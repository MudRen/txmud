// Room: /d/jinghai/duz_m.c

#include <cross_river.h>

inherit CROSS_RIVER_BOAT;

void create()
{
	set("short", "����");
	set("long", @LONG
����һ�Ҳ�С�ĺ�������ͷһ�����������š������ɡ���
LONG
	);

	set_boat_master(__DIR__"npc/sy_zm");
	set_boat_bank1(__DIR__"bank4");
	set_boat_bank2(__DIR__"moonlu5");
	set_bank1_desc("��½");
	set_bank2_desc("���µ�");
	set_cross_msg("�ɺ�");

	setup();
}
