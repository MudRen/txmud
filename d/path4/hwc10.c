// Room: /d/path4/hwc10.c

inherit ROOM;

void create()
{
	set("short", "��ʯС·");
	set("long", @LONG
����һ��ʲ��Ҳû�еĿշ��䡣

LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"hwc11",
  "east" : __DIR__"hwc09",
]));
	set("outdoors", "path4");
	setup();
	replace_program(ROOM);
}