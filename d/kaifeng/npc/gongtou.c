inherit NPC;

void create()
{
        set_name("��ͷ", ({ "gong tou" , "tou"}) );
        set("gender", "����" );
        set("age", 39);
        set("long", "��ͷ���ڴ����������ù����Ǹɻ�.\n");

        set("combat_exp", 1200);

        setup();
        carry_object(ARMOR_DIR"cloth")->wear();        
}
