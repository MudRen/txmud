// Room: /d/path5/nanping.c

inherit ROOM;

void create()
{
	set("short", "南坪镇");
	set("long", @LONG
这里就是南坪镇了。由于处在中原到川藏的中间，人气还是
不错的。有好多少数民族都来这里和汉商交易。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"kch01",
  "north" : __DIR__"na01",
]));
        set("outdoors", "path5");
	setup();
	replace_program(ROOM);
}
