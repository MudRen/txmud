// Room: /d/path4/hl04.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
����һ��ʲ��Ҳû�еĿշ��䡣

LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"hl05",
  "north" : __DIR__"hl03",
]));
	set("outdoors", "path4");
	setup();
	replace_program(ROOM);
}
