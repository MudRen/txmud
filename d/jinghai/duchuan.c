// Room: /d/path2/duchuan.c

#include <cross_river.h>

inherit CROSS_RIVER_BOAT;

void create()
{
	set("short", "����");
	set("long", @LONG
����һ�Ҳ�С�ĺ�������ͷһ�����������š������ɡ���
LONG
	);
	set(SAFE_ENV,1);
	set("no_clean_up",1);
	set("invalid_fuji", 1);

	set_boat_master(__DIR__"npc/shaogong");
	set_boat_bank1(__DIR__"zhuque3");
	set_boat_bank2(__DIR__"moon1");
	set_bank1_desc("��½");
	set_bank2_desc("���µ�");
	set_cross_msg("�ɺ�");

	setup();
}
