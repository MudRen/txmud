// Room: /d/path4/hwc32.c

inherit ROOM;

void create()
{
	set("short", "���д��");
	set("long", @LONG
����һ��ʲ��Ҳû�еĿշ��䡣

LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"hwc33",
  "north" : __DIR__"hwc31",
]));
	set("outdoors", "path4");
	setup();
	replace_program(ROOM);
}
