// snake.c

#include <ansi.h>

inherit NPC;

private int been = 0;

void attack_killer();

void create()
{
	set_name("�߲���", ({ "qibu she", "she" }) );
	set("race", "Ұ��");
	set("age",1);
	set("max_kee",1500);

	set("attitude", "killer");

	set("long", "һ���׺ݵ��߲������ڳ������š�\n");

	set("limbs", ({ "ͷ��", "����", "β��" }) );
	set("verbs", ({ "bite" }) );

	set("chat_chance_combat",30);
	set("chat_msg_combat",({
	(: attack_killer :),
 }));

	set("combat_exp", 60000+random(10000));
	set_temp("apply/attack",45);
	set_temp("apply/defense",30);
	setup();
}

void attack_killer()
{
	object *ens,*ex = ({});
	int i;

	if(been)
		return;

	ens = query_enemy();

	if(!ens || !sizeof(ens))
		return;

	for(i=0;i<sizeof(ens);i++)
		if(objectp(present("bidu zhu",ens[i])))
			ex += ({ ens[i] });

	if(sizeof(ex))
		ens -= ex;

	if(!sizeof(ens))
		return;

	message_vision(GRN"\n$Nһ��ͷ���ۡ���һ�������һ�ں���ɫ�Ķ�Һ��\n\n"NOR,this_object());

	tell_room(environment(),HIB"��ֻ����һ�ɶ���������ڱǲ�����������ж��ˣ�\n\n"NOR,
		sizeof(ex)?ex:({this_object()}));

	ens->apply_condition("snake_poison", random(15)+15);
}

int accept_shecha(object ob)
{
	if(!ob->id("she cha"))
		return 0;

	if(been)
		return -1;

	if(random(10) < 3)
		return 0;

	set_temp("she_cha",ob);
	ob->set_temp("snake",this_object());
	been = 1;
	return 1;
}

int heal_up()
{
	object ob;

	if(been)
	{
		if(!ob = query_temp("she_cha"))
			been = 0;
		if(environment(ob) != environment())
		{
			delete_temp("she_cha");
			been = 0;
		}
	}

	return ::heal_up() + 1;
}

void die()
{
	object ob, env;

	if(!objectp(env = environment(this_object())))
	{
		destruct(this_object());
		return;
	}

	message_vision("$N���ˡ�\n", this_object());
        ob = new(__DIR__"shedan");
	ob->move(env);
	if(function_exists("check_set_up",env))
		env->check_set_up();

	destruct(this_object());
}
