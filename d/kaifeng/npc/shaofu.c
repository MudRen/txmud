inherit NPC;

void create()
{
        set_name("少妇", ({ "shao fu"}) );
        set("gender", "女性" );
        set("age", 42);
        set("long", "少妇是这里的佣人。\n");

        set("combat_exp", 1);

        setup();
        carry_object(ARMOR_DIR"cloth")->wear();
}
