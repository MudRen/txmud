// Room: /d/path4/hl01.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
����һ��ʲ��Ҳû�еĿշ��䡣

LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"hl02",
  "north" : __DIR__"hwc09",
]));
	set("outdoors", "path4");
	setup();
	replace_program(ROOM);
}
