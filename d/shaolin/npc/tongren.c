// tongren.c
// by Find.

#include <ansi.h>
#include <combat.h>

inherit NPC;

private void short_attack();
protected object chk_user;

void create()
{
	set_name("ͭ��", ({ "tong ren" }) );

	set("race", "Ұ��");

	set("long", "����һ��������ϸ��ͭ�ˣ����ӿ�
������һ�����ֺ��е�ģ����\n");

	set("combat_exp", 3000000);
	set("str", 67);
	set("kar", 67);

	set("max_kee",10000);
	set("kee",10000);
	set("max_gin",10000);
	set("gin",10000);
	set("max_sen",10000);
	set("sen",10000);

	set("atman", 10000);
	set("max_atman", 10000);
	set("mana", 10000);
	set("max_mana", 10000);
	set("limbs", ({
		"ͷ��",	"����",	"�ؿ�",	"����",	"���",	"�Ҽ�",	"���",
		"�ұ�",	"����",	"����",	"����",	"С��",	"����",	"����",
		"���",	"�ҽ�"
	}) );

	set_temp("apply/armor",100);
	set("chat_chance_combat",30);
	set("chat_msg_combat",({
	(: short_attack :),
 }));

	setup();
	carry_object(__DIR__"obj/tong_stick")->wield();
}

private void copy_skill(int ski,int f)
{
	set_skill("unarmed",ski);
	set_skill("dodge",ski);
	set_skill("parry",ski);
	set_skill("force",ski);
	set_skill("stick",ski);
	set_skill("iron-cloth",ski);
	set_skill("perception",ski);

	set_skill("yiqi-force",ski/2);
	set_skill("ganchan",ski/2);
	set_skill("weituo-gun",ski/2);
	set_skill("luohan-quan",ski/2);

	map_skill("force","yiqi-force");
	map_skill("dodge","ganchan");
	map_skill("stick","weituo-gun");
	map_skill("unarmed","luohan-quan");
	map_skill("parry","weituo-gun");

	set("force_factor",f);
	reset_action();
}

private void short_attack()
{
	string *cdir = ({"��","��","��","��"}),dir;
	object *enemy,ob;

	if( !environment()
	|| !(enemy = filter_array(query_enemy() - ({0}),(: userp :)) )
	|| !sizeof(enemy) )
		return;

	ob = present("hide tong ren",environment());
	if(!ob)
	{
		ob = new(__DIR__"hide_tongren");
		if(!ob)
			return;
		ob->init_skill(environment()->query_stage());
	}

	tell_object(enemy[0],sprintf(HIB"\n\n��Ȼ%s���ʯ���ﵯ��һ��ͭ��,�䲻�����㹥�˹���������\n\n"NOR,
		(dir = cdir[random(4)])));

	enemy[0]->kill_ob(ob);
	ob->kill_ob(enemy[0]);

	for(int i=0;i<3;i++)
		COMBAT_D->do_attack(ob,enemy[0],TYPE_QUICK);

	enemy[0]->remove_killer(ob);
	ob->remove_killer(enemy[0]);
	tell_object(enemy[0],sprintf(HIB"\n\n%s���ͭ��ٿ��һ���ֵ��˻�ȥ������\n\n"NOR,
		dir));
}

void init_skill(int sta)
{
	int skill,force;

	switch (sta)
	{
		case 2:
			set("force", 1500);
			set("max_force", 1500);
			skill = 200; force = 40;
			break;
		case 3:
			set("force", 1000);
			set("max_force", 1000);
			skill = 250; force = 80;
			break;
		default:
			set("force", 500);
			set("max_force", 500);
			skill = 120; force = 10;
			break;

	}

	copy_skill(skill,force);
}

private void do_success()
{
	if(!chk_user
	|| !environment()
	|| environment(chk_user) != environment()
	|| chk_user->query("kee") <= 0)
	{
		call_out("do_success",5);
		return;
	}
	environment()->do_pass(chk_user);
}

void do_begin(object user)
{
	if(!user || environment(user) != environment())
		return;

	chk_user = user;
	call_out("do_success",120);
}

void unconcious()
{
	environment()->do_pass(chk_user);
	::unconcious();
}

void die()
{
	environment()->do_pass(chk_user);
	::die();
}

