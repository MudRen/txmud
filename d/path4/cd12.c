// Room: /d/path4/cd12.c

inherit ROOM;

void create()
{
	set("short", "ɽ��·");
	set("long", @LONG
����һ��ʲ��Ҳû�еĿշ��䡣

LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"cd13",
  "north" : __DIR__"cd11",
]));
	set("outdoors", "path4");
	setup();
	replace_program(ROOM);
}
