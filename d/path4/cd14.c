// Room: /d/path4/cd14.c

inherit ROOM;

void create()
{
	set("short", "ɽʯ·");
	set("long", @LONG
����һ��ʲ��Ҳû�еĿշ��䡣

LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "southeast" : __DIR__"cd15",
  "north" : __DIR__"cd13",
]));
	set("outdoors", "path4");
	setup();
	replace_program(ROOM);
}
