inherit NPC;

void create()
{
        set_name("路人", ({ "lu ren" }) );
        set("gender", "男性" );
        set("age", 36);
        set("long",
                "他是一位经过成都的路人。\n");
        set("combat_exp", 1000);

	set_skill("unarmed",20);
        set("attitude", "friendly");
        setup();
        carry_object(ARMOR_DIR"cloth")->wear();
}

