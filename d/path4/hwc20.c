// Room: /d/path4/hwc20.c

inherit ROOM;

void create()
{
	set("short", "��ʯ·");
	set("long", @LONG
����һ��ʲ��Ҳû�еĿշ��䡣

LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"hwc19",
  "north" : __DIR__"hwc21",
]));
	set("outdoors", "path4");
	setup();
	replace_program(ROOM);
}
