inherit NPC;

void create()
{
        set_name("弈者", ({ "yi zhe" }) );
        set("gender", "男性" );
        set("age", 67);
        set("long", "一位白发童颜的老人.\n");

        set("combat_exp", 200);

        setup();
        carry_object(ARMOR_DIR"cloth")->wear();        
}
