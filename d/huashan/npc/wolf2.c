// wolf2.c

#include <ansi.h>

inherit NPC;

void create()
{
        set_name( "����", ({"white wolf" }) );
        set("long", WHT"����һֻ����ѩ�׵���,�����һ���
�Ǵ�һ�����࣬����������ͷ���ˡ�\n"NOR);
        set("race", "Ұ��");
        set("family","����");
        set("limbs", ({ "ͷ��", "����", "β��" }) );
        set("verbs", ({ "bite" }) );

	set("max_gin", 4000);
        set("max_kee", 4000);
        set("max_sen", 4000);

	set("age", 20);

	set("str", 35);
	set("cor", 70);

	set("combat_exp", 1000000);
	set("chat_chance", 2);

	set("chat_chance_combat", 5);
	set("chat_msg_combat", ({
		HIY"���Ǻ����﷢���͵͵�������\n"NOR,
		HIY"����Ѫ����۾������㡣\n"NOR,
        }) );

	set_temp("apply/dodge", 150);
	set_temp("apply/unarmed",150);
	set_temp("apply/parry",150);
	set_temp("apply/damage",100);
	set_temp("apply/armor",150);

        setup();
}

void check_env(object ob)
{
	object *inv,env;

	if(!ob || !userp(ob) || (environment(ob) != environment()))
		return;

	inv = filter_array(all_inventory(env = environment()),(: $1->is_hs_wolf() :));

	if(sizeof(inv) >= 10)
	{ inv->kill_ob(ob); return; }

	for(int i=0;i<2;i++)
	{
		object wl = new(__DIR__"wolf1");
		wl->move(env);
		message_vision("ͻȻ����ߴڽ�һֻ$N��",wl);
		wl->kill_ob(ob);
	}
}

void init()
{
	object ob = this_player();

	if(!ob)
		return;

	if( ob->query("bellicosity") > 200)
	{
		message_vision(HIR"$N�͵��������˹�����\n"NOR, this_object() );
		kill_ob(ob);
		check_env(ob);
        }
	add_action("do_killing", "kill");
}

int do_killing(string arg)
{
        object me = this_player();

	if(!arg || !id(arg))
		return 0;

	check_env(me);
        return 0;
}
