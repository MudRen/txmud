// Room: /d/path4/hwc27.c

inherit ROOM;

void create()
{
	set("short", "ɽʯ·");
	set("long", @LONG
����һ��ʲ��Ҳû�еĿշ��䡣

LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"hwc28",
  "east" : __DIR__"hwc26",
]));
	set("outdoors", "path4");
	setup();
	replace_program(ROOM);
}
