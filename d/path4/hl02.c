// Room: /d/path4/hl02.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
����һ��ʲ��Ҳû�еĿշ��䡣

LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"hl03",
  "north" : __DIR__"hl01",
]));
	set("outdoors", "path4");
	setup();
	replace_program(ROOM);
}
