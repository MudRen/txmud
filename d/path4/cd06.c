// Room: /d/path4/cd06.c

inherit ROOM;

void create()
{
	set("short", "���ɽ·");
	set("long", @LONG
����һ��ʲ��Ҳû�еĿշ��䡣

LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "northwest" : __DIR__"cd05",
  "east" : __DIR__"cd07",
]));
	set("outdoors", "path4");
	setup();
	replace_program(ROOM);
}
