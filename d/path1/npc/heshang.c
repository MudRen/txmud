// heshang.c

inherit NPC;

void create()
{
	set_name("�нź���", ({ "xingjiao heshang", "heshang" }) );
	set("long", "����һλ�нŻ�Ե�ĺ��У�����
������һ������\n");
	set("age", 38);
	set("per", 20);
	set("kar", 28);
	set("str", 35);
	set("attitude", "peaceful");
	set("combat_exp", 40000);
	set("max_kee",600);
	set("max_gin",600);
	set("max_sen",600);
	set("max_force",2000);
	set("force_factor",5);

	set_skill("parry",50);
	set_skill("dodge",50);
	set_skill("unarmed",30);

	setup();
        carry_object(__DIR__"obj/jiasha")->wear();
}
