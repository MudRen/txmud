// Room: /d/path4/hwc05.c

inherit ROOM;

void create()
{
	set("short", "����·");
	set("long", @LONG
����һ��ʲ��Ҳû�еĿշ��䡣

LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "southwest" : __DIR__"hwc06",
  "east" : __DIR__"hwc04",
]));
	set("outdoors", "path4");
	setup();
	replace_program(ROOM);
}
