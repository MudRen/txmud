// yulin.c

inherit NPC;

void create()
{
	set_name("���־�У", ({ "jun xiao"}) );
	set("gender", "����");
	set("age", 27);

	set("long",@LONG
����һλ����������־�У��ר˾�����ʳǡ�
���־���ÿһλ��Ա���Ǵ��׹�󳼵��ӵ�
��ѡ�γ����ģ���ֻ��һ����ͨ�ľ�У��
����Ҳ��һ�㡣
LONG
);
	set("vendetta_mark", "guanfu");
	set("combat_exp", 200000);
	set("str",40);
	set("con",30);
	set("max_force",2000);
	set("force",2000);
	set("force_factor",60);

	set("max_atman",1000);
	set("atman",1000);
	set("max_mana",1000);
	set("mana",1000);
	set("max_kee",1500);
	set("max_gin",1500);
	set("max_sen",1500);
	set("attitude", "heroism");

	set_skill("unarmed",150);
	set_skill("force",200);
	set_skill("parry", 180);
	set_skill("dodge", 180);
	set_skill("fork",180);
	set_skill("qiuyue-fork",150);
	map_skill("fork","qiuyue-fork");
	map_skill("parry","qiuyue-fork");

	setup();

	carry_object(WEAPON_DIR"spear")->wield();
	carry_object(ARMOR_DIR"armor")->wear();
}
