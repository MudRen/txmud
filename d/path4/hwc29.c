// Room: /d/path4/hwc29.c

inherit ROOM;

void create()
{
	set("short", "ɽʯ·");
	set("long", @LONG
����һ��ʲ��Ҳû�еĿշ��䡣

LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"hwc30",
  "east" : __DIR__"hwc28",
]));
	set("outdoors", "path4");
	setup();
	replace_program(ROOM);
}
