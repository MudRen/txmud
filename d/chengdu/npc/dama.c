inherit NPC;

void create()
{
        set_name("老大妈", ({ "old woman" }) );
        set("gender", "女性" );
        set("age", 62);
        set("long",
                "一个年迈的老大妈。\n");
        set("combat_exp", 500);

        set("attitude", "friendly");
        setup();
        carry_object(ARMOR_DIR"cloth")->wear();
}
