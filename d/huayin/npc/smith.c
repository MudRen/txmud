// smith.c

inherit SMITH;

void create()
{
	set_name("史老汉", ({ "shi lao han"}) );
        set("gender", "男性" );
        set("age", 58);
	set("str",88);
        set("long", "他就是华阴村的史铁匠。\n");
        set("combat_exp", 100);
        set("attitude", "friendly");
        set_skill("dodge", 60);
        set_skill("unarmed", 10);
        setup();

	carry_object(ARMOR_DIR+"cloth")->wear();
}