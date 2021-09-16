// yao_npc.c

inherit NPC;

#include <ansi.h>
int ask_xuelian(object me);
int is_quest_object() { return 1;}

int have = 1,time;

void create()
{
	set_name("����", ({ "wu ming" }) );
        set("gender", "����" );
        set("age", 47);
        set("long", "����һλ��ɫ�Ҵҵ������ˡ�\n");
        set(NO_KILL, 1);

	set("chat_chance", 15);
	set("chat_msg", ({
		(: random_move :),
	}) );

	set("inquiry",([
	"��ɽѩ��" : (: ask_xuelian :),
	"ѩ��" : (: ask_xuelian :),
]));

        setup();
        carry_object(ARMOR_DIR"cloth")->wear();
}

int ask_xuelian(object me)
{
	if(!have)
	{
		write(sprintf(CYN"%s˵�����Ѿ��ñ��������ˡ�\n"NOR,name()));
		return 1;
	}

	if(me->query("quest/shaolin_quest/asked_xuelian") != query("id"))
	{
		write(sprintf(CYN"%s˵�����Һò����ײ��򵽵ģ���ô�ܸ��㣡��\n"NOR,name()));
		return 1;
	}

	write(sprintf(CYN"%s˵�������Ǻò����ײ�Ū���ģ�������5�������أ�
��Ȼ�㼱�þ� 5 ������ת�ø���ɣ�
�����������ֺ�����ȥ��ѽ��\n"NOR,name()));
	me->set_temp("xuelian_60",1);
	return 1;
}

int accept_object(object me, object ob)
{
	object lian;

	if(!is_money(ob))
		return 0;

	if(!me->query_temp("xuelian_60"))
	{
		command("say ���������׸�Ǯ�����鶼�У�лл����");
		return 1;
	}

	if(ob->value() < 500)
	{
		command("say 5�������Ѿ��ǲ�׬Ǯ�����ˣ��㻹Ҫ��ô�ţ�");
		return 0;
	}

	lian = new(__DIR__"obj/xuelian");
	lian->move(this_object());

	command("say �ðɣ����������ˣ���Ҳ������������������ˡ�");
	command(sprintf("give tianshan xuelian to %s",me->query("id")));

	me->delete_temp("xuelian_60");
	me->delete_temp("asked_xuelian");
	me->set("quest/shaolin_quest/have",1);
	have = 0;
        call_out("go_away",3);

	return 1;
}

int heal_up()
{
	int t;

	if(!have && living(this_object()))
	{
		call_out("go_away",1);
		return 1;
	}

	t = time();

	if(!time)
		time = t;

	else if(t - time > 1200)
	{
		call_out("go_away",1);
		return 1;
	}

	return ::heal_up() + 1;
}

void go_away()
{
	if(!living(this_object()))
		return;

	if(environment())
		tell_object(environment(),name()+"�Ҵ�ææ�����ˡ�\n");
	destruct(this_object());
}
