inherit NPC;

void create()
{
        set_name("����", ({ "lao zhe" }) );
        set("gender", "����" );
        set("age", 68);
        set("long", "��λ������ȫ���ע�Ķ�����ء�\n");

        set("combat_exp", 200);

        setup();
        carry_object(ARMOR_DIR"cloth")->wear();
}
