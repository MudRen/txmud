// Room: /d/path5/duchuan.c

#include <cross_river.h>

inherit CROSS_RIVER_BOAT;

void create()
{
	set("short", "木船");
	set("long", @LONG
这是一艘不小的木船，看样子少说也能坐7、8个人。
LONG
	);
	set(NO_KILL,1);
	set("no_clean_up",1);
	set("cannot_build_home", 1);

	set_boat_master(__DIR__"npc/li");
	set_boat_bank1("/d/path3/k_s20");
	set_boat_bank2(__DIR__"na12");
	set_bank1_desc("长江北岸");
	set_bank2_desc("长江南岸");
	set_cross_msg("过长江");

	setup();
}
