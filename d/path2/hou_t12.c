// Room: /d/path2/hou_t12.c

inherit ROOM;

void create()
{
	set("short", "小土路");
	set("long", @LONG
这是一条坎坷的黄土小路，路边远处是高低不等的山丘。风
一吹起，漫天飘的都是粉状的黄沙，你不由得用手挡住了眼睛。
路的两侧是一排排的窑洞。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"hou_t11",
  "west" : __DIR__"hou_t13",
]));
	set("no_clean_up", 0);
	set("outdoors", "path2");
	setup();
	replace_program(ROOM);
}
