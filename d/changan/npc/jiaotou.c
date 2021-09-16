// jiaotou.c

inherit NPC;
 
void create()
{
	set_name("武馆教头", ({"wuguan jiaotou", "jiaotou"}));
	set("long", "这位是武馆的教头正在督促弟子们练功。\n");
	set("gender","男性");

	set("age",38);
	set("con",30);
	set("str",20);
	set("max_kee",1000);
	set("max_gin",700);
	set("max_sen",700);
	set("max_force",500);
	set("force",500);
	set("force_factor",10);

	set_skill("dodge",100);
	set_skill("parry",100);
	set_skill("unarmed",90);

	set("combat_exp",70000);

	setup();
	carry_object(ARMOR_DIR"cloth")->wear();
}