// jiading.c

inherit NPC;
 
void create()
{
        set_name("�Ҷ�", ({"jia ding"}));

	set("long", "����һλ��������ļҶ���\n");
	set("gender","����");

        set("age",35);
        set("con",30);
        set("str",20);
	set("max_kee",800);
	set("max_mana",1000);
	set("max_atman",1000);
	set("max_force",1000);
	set("force",1000);
	set("force_factor",10);

	set_skill("unarmed",40);
	set_skill("stick",50);
	set_skill("parry",100);
	set_skill("dodge",100);
	set_skill("force",100);

	set("combat_exp",80000);

        setup();
        carry_object(ARMOR_DIR"cloth")->wear();
	carry_object(WEAPON_DIR"stick")->wield();
}
