inherit NPC;

void create()
{
        set_name("工人", ({ "gong ren" , "ren"}) );
        set("gender", "男性" );
        set("age", 37);
        set("long", "一位正在干活的中年男子.\n");

        set("combat_exp", 800);

        setup();
        carry_object(ARMOR_DIR"cloth")->wear();        
}
