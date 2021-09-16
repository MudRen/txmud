// Room: /d/path2/duchuan.c

#include <cross_river.h>

inherit CROSS_RIVER_BOAT;

void create()
{
	set("short", "海船");
	set("long", @LONG
这是一艘不小的海船，船头一面旗子上绣着“靖海派”。
LONG
	);
	set(SAFE_ENV,1);
	set("no_clean_up",1);
	set("invalid_fuji", 1);

	set_boat_master(__DIR__"npc/shaogong");
	set_boat_bank1(__DIR__"zhuque3");
	set_boat_bank2(__DIR__"moon1");
	set_bank1_desc("大陆");
	set_bank2_desc("明月岛");
	set_cross_msg("渡海");

	setup();
}
