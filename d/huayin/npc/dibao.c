// smith.c

inherit NPC;

void create()
{
	set_name("莫提谦", ({ "mo ti qian"}) );
	set("title","华阴村地保");
        set("gender", "男性" );
        set("age", 58);
	set("str",60);
        set("long", "他就是华阴村的地保，据说还
是大同府知府的亲戚。\n");

        set("combat_exp", 100);
        set("attitude", "friendly");
        setup();

	carry_object(ARMOR_DIR+"cloth")->wear();
}