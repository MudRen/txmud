// Room: /d/path4/hwc18.c

inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
����һ��ʲ��Ҳû�еĿշ��䡣

LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "southwest" : __DIR__"hwc22",
  "east" : __DIR__"hwc17",
  "north" : __DIR__"hwc19",
]));
	set("outdoors", "path4");
	setup();
	replace_program(ROOM);
}
