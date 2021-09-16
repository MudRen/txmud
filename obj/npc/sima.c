// by uudd.
// sima.c
// ��Ҹ������.
#include <ansi.h>

#define BASE_CHANGE_COST 100   //�����ĸ������ã���λ gold.

inherit NPC;

private string change_name();
private int comput_cost(object me);
private void dest_objects();

void create()
{
	// ***** This object's name must be "banned". *****
	// I think the environment of this object may be set "no_fight".
	set_name("˾����", ({ "sima liang", "sima", "liang" }));
	set("title", "�����ù�");

	set("str", 20);
	set("gender", "����");
	set("age", 35);
	set("long",
"˾�����ǵ��������ù٣������������أ����
��͢���Σ�����������ר˾������С�������
�յ�һЩС����Ҳ�����ƹܡ�\n");

	set("combat_exp", 150);
	set("attitude", "friendly");
	set("inquiry", ([
	"����" : (: change_name :),
	"����" : (: change_name :),
]));

	setup();
	carry_object(ARMOR_DIR"cloth")->wear();
}

void init()
{
	object ob;

	::init();
	if (interactive(ob = this_player()) && !is_fighting())
	{
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
	add_action("do_name","change");
}
 
void greeting(object ob)
{
	if(!ob || environment(ob) != environment())
		return;

	if(!is_day())
		return;

	switch(random(2))
	{
		case 0 :
			command("say ��λ"+RANK_D->query_respect(ob)+"���������к����飿\n");
			break;
		case 1 :
			command("say ����ֻ����������ˣ������������ذɡ�\n");
			break;
	}
}

private string change_name()
{
	object me = this_player();

	if(!is_day())
		return "�����Ѿ�Ъ���ˣ�����˵㵽��ŵ�ǰ������\n";
	return me->name() + "Ҫ�������Ƚ�" +
		chinese_number(comput_cost(me)) + "���ƽ�ĸ��������ѡ�\n";
}

private int comput_cost(object me)
{
	int times;

	if(times = me->query("changed_name"))
		// ÿ����һ�Σ��´�Ҫ���� 50 gold.
		return BASE_CHANGE_COST + times * 50;
	else return BASE_CHANGE_COST;
}

int accept_object(object who, object ob)
{
	if(!is_day())
	{
		command("say �����Ѿ�Ъ���ˣ�����˵㵽��ŵ�ǰ������\n");
		return 0;
	}

	if(!ob->query("money_id"))
	{
		command("say �������������õģ�Ҫ�������ֽ�\n");
		return 0;
	}

 	if( ob->value() >= comput_cost(who)*10000 )
	{
		command("say "+who->name()+"����������������µ��������ֺ�change �µ���������\n");
		who->set_temp("paid_changename_cost",1);
		call_out("dest_objects",1);
		return 1;
	}

	else
	{
		command("say "+who->name() + "Ҫ������Ҫ��" +
		chinese_number(comput_cost(who)) + "���ƽ�ĸ��������ѡ�\n");
		return 0;
	}
}

int do_name(string target)
{
	object me = this_player();

	if(!is_day())
	{
		command("say �����Ѿ�Ъ���ˣ�����˵㵽��ŵ�ǰ������\n");
		return 1;
	}

	if( !me->query_temp("paid_changename_cost") ) 
		return notify_fail(me->name() + "Ҫ������Ҫ��" +
			chinese_number(comput_cost(me)) + "���ƽ�ĸ��������ѡ�\n");

	if( !target || target==" ") 
		return notify_fail("change �µ���������\n");

	if( target == me->name() )
		return notify_fail("��ô������ԭ�������֣�ҪϷŪ������\n");

	message_vision("$N����һ��������ϸ�Ĳ���������\n",this_object());
	call_out("do_change",1,me,target);
	return 1;
}

private void do_change(object me,string target)
{
	object link_ob,mailbox,ob = find_object(LOGIN_D);

	if(!ob)
	{
		say("Bug! Can not find LOGIN_D!! Please report to wizards!!\n");
		return;
	}

	if(!ob->check_legal_name(target))
	{
		say("����һ���ɡ�\n");
		return;
	}

	change_cname(me->query("id"),target);

	link_ob = me->query_temp("link_ob");
	PLAYERHOME_D->home_master_change_cname(me,me->name(),target);

        NEWS_D->add_news_item( sprintf(HIY"%s(%s) �ڻ���ע����ʽ����Ϊ \"%s\"��\n"NOR,
                me->name(),capitalize(me->query("id")),target ),"p", 1);

	command("chat " +"\""+ me->name() + "\""+"�ڻ���ע�����Ϊ��" +
		"\""+target + "\""+"������Ժ�Ҫ�ϴ������ˣ�\n");
	me->delete_temp("paid_changename_cost");
	me->add("changed_name",1);
	me->set("name", target);
	link_ob->set("name", target);

	mailbox = present("mailbox",me);
	if(mailbox)
		mailbox->set_name( me->name(1) + "������",({ "mailbox", "box" }) );

	me->save();
	link_ob->save();
	return;
}

private void dest_objects()
{
	int i;
	object *inv;

	inv = all_inventory(this_object());
	for(i=0;i<sizeof(inv);i++)
	{
		if(inv[i]->query("id") == "cloth")
			continue;
		destruct(inv[i]);
	}
}
