inherit NPC;

void create()
{
        set_name("����", ({ "old man" }) );
        set("gender", "����" );
        set("age", 65);
        set("long",
                "һ�����������ˡ�\n");
        set("combat_exp", 500);

        set("attitude", "friendly");
        setup();
        carry_object(ARMOR_DIR"cloth")->wear();
}
