inherit NPC;

void create()
{
        set_name("����", ({ "xian ren" }) );
        set("gender", "����" );
        set("age", 32);

        set("combat_exp", 2000);

        setup();
        carry_object(ARMOR_DIR"cloth")->wear();
}
