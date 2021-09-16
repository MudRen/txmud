// Room: /d/hangzhou/zfpath6.c

inherit ROOM;

void create()
{
	set("short", "过道");
	set("long", @LONG
这是一条过廊，知府大人每天退堂都要经过这条走廊，走廊
的两边是松木雕刻的围栏，围栏外面是一个小花园，花园虽然不
大，但却是花草茂盛，春色满园。

LONG
	);
	set("outdoors", "hangzhou");
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"zfdatang",
  "west" : __DIR__"zfpath4",
]));

	setup();
	replace_program(ROOM);
}
