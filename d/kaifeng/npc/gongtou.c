inherit NPC;

void create()
{
        set_name("工头", ({ "gong tou" , "tou"}) );
        set("gender", "男性" );
        set("age", 39);
        set("long", "工头正在大声嚷嚷着让工人们干活.\n");

        set("combat_exp", 1200);

        setup();
        carry_object(ARMOR_DIR"cloth")->wear();        
}
