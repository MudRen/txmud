// muren.c

inherit NPC;

void create()
{
	set_name("ľ��", ({ "mu ren" }) );
	set("long", "����һ����̾�ϸ��ľ�ˡ�\n");
	set("max_gin", 400);
	set("max_kee", 500);
	set("max_sen", 400);

	set("str", 30);
	set("cor", 20);
	set("con", 30);

	set_skill("unarmed",1);
	set_skill("dodge",1);
	set("combat_exp",200000+random(20000));

	set_temp("apply/attack",80);
	set_temp("apply/defense",75);

	setup();
}
