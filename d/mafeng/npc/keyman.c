// keyman.c

inherit NPC;

void create()
{
	set_name("�����", ({ "bad man" }) );
	set("long", "����һλ�⺷�������ˡ����ϻ���һ����
�̣�һ���Ͳ���һ��������\n");

	set("max_gin", 1500);
	set("max_kee", 1500);
	set("max_sen", 1500);
	set("max_force",4500);
	set("force",4500);
	set("force_factor",70);
	set("str", 50);
	set("cor", 30);
	set("kar", 35);
	set("combat_exp", 2000000);

	set_skill("blade", 200);
	set_skill("pofeng-blade",200);
	set_skill("parry", 280);
	set_skill("dodge", 300);
	set_skill("unarmed", 300);

	map_skill("blade","pofeng-blade");
	map_skill("parry","pofeng-blade");

	setup();

	carry_object(__DIR__"obj/armor")->wear();
	carry_object(WEAPON_DIR"blade")->wield();
}

void die()
{
	object ob;

	if(ob = new(__DIR__"obj/key"))
		ob->move(this_object());

	::die();
}
