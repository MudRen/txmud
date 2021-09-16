// design by ���ֺ�(find) . all right reserved.

// hong_xiu.c

#include <ansi.h>

inherit NPC;
void back_out(object who);
void create()
{
	set_name("����", ({ "hong xiu" }) );
	// ���ɸ� ji1
	set("gender", "Ů��" );
	set("age", 19);
	set("str", 25);
	set("per", 30);
	set("long", @LONG
�����ٸ��죬һ˫�����۾�ֱ�����������㡣
LONG
);
	set("class","jiyuan");
	set("combat_exp", 100);
	set("attitude", "friendly");

	set_skill("unarmed",100);
	set_skill("parry",100);
	set_skill("dodge",100);

	setup();
	carry_object(__DIR__"obj/ruby_ring");
	carry_object(__DIR__"obj/wucai_skirt")->wear();
}

void init()
{	
	object *inv;
	int i;

	::init();
	inv = all_inventory(environment());
	for(i=0;i<sizeof(inv);i++)
		{
		if(!inv[i]->query_temp("jiyuan/order")) continue;
		remove_call_out("greeting");
		call_out("greeting", 1, inv[i]);
		}
	add_action("do_sleep","come");
}

void greeting(object ob)
{
	if( !ob || environment(ob) != environment() || !ob->query_temp("jiyuan/order")) return;
	message_vision("\n$N��$nӯӯһ����ū�����ź����ˡ�ū�к���(hong xiu)��\n",this_object(),ob);
	message_vision("үԸ��Ը��ȥū�ġ����ɸ󡹣����Һú��ź��ź�ү��(accept hong xiu)\n",this_object());
}

int accept_object(object who,object ob)
{
	object obj;
	if(!who->query_temp("jiyuan/shangqian") || who->query_temp("jiyuan/shangqian") != "����") return 0;
	if(!ob->query("money_id")) return 0;
	if(ob->value() < 10000)
		{
		message_vision("$N˵����ү�ٶ��ͼ����ɡ�\n",this_object());
		return 1;
		}
	if(obj = present("lian yu",environment())) {
		tell_object(environment(),obj->name()+"���ˡ�\n");
		destruct(obj);
	}
	if(obj = present("wan xiang",environment())) {
		tell_object(environment(),obj->name()+"���ˡ�\n");
		destruct(obj);
	}
	if(obj = present("xiang yu",environment())) {
		tell_object(environment(),obj->name()+"���ˡ�\n");
		destruct(obj);
	}
	message_vision("$N���˵�˵������л$n��ү���͡�ү�������ɡ�",this_object(),who);
	who->set_leader(this_object());
	who->delete_temp("jiyuan");
	who->set_temp("jiyuan/sleep",this_object()->name());
	command("go north");
	call_out("can_sleeping",2,who);
	return 1;
}

void can_sleeping(object who)
{
	object mother;
	if( !who || environment(who) != environment() )
	{
	message_vision("$N̾�˿��������ˡ�\n",this_object());
	if(mother = present("m_boss",find_object("/d/changan/jiyuan")))
		mother->delete_temp("have_full");
	if(who) who->delete_temp("jiyuan");
	destruct(this_object());
	return;
	}
	message_vision("$N�����ߺ��������һ����\n",this_object());
	command("remove skirt");
	message_vision(CYN"$N������$n˵��ү����(come)�ɣ�ū�Ҷ�...�Ȳ����ˡ�\n"NOR,this_object(),who);
	call_out("waiting_you",3,who,0);
	return;
}


void waiting_you(object who,int n)
{
	remove_call_out("waiting_you");
	if( !who || environment(who) != environment() )
	{
		back_out(who);
		return;
	}

	switch (n)
	{
		case 0:
			message_vision(CYN"$N��ɬ�Ŀ���$n˵�����ѵ�ū�ҵ�����Ҳ�������⡣����\n"NOR,this_object(),who);
			break;
		case 1:
			message_vision(CYN"$N����С������$n˵����Ҳ��ô����ū�Ĺ⾰�����滵������\n"NOR,this_object(),who);
			break;
		case 2:
			message_vision(CYN"$N����С���˵����ү����ū���ֲ�������ū���ǡ�����\n"NOR,this_object(),who);
			break;
	}

	if(n >= 2)
		back_out(who);
	else
	{
		n += 1;
		call_out("waiting_you",3,who,n);
	}
}

void back_out(object who)
{
	object mother;
	command("wear skirt");
	message_vision("$N̾�˿��������ˡ�\n",this_object());
	if(mother = present("m_boss",find_object("/d/changan/jiyuan")))
		mother->delete_temp("have_full");
	if(who) who->delete_temp("jiyuan");
	destruct(this_object());
	return;
}

int do_sleep(string arg)
{
	object *inv,me = this_player();
	int i;
	if(!me->query_temp("jiyuan/sleep") || me->query_temp("jiyuan/sleep") != "����")
		return 0;
	if(find_call_out("waiting_you"))
		remove_call_out("waiting_you");
	message_vision("$N����ͨ�죬�ͺ�һ������$n������......\n",me,this_object());
	message_vision("$NͻȻ����һ����ѣ......\n",me);
	me->delete_temp("jiyuan");
	me->unconcious();
	command("get all");
	inv = all_inventory(me);
	for(i=0;i<sizeof(inv);i++)
		{
		destruct(inv[i]);
		}
	call_out("go_out",1);
	return 1;
}

void go_out()
{
	object mother;
	command("wear skirt");
	message_vision("$Nһ����Ц�����˳�ȥ��\n",this_object());
	if(mother = present("m_boss",find_object("/d/changan/jiyuan")))
		mother->delete_temp("have_full");
	destruct(this_object());
	return;
}