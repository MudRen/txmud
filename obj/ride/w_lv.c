// w_lv.c

inherit WILD;

void create()
{
	set_name("Ұ¿", ({ "wild donkey"}) ); 

	set("race", "Ұ��");
	set("gender", "����");
	set("unit","ͷ");
	set("age", 6);
	set("long", "����һͷ�����������Ұ¿��\n");
	set("chat_chance", 15);
	set("chat_msg", ({
		(: random_move :),
	}) );

	set("str", 24);
	set("cor", 26);
	set("cps", 22);

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
        set("ride_msg","$N����һԾ�����ȵ�������"+name()+"ƨ�ɡ�");
        set("unride_msg","$N�����"+name()+"���Ͽ���������");

	set("ride_level",2);	// ����2�����
	setup();
}
