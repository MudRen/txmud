inherit NPC;

void create()
{
        set_name("中年妇人", ({ "zhongnian furen" , "furen"}) );
        set("gender", "女性" );
        set("age", 45);
        set("long", "她就是张妞妞的母亲。\n");

        set("combat_exp", 1);

        setup();
        carry_object(ARMOR_DIR"cloth")->wear();
}
