// Room: /d/path4/hwc31.c

inherit ROOM;

void create()
{
	set("short", "С·");
	set("long", @LONG
����һ��ʲ��Ҳû�еĿշ��䡣

LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"hwc32",
  "north" : __DIR__"hwc30",
]));
	set("outdoors", "path4");
	setup();
	replace_program(ROOM);
}
