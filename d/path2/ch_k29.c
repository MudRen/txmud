// Room: /d/path2/ch_k29.c

#include <cross_river.h>

inherit CROSS_RIVER_BANK;

void create()
{
	set("short", "黄河渡口");
	set("long", @LONG
这里是黄河下游北岸的渡口，汹涌的河水拍打着岸边，不时
发出轰轰的声响。一道碗粗的绳索跨过河面伸向另一岸，河面上
雾气腾腾，想到过河，你只有喊(yell)船家过来渡你了。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"ch_k28",
  "east" : __DIR__"an2",
  "west" : __DIR__"an1",
]));

	set_boat_file(__DIR__"duchuan");
	set_max_passenger(4);
	set_yell_msg("$N扯着嗓子喊道：“船家！！我要过黄河！！”\n");

	set("outdoors", "path2");
	setup();
}
