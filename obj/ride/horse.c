// horse.c
// By Find.

#include <ansi.h>
inherit NPC;

void create()
{
	set_name("�����񻨴�", ({ "horse"}) ); 

	set("race", "Ұ��");
	set("gender", "����");
	set("unit","ƥ");
	set("age", 6);
	set("long", "����һƥ��ͷ����ȫ���ë��������һ��鵭��ɫ�ߵ㣬�������ף�
�񿡷Ƿ����ƽ�̤�룬���������ű�ʯ���������Ϲ���һ����ɫ��
С��ޡ�\n");

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

	set_temp("apply/attack", 100);
	set_temp("apply/armor", 200);

	set("ride",1);	// �����ǡ�

	// msg ��Ӳ��ӻ���("\n")����.
        set("ride_msg","$N����һԾ�����ȵ�������"+name()+"��");
        set("unride_msg","$N�����"+name()+"����Ծ�¡�");

	set("ride_level",2);	// ����2�����
	setup();
}
