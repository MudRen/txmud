// Room: /d/path4/cd13.c

inherit ROOM;

void create()
{
	set("short", "ɽ��·");
	set("long", @LONG
����һ��ʲ��Ҳû�еĿշ��䡣

LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"cd14",
  "north" : __DIR__"cd12",
]));
	set("outdoors", "path4");
	setup();
	replace_program(ROOM);
}
