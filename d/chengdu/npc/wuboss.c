// wuboss.c

inherit NPC;

void create()
{
        set_name("吴老头", ({ "wu boss"}) );
        set("title","棺材铺老板");
        set("gender", "男性" );
        set("age", 68);
        set("long","吴老头一脸死气沉沉的样子，
好象谁都欠他钱一样。\n");
        set("attitude", "friendly");
        setup();
        carry_object(ARMOR_DIR"cloth")->wear();
}

