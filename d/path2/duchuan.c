// Room: /d/path2/duchuan.c

#include <cross_river.h>

inherit CROSS_RIVER_BOAT;

void create()
{
	set("short", "�ɴ�");
	set("long", @LONG
����һ����ͨ�ĻƺӶɴ�����Լ�����ġ�����ˡ�
LONG
	);

	set(SAFE_ENV,1);

	set_boat_master(__DIR__"npc/shaogong");
	set_boat_bank1(__DIR__"ch_k29");
	set_boat_bank2(__DIR__"ch_k30");
	set_bank1_desc("�ƺӱ���");
	set_bank2_desc("�ƺ��ϰ�");
	set_cross_msg("���ƺ�");

	setup();
}
