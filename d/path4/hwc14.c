// Room: /d/path4/hwc14.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
����һ��ʲ��Ҳû�еĿշ��䡣

LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "northwest" : __DIR__"hwc15",
  "southeast" : __DIR__"hwc13",
]));
	set("outdoors", "path4");
	setup();
	replace_program(ROOM);
}
