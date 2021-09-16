// jjseng.c

inherit NPC;

void create()
{
	set_name("知客僧", ({ "zhike seng", "seng" }) );
	set("class","shaolin");
	set("gender", "男性" );
	set("age", 33);
	set("long", "这是一位满脸和善的僧人，但从眼中的
精光和高高隆起的太阳穴上可见也是一
位武功好手。\n");
	set("attitude", "peaceful");

	set("combat_exp", 1500000);
	set("str", 27);
	set("max_kee",1500);
	set("kee",1500);
	set("max_gin",1500);
	set("gin",1500);
	set("max_sen",1500);
	set("sen",1500);
	set("force", 2000);
	set("max_force", 2000);
	set("atman", 2000);
	set("max_atman", 2000);
	set("mana", 2000);
	set("max_mana", 2000);
	set("force_factor", 20);

	set_skill("stick",100);
	set_skill("weituo-gun",100);
	set_skill("dodge",100);
	set_skill("parry",100);
	set_skill("force",100);
	set_skill("yiqi-force",100);
	set_skill("ganchan",100);

	map_skill("stick","weituo-gun");
	map_skill("force","yiqi-force");
	map_skill("parry","weituo-gun");
	map_skill("dodge","ganchan");

	setup();

	carry_object(__DIR__"obj/tong_stick")->wield();
	carry_object(__DIR__"obj/seng_pao")->wear();
}
