// Room: /d/path4/dw04.c

inherit ROOM;

void create()
{
	set("short", "ë����");
	set("long", @LONG
����һ��ʲ��Ҳû�еĿշ��䡣

LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "northwest" : __DIR__"dw05",
  "east" : __DIR__"dw03",
]));
	set("outdoors", "path4");
	setup();
	replace_program(ROOM);
}
