// Room: /d/path4/hwc11.c

inherit ROOM;

void create()
{
	set("short", "��ʯС·");
	set("long", @LONG
����һ��ʲ��Ҳû�еĿշ��䡣

LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"hwc12",
  "east" : __DIR__"hwc10",
]));
	set("outdoors", "path4");
	setup();
	replace_program(ROOM);
}
