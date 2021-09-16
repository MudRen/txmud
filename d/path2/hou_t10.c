// Room: /d/path2/hou_t10.c

#include <cross_river.h>

inherit CROSS_RIVER_BANK;

void create()
{
	set("short", "渡口");
	set("long", @LONG
这里是黄河中游东岸的渡口，汹涌的河水拍打着岸边，不时
发出轰轰的声响。一道碗粗的绳索跨过河面伸向另一岸，绳索下
涛涛的河水携带着滚滚黄沙奔驰而过。过河的话只能喊(yell)船
家过来渡你。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"hou_t9",
]));

	set_boat_file(__DIR__"duchuan2");
	set_max_passenger(4);
	set_yell_msg("$N扯着嗓子喊道：“船家！！我要过黄河！！”\n");

	set("outdoors", "path2");
	setup();
}
