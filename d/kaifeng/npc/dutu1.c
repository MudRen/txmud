inherit NPC;

void create()
{
        set_name("赌徒", ({ "du tu" }) );
        set("gender", "男性");
        set("age", 37);
        set("long", "这是一个以赌为生的人。\n");

        set("combat_exp", 1000);

        setup();
        carry_object(ARMOR_DIR"cloth")->wear();
}
