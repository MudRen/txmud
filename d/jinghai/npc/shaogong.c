// shaogong.c

#include <cross_river.h>

inherit CROSS_RIVER_MASTER;

void create()
{
        set_name("ˮ��", ({"shui yong"}));
        set("long", @LONG
����һλľ������ˮ�¡�
LONG
);
        set("gender","����");

        set("age",36);
        set("con",20);
        set("str",30);
	set_skill("unarmed",60);
	set_skill("dodge",60);
	set_skill("parry",60);
	set(NO_KILL, 1);

        set("combat_exp",8000);

	set_max_passenger(10);
	set_cross_msg("�ɺ�");

        setup();
        carry_object(ARMOR_DIR"cloth")->wear();
}

// �����������ʹ�������˲���Ǯ
int accept_object(object me,object obj)
{
	if(me->query("class") == "jinghai")
		return notify_fail(sprintf("%sҡҡͷ˵������������һ����ѡ�\n", name()));
	else
		return ::accept_object(me, obj);
}
