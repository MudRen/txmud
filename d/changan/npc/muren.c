// muren.c

inherit NPC;

void create()
{
	set_name("ľ��", ({ "mu ren" }) );
	set("long", "�����ô��������Ƶĵ�ľ�ˡ�\n");
	set("max_gin", 800);
	set("max_kee", 1000);
	set("max_sen", 1000);

	set("str", 25);
	set("cor", 30);
	set("con", 40);
	set("kar", 30);

	set_skill("unarmed",20);
	set_skill("dodge",150);
	set("combat_exp",40000);

	set_temp("apply/attack",60);
	set_temp("apply/defense",40);

	setup();
}
