// wu_whorse.c

inherit WILD;

void create()
{
	set_name("Ұ��", ({ "wild horse"}) ); 

	set("race", "Ұ��");
	set("gender", "����");
	set("unit","ƥ");
	set("age", 6);
	set("long", "����һƥ������ë������Ұ��\n");

	set("str", 24);
	set("cor", 26);
	set("cps", 22);
	set("chat_chance", 15);
	set("chat_msg", ({
		(: random_move :),
	}) );
	set("max_kee", 400);
	set("max_gin", 400);
	set("max_sen", 400);
	set("attitude", "peaceful");
	set("limbs", ({ "ͷ��", "����", "ǰ��", "����", "β��" }) );
	set("verbs", ({ "bite", "claw" }) );

	set("bellicosity", 10 ); 

	set_temp("apply/attack", 100);
	set_temp("apply/armor", 200);

	set("ride",1);	// �����ǡ�

	// msg ��Ӳ��ӻ���("\n")����.
        set("ride_msg","$N����һԾ�����ȵ�������"+name()+"��");
        set("unride_msg","$N�����"+name()+"����Ծ�¡�");

	set("ride_level",4);	// ����2�����
	setup();
}
