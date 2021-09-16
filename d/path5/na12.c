// Room: /d/path5/na12.c

#include <cross_river.h>

inherit CROSS_RIVER_BANK;

void create()
{
	set("short", "长江南岸");
	set("long", @LONG
这里位于长江中游以南，江面虽不是特宽，但水流依然十分
湍急。这里平时少有人至，想过江的话只能去和打渔为生的李老
汉商量商量了。由此向南就是汉中境地了。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"na11",
  "east"  : __DIR__"na13",
]));

	set_boat_file(__DIR__"duchuan");
	set_max_passenger(8);
	set_yell_msg("$N扯着嗓子喊道：“船家！！我要过长江！！”\n");

        set("outdoors", "path5");
        set("cannot_build_home", 1);
	setup();
}
