inherit NPC;

void create()
{
        set_name("戏迷", ({ "ximi" }) );
        set("gender", "男性" );
        set("age", 48);
        set("long", "一个正自我陶醉的戏迷\n");

        set("combat_exp", 600);

        setup();
        carry_object(ARMOR_DIR"cloth")->wear();        
}
