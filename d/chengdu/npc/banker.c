// banker.c

inherit NPC;

void create()
{
        set_name("龚雷", ({ "gong lei" }) );
        set("title", "钱庄老板");
        set("gender", "男性" );
        set("age", 56);

        set("str", 52);

        set("long","这是一位和善的老人。\n");

        set("combat_exp", 80);
        set("attitude", "friendly");
        setup();
        
        carry_object(ARMOR_DIR"cloth")->wear();
}
