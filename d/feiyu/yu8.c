// Room: /u/w/wangs/a/yu8.c

inherit ROOM;

void create()
{
	set("short", "柴房");
	set("long", @LONG
这是间不宽的柴房，房子里的木柴已经快烧光了，墙角
放着几把『柴刀』。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"yu18",
]));

	setup();
	replace_program(ROOM);
}
