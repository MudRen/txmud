// smith.c

inherit SMITH;

void create()
{
	set_name("张铁匠", ({ "smith zhang","zhang","smith" }) );
        set("gender", "男性" );
        set("age", 38);
	set("str",88);
        set("long", "他就是雪亭镇铁器作坊老板张铁匠。\n");
        set("combat_exp", 300);
        set("attitude", "friendly");
        set_skill("dodge", 60);
        set_skill("unarmed", 60);

	set_weapon_ability(({"dhammer", "hammer", "sword"}));
	set_ability_level(10);

        setup();

	carry_object(ARMOR_DIR+"cloth")->wear();
}
