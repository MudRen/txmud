inherit NPC;

void create()
{
        set_name("老大娘", ({ "lao daniang" }) );
        set("gender", "女性" );
        set("age", 63);
        set("long", "一个就快要进棺材的人。\n");

        set("combat_exp", 1);

        setup();
        carry_object(ARMOR_DIR"cloth")->wear();
}

