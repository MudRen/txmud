// Room: /d/path4/cd15.c

inherit ROOM;

void create()
{
	set("short", "ɽʯ·");
	set("long", @LONG
����һ��ʲ��Ҳû�еĿշ��䡣

LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "northwest" : __DIR__"cd14",
  "southeast" : __DIR__"cd16",
]));
	set("outdoors", "path4");
	setup();
	replace_program(ROOM);
}
