// dizi.c

inherit NPC;
 
void create()
{
	set_name("��ݵ���", ({"wuguan dizi", "dizi"}));
	set("long", "����һλ��׳�Ĵ󺺣�һ����
�����������书���ˡ�\n");
	set("gender","����");

	set("age",28);
	set("con",30);
	set("str",20);
	set("max_kee",700);
	set("max_gin",250);
	set("max_sen",250);

	set_skill("dodge",90);
	set_skill("parry",90);
	set_skill("unarmed",70);

	set("combat_exp",40000);

	setup();
	carry_object(ARMOR_DIR"cloth")->wear();
}