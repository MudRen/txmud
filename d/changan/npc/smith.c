// smith.c

inherit SMITH;

void create()
{
	set_name("ÕÅÌú½³", ({ "smith zhang","zhang","smith" }) );
        set("gender", "ÄĞĞÔ" );
        set("age", 38);
	set("str",88);
        set("long", "ÌúÆ÷×÷·»ÀÏ°åÕÅÌú½³¡£\n");
        set("combat_exp", 300);
        set("attitude", "friendly");
        set_skill("dodge", 60);
        set_skill("unarmed", 60);

	set_weapon_ability(({"staff","dhammer", "hammer", "sword"}));
	set_ability_level(10);

        setup();

	carry_object(ARMOR_DIR+"cloth")->wear();
}
