// Room: /d/path4/hed21.c

inherit ROOM;

void create()
{
	set("short", "��ʯɽ·");
	set("long", @LONG
����һ��ʲ��Ҳû�еĿշ��䡣

LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"hed22",
  "north" : __DIR__"hed20",
]));
	set("outdoors", "path4");
	setup();
	replace_program(ROOM);
}
