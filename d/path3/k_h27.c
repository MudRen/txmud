// Room: /d/path3/k_h27.c

#include <cross_river.h>

inherit CROSS_RIVER_BANK;

void create()
{
	set("short", "仙人渡");
	set("long", @LONG
这里就是仙人渡了，是过长江的重要口岸之一。由于地理位
置的原因，这里摆渡（yell）的收费可不便宜。舵主是个四十多
岁的人，看起来很老实。但本地人相信他是什么帮中的人物，不
然，收这么多黑钱早被人做了。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"k_h26",
]));

	set_boat_file(__DIR__"duchuan");
	set_max_passenger(4);
	set_yell_msg("$N扯着嗓子喊道：“船家！！我要过长江！！”\n");

	set("outdoors", "path3");
	setup();
}
