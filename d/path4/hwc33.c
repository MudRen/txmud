// Room: /d/path4/hwc33.c

inherit ROOM;

void create()
{
	set("short", "���йٵ�");
	set("long", @LONG
����һ��ʲ��Ҳû�еĿշ��䡣

LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"hwc34",
  "north" : __DIR__"hwc32",
]));
	set("outdoors", "path4");
	setup();
	replace_program(ROOM);
}
