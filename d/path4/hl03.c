// Room: /d/path4/hl03.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
����һ��ʲ��Ҳû�еĿշ��䡣

LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"hl04",
  "north" : __DIR__"hl02",
]));
	set("outdoors", "path4");
	setup();
	replace_program(ROOM);
}
