// Room: /d/path3/k_s20.c

#include <cross_river.h>

inherit CROSS_RIVER_BANK;

void create()
{
	set("short", "长江中游北岸");
	set("long", @LONG
这里是长江中游北岸，江水湍湍但不算很急。过了江就可以
到川中了，但你放眼望去，却看不到船家。江面上只有几只渔船，
那是一些本地的渔夫正在打鱼。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"k_s19",
    "west" : __DIR__"k_s21",
]));

	set_boat_file("/d/path5/duchuan");
	set_max_passenger(8);
	set_yell_msg("$N扯着嗓子喊道：“船家！！我要过长江！！”\n");

        set("cannot_build_home", 1);
        set("outdoors", "path3");
	setup();
}
