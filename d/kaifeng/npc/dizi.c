inherit NPC;

void create()
{
        set_name("��ݵ���", ({ "wuguan dizi" , "dizi" }) );
        set("gender", "����" );
        set("age", 24);
        set("long", "һ����ݵļ������ӡ�\n");

	set("max_kee",700);
	set("max_gin",700);
	set("max_sen",700);

        set("combat_exp", 30000);
        set("str", 20);
        set("int", 30);

	set_skill("dodge",50);
        set_skill("parry",50);
        set_skill("unarmed",40);

        setup();
        carry_object(ARMOR_DIR"cloth")->wear();
}
