//d_boss.c 林芝村当铺老板。
inherit NPC;
void create()
{
        set_name("贡布", ({ "gong bu","boss" }) );
        set("gender", "男性" );
        set("title","当铺老板");
        set("age", 29);
        set("long","一位看上去非常聪明的青年。\n");
        set("combat_exp", 20000);
        set("attitude", "friendly");
        setup();
        carry_object(ARMOR_DIR"cloth")->wear();
}
