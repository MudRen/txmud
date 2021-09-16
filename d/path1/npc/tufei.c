// tufei.c

inherit NPC;

void create()
{
	set_name("土匪", ({ "tu fei" }) );
	set("gender", "男性" );
	set("age", 35);
	set("str",35);
	set("attitude","killer");

	set("max_kee",1000);
	set("max_gin",1000);
	set("max_sen",1000);

	set("combat_exp", 40000);

	set("long", "看样子这是一位拦路抢劫的土匪，只见虎
背熊腰，一脸凶狠而霸道的样子。\n");

	set_skill("blade",50);
	set_skill("parry",70);
	set_skill("dodge",70);
	set_skill("unarmed",70);

	setup();

	carry_object(__DIR__"obj/hujia")->wear();
	carry_object(WEAPON_DIR"blade")->wield();
}
