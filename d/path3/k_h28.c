// Room: /d/path3/k_h28.c

#include <cross_river.h>

inherit CROSS_RIVER_BANK;

void create()
{
	set("short", "仙人渡南渡");
	set("long", @LONG
这里是长江南岸，到江北的人通常都由这里过渡，虽然摆渡
费并不便宜。舵主胡三外号过江龙，听说家传三代都在这里做渡
江生意。你要是也想由此过江（yell），就只有搭他的船了。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"k_h29",
]));

	set_boat_file(__DIR__"duchuan");
	set_max_passenger(4);
	set_yell_msg("$N扯着嗓子喊道：“船家！！我要过长江！！”\n");

	set("outdoors", "path3");

	setup();
}
