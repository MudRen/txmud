inherit NPC;

void create()
{
        set_name("老者", ({ "lao zhe" }) );
        set("gender", "男性" );
        set("age", 68);
        set("long", "这位老人正全神贯注的盯着鱼池。\n");

        set("combat_exp", 200);

        setup();
        carry_object(ARMOR_DIR"cloth")->wear();
}
