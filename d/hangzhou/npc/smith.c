// smith.c

inherit SMITH;

void create()
{
	set_name("»ÆÌú½³", ({ "smith huang" }) );
        set("gender", "ÄĞĞÔ" );
        set("age", 48);
	set("str",80);
        set("long", "Ëû¾ÍÊÇº¼ÖİÌú½³ÆÌµÄ»ÆÌú½³¡£\n");
        set("combat_exp", 2000);
        set("attitude", "friendly");
        set_skill("dodge", 60);
        set_skill("unarmed", 60);
        setup();

	carry_object(ARMOR_DIR+"cloth")->wear();
}