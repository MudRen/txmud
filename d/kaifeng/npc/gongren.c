inherit NPC;

void create()
{
        set_name("����", ({ "gong ren" , "ren"}) );
        set("gender", "����" );
        set("age", 37);
        set("long", "һλ���ڸɻ����������.\n");

        set("combat_exp", 800);

        setup();
        carry_object(ARMOR_DIR"cloth")->wear();        
}
