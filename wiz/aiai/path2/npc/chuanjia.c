// chuanjia.c

#include <cross_river.h>

inherit CROSS_RIVER_MASTER;

void create()
{
        set_name("����", ({"chuan jia"}));
        set("long", @LONG
����һλ������ɣ���ϴ��ҡ�
LONG
);
        set("gender","����");

        set("age",56);
        set("con",20);
        set("str",30);
	set_skill("unarmed",60);
	set_skill("dodge",60);
	set_skill("parry",60);
	set(NO_KILL, 1);

        set("combat_exp",8000);

	set_max_passenger(4);
	set_cross_msg("���ƺ�");

        setup();
        carry_object(ARMOR_DIR"cloth")->wear();
}
