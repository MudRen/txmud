// Room: /d/path4/cd10.c

inherit ROOM;

void create()
{
	set("short", "ɽ��·");
	set("long", @LONG
����һ��ʲ��Ҳû�еĿշ��䡣

LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "northwest" : __DIR__"cd09",
  "southeast" : __DIR__"cd11",
]));
	set("outdoors", "path4");
	setup();
	replace_program(ROOM);
}
