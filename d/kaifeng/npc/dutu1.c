inherit NPC;

void create()
{
        set_name("��ͽ", ({ "du tu" }) );
        set("gender", "����");
        set("age", 37);
        set("long", "����һ���Զ�Ϊ�����ˡ�\n");

        set("combat_exp", 1000);

        setup();
        carry_object(ARMOR_DIR"cloth")->wear();
}
