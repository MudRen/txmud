// smith.c

inherit SMITH;

void create()
{
	set_name("刘二嘎", ({ "liu er ga" }) );
	set("title","打铁大汉");

	set("gender", "男性" );
	set("age", 38);
	set("str",88);
        set("long", "一个健壮的中年人。\n");
        set("combat_exp", 300);
        set("attitude", "friendly");
        set_skill("dodge", 60);
        set_skill("unarmed", 60);
        setup();

	carry_object(ARMOR_DIR+"cloth")->wear();
}
