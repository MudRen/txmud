// wolf1.c

#include <ansi.h>
inherit NPC;

int is_hs_wolf() { return 1; }

void create()
{
        set_name( "����", ({"black wolf" }) );
        set("long", WHT"����һֻ���׳�ĺ���,����ݺ�
�ض����㡣\n"NOR);
        set("race", "Ұ��");
        set("family","����");
        set("limbs", ({ "ͷ��", "����", "β��" }) );
        set("verbs", ({ "bite" }) );

	set("max_gin", 2000);
        set("max_kee", 2000);
        set("max_sen", 2000);

	set("age", 20);

	set("str", 50);
	set("cor", 70);

        set("combat_exp", 100000);

        set("chat_chance", 5);
        set("chat_msg", ({
	(: random_move :)
}) );

	set("chat_chance_combat", 5);
	set("chat_msg_combat", ({
		HIY"���Ǻ����﷢���͵͵�������\n"NOR,
		HIY"����Ѫ����۾������㡣\n"NOR,
        }) );

	set_temp("apply/dodge", 100);
	set_temp("apply/unarmed",100);
	set_temp("apply/parry",100);
	set_temp("apply/damage",60);
	set_temp("apply/armor",100);

        setup();

}
