inherit NPC;

void create()
{
        set_name("����", ({ "yi zhe" }) );
        set("gender", "����" );
        set("age", 67);
        set("long", "һλ�׷�ͯ�յ�����.\n");

        set("combat_exp", 200);

        setup();
        carry_object(ARMOR_DIR"cloth")->wear();        
}
