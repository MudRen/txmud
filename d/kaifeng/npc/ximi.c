inherit NPC;

void create()
{
        set_name("Ϸ��", ({ "ximi" }) );
        set("gender", "����" );
        set("age", 48);
        set("long", "һ�������������Ϸ��\n");

        set("combat_exp", 600);

        setup();
        carry_object(ARMOR_DIR"cloth")->wear();        
}
