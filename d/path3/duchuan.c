// Room: /d/path3/duchuan.c

#include <cross_river.h>

inherit CROSS_RIVER_BOAT;

void create()
{
	set("short", "�ɴ�");
	set("long", @LONG
����һ���ɴ�ë���ƳɵĶɴ�����Լ�����ġ�����ˡ�
LONG
	);

	set(SAFE_ENV,1);

	set_boat_master(__DIR__"npc/shaogong");
	set_boat_bank1(__DIR__"k_h28");
	set_boat_bank2(__DIR__"k_h27");
	set_bank1_desc("�����ϰ�");
	set_bank2_desc("��������");
	set_cross_msg("������");

	setup();
}
