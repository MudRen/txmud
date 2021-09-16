// hide_tongren.c
// by Find.

inherit NPC;

void create()
{
	set_name("ͭ��", ({ "hide tong ren" }) );

	set("race", "Ұ��");

	set("long", "����һ��������ϸ��ͭ�ˣ����ӿ�
������һ�����ֺ��е�ģ����\n");

	set("combat_exp", 3000000);
	set("str", 67);
	set("no_show",1);

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

void init_skill(int sta)
{
	int skill,force;

	switch (sta)
	{
		case 2:
			set("force", 2500);
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
