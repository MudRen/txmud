// Room: /d/path4/hwc28.c

inherit ROOM;

void create()
{
	set("short", "ɽʯ·");
	set("long", @LONG
����һ��ʲ��Ҳû�еĿշ��䡣

LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"hwc29",
  "east" : __DIR__"hwc27",
]));
	set("outdoors", "path4");
	setup();
	replace_program(ROOM);
}
