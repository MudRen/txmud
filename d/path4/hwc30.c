// Room: /d/path4/hwc30.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
����һ��ʲ��Ҳû�еĿշ��䡣

LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"hwc29",
  "south" : __DIR__"hwc31",
]));
	set("outdoors", "path4");
	setup();
	replace_program(ROOM);
}
