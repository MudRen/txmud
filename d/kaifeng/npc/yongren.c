inherit NPC;

void create()
{
        set_name("佣人", ({ "yong ren" , "ren"}) );
        set("gender", "女性" );
        set("age", 38);
        set("long", "一位正在扫地的中年妇女.\n");

        set("combat_exp", 100);

        setup();
        carry_object(ARMOR_DIR"cloth")->wear();        
}
