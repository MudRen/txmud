// Room: /u/w/wangs/a/yu90.c

inherit ROOM;

void create()
{
	set("short", "走廊");
	set("long", @LONG
你走在长廊上只见红栏碧瓦，雕梁画栋，廊外风吹古木，涛
声阵阵，看来绯雨阁气派果然不凡。北面，一楼阁拔地而起，横
匾上书三个大字“看雨轩”。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"yu91",
  "south" : __DIR__"yu89",
]));

	setup();
	replace_program(ROOM);
}
