inherit NPC;

void create()
{
        set_name("金财迷", ({ "jin caimi" , "jin" , "caimi" }) );
        set("title","钱庄老板");
        set("gender", "男性" );
        set("age", 36);
        set("long", "金财迷浑身都是铜臭味，还是离他远点好。\n");

        set("combat_exp", 100);

        setup();
        carry_object(ARMOR_DIR"cloth")->wear();
}
