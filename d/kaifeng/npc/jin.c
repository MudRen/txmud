inherit NPC;

void create()
{
        set_name("�����", ({ "jin caimi" , "jin" , "caimi" }) );
        set("title","Ǯׯ�ϰ�");
        set("gender", "����" );
        set("age", 36);
        set("long", "����Ի�����ͭ��ζ����������Զ��á�\n");

        set("combat_exp", 100);

        setup();
        carry_object(ARMOR_DIR"cloth")->wear();
}
