inherit NPC;

void create()
{
        set_name("老人", ({ "old man" }) );
        set("gender", "男性" );
        set("age", 65);
        set("long",
                "一个年迈的老人。\n");
        set("combat_exp", 500);

        set("attitude", "friendly");
        setup();
        carry_object(ARMOR_DIR"cloth")->wear();
}
