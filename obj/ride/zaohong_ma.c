// zaohong_ma.c

inherit NPC;

void create()
{
	set_name("�����", ({ "zaohong horse", "horse"}) ); 

	set("race", "Ұ��");
	set("gender", "����");
	set("unit","ƥ");
	set("age", 3);
	set("long", "����һƥ��׳�ߴ�������\n");

	set("str", 24);
	set("cor", 26);
	set("cps", 22);

	set("max_kee", 500);
	set("max_gin", 500);
	set("max_sen", 500);
	set("attitude", "peaceful");
	set("limbs", ({ "ͷ��", "����", "ǰ��", "����", "β��" }) );
	set("verbs", ({ "bite", "claw" }) );

	set("bellicosity", 10 ); 

	set_temp("apply/attack", 100);
	set_temp("apply/armor", 200);

	set("ride",1);	// �����ǡ�

	set("ride_level",2);
	setup();
}
