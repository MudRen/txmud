// Room: /d/path5/duchuan.c

#include <cross_river.h>

inherit CROSS_RIVER_BOAT;

void create()
{
	set("short", "ľ��");
	set("long", @LONG
����һ�Ҳ�С��ľ������������˵Ҳ����7��8���ˡ�
LONG
	);
	set(NO_KILL,1);
	set("no_clean_up",1);
	set("cannot_build_home", 1);

	set_boat_master(__DIR__"npc/li");
	set_boat_bank1("/d/path3/k_s20");
	set_boat_bank2(__DIR__"na12");
	set_bank1_desc("��������");
	set_bank2_desc("�����ϰ�");
	set_cross_msg("������");

	setup();
}
