inherit NPC;

void create()
{
        set_name("Ӷ��", ({ "yong ren" , "ren"}) );
        set("gender", "Ů��" );
        set("age", 38);
        set("long", "һλ����ɨ�ص����긾Ů.\n");

        set("combat_exp", 100);

        setup();
        carry_object(ARMOR_DIR"cloth")->wear();        
}
