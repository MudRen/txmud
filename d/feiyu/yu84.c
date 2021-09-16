// Room: /u/w/wangs/a/yu84.c

inherit ROOM;

void create()
{
	set("short", "走廊");
	set("long", @LONG
你走在长廊上只见红栏碧瓦，雕梁画栋，廊外风吹古木，
涛声阵阵，看来绯雨阁气派果然不凡。西、南两向，各有一
间寝室。
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"yu83",
  "south" : __DIR__"yu86",
  "west" : __DIR__"yu85",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
