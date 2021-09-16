// Room: /d/path2/duchuan.c

#include <cross_river.h>

inherit CROSS_RIVER_BOAT;

void create()
{
	set("short", "渡船");
	set("long", @LONG
这是一条普通的黄河渡船，大约能载四、五个人。
LONG
	);

	set(SAFE_ENV,1);

	set_boat_master(__DIR__"npc/shaogong");
	set_boat_bank1(__DIR__"ch_k29");
	set_boat_bank2(__DIR__"ch_k30");
	set_bank1_desc("黄河北岸");
	set_bank2_desc("黄河南岸");
	set_cross_msg("过黄河");

	setup();
}
