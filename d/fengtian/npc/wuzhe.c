// wuzhe.c

inherit NPC;
 
void create()
{
	set_name("����", ({"wu zhe"}));
	set("long", "����һ�����⺷֮���Ĺ����
���������ӻ�����书��\n");
	set("gender","����");

	set("age",35);
	set("con",20);
	set("str",20);

	set_skill("unarmed",100);
	set_skill("dodge",90);
	set_skill("parry",90);
	set_skill("sword",70);
	set_skill("lianhuan-sword",50);

	map_skill("sword","lianhuan-sword");
	map_skill("parry","lianhuan-sword");

	set("combat_exp",250000);

	setup();

	carry_object(WEAPON_DIR"sword")->wield();
	carry_object(ARMOR_DIR"cloth")->wear();
}
