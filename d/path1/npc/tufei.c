// tufei.c

inherit NPC;

void create()
{
	set_name("����", ({ "tu fei" }) );
	set("gender", "����" );
	set("age", 35);
	set("str",35);
	set("attitude","killer");

	set("max_kee",1000);
	set("max_gin",1000);
	set("max_sen",1000);

	set("combat_exp", 40000);

	set("long", "����������һλ��·���ٵ����ˣ�ֻ����
��������һ���׺ݶ��Ե������ӡ�\n");

	set_skill("blade",50);
	set_skill("parry",70);
	set_skill("dodge",70);
	set_skill("unarmed",70);

	setup();

	carry_object(__DIR__"obj/hujia")->wear();
	carry_object(WEAPON_DIR"blade")->wield();
}
