// Room: /d/path4/cd17.c

inherit ROOM;

void create()
{
	set("short", "���");
	set("long", @LONG
����һ��ʲ��Ҳû�еĿշ��䡣

LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"cd18",
  "north" : __DIR__"cd16",
]));
	set("outdoors", "path4");
	setup();
	replace_program(ROOM);
}
