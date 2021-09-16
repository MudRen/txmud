// tongren.c
// by Find.

#include <ansi.h>
#include <combat.h>

inherit NPC;

private void short_attack();
protected object chk_user;

void create()
{
	set_name("铜人", ({ "tong ren" }) );

	set("race", "野兽");

	set("long", "这是一个制作精细的铜人，样子看
起来是一个少林和尚的模样。\n");

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
		"头部",	"颈部",	"胸口",	"後心",	"左肩",	"右肩",	"左臂",
		"右臂",	"左手",	"右手",	"腰间",	"小腹",	"左腿",	"右腿",
		"左脚",	"右脚"
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
	string *cdir = ({"东","南","西","北"}),dir;
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

	tell_object(enemy[0],sprintf(HIB"\n\n忽然%s面的石壁里弹出一个铜人,冷不防向你攻了过来。。。\n\n"NOR,
		(dir = cdir[random(4)])));

	enemy[0]->kill_ob(ob);
	ob->kill_ob(enemy[0]);

	for(int i=0;i<3;i++)
		COMBAT_D->do_attack(ob,enemy[0],TYPE_QUICK);

	enemy[0]->remove_killer(ob);
	ob->remove_killer(enemy[0]);
	tell_object(enemy[0],sprintf(HIB"\n\n%s面的铜人倏的一下又弹了回去。。。\n\n"NOR,
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

