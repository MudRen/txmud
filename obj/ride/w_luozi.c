// w_luozi.c

inherit WILD;

void create()
{
	set_name("Ұ����", ({ "wild luozi"}) ); 

	set("race", "Ұ��");
	set("gender", "����");
	set("unit","ͷ");
	set("age", 6);
	set("long", "����һͷ�����������Ұ���ӡ�\n");

	set("str", 24);
	set("cor", 26);
	set("cps", 22);

	set("chat_chance", 15);
	set("chat_msg", ({
		(: random_move :),
	}) );

	set("max_kee", 200);
	set("max_gin", 200);
	set("max_sen", 200);
	set("attitude", "peaceful");
	set("limbs", ({ "ͷ��", "����", "ǰ��", "����", "β��" }) );
	set("verbs", ({ "bite", "claw" }) );

	set("bellicosity", 10 ); 

	set_temp("apply/attack", 60);
	set_temp("apply/armor", 100);

	set("ride",1);	// �����ǡ�

	// msg ��Ӳ��ӻ���("\n")����.
        set("ride_msg","$N����������"+name()+"����");
        set("unride_msg","$N�����"+name()+"���Ͽ���������");

	set("ride_level",3);	// ����2�����
	setup();
}
