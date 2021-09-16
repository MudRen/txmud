// smith.c

inherit SMITH;

void create()
{
	set_name("ÖÜÌú½³", ({ "smith zhou","zhou","smith" }) );
        set("gender", "ÄĞĞÔ" );
        set("age", 38);
	set("str",88);
        set("long", "Ìú½³ÆÌÀÏ°åÕÅÌú½³¡£\n");
        set("combat_exp", 300);
        set("attitude", "friendly");
        set_skill("dodge", 60);
        set_skill("unarmed", 60);
        setup();

	carry_object(ARMOR_DIR+"cloth")->wear();
}
