inherit NPC;

void create()
{
        set_name("����ʦ", ({ "li biaoshi" , "biaoshi" , "li" }) );
        set("gender", "����" );
        set("age", 37);
        set("long", "����ʦ���ھ��Ѿ��ܶ����ˡ�\n");

        set("combat_exp", 100000);
        set("str", 20);
        set("int", 30);
        set("force", 1900);
        set("max_force", 1900);
        set("force_factor", 10);

        set_skill("dodge",50);
        set_skill("parry",50);
        set_skill("unarmed",60);

	setup();
	carry_object(ARMOR_DIR"cloth")->wear();
}
