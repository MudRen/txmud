inherit NPC;

void create()
{
        set_name("�ϴ���", ({ "lao daniang" }) );
        set("gender", "Ů��" );
        set("age", 63);
        set("long", "һ���Ϳ�Ҫ���ײĵ��ˡ�\n");

        set("combat_exp", 1);

        setup();
        carry_object(ARMOR_DIR"cloth")->wear();
}

