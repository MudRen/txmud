// Room: /wiz/louth/c/jguanlu1.c

inherit ROOM;

void create()
{
	set("short", "锦官路");
	set("long", @LONG
这里是成都的锦官路。南边是成都的二麻鞋店。东西方向则
贯穿成都北部的锦官路。
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"xiemaodian",
  "west" : __DIR__"jguanlu2",
  "east" : __DIR__"shizi",
]));

	set("outdoors","chengdu");

	setup();
	replace_program(ROOM);
}
