inherit NPC;

void create()
{
        set_name("�ϴ���", ({ "old woman" }) );
        set("gender", "Ů��" );
        set("age", 62);
        set("long",
                "һ���������ϴ��衣\n");
        set("combat_exp", 500);

        set("attitude", "friendly");
        setup();
        carry_object(ARMOR_DIR"cloth")->wear();
}
