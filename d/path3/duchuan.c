// Room: /d/path3/duchuan.c

#include <cross_river.h>

inherit CROSS_RIVER_BOAT;

void create()
{
	set("short", "渡船");
	set("long", @LONG
这是一条由粗毛竹制成的渡船，大约能载四、五个人。
LONG
	);

	set(SAFE_ENV,1);

	set_boat_master(__DIR__"npc/shaogong");
	set_boat_bank1(__DIR__"k_h28");
	set_boat_bank2(__DIR__"k_h27");
	set_bank1_desc("长江南岸");
	set_bank2_desc("长江北岸");
	set_cross_msg("过长江");

	setup();
}
