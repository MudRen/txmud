// xiaotong.c

inherit NPC;
void create()
{
        set_name("小童", ({ "xiao tong"}) );
        set("gender", "男性" );
        set("age", 9);
        set("long","一个眉清目绣的小孩。\n");
        set("combat_exp", 100);
        set("attitude", "friendly");
        setup();
        carry_object(ARMOR_DIR"cloth")->wear();
}

