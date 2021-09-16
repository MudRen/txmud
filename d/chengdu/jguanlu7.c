// Room: /wiz/louth/c/jguanlu7.c

inherit ROOM;

void create()
{
	set("short", "锦官路");
	set("long", @LONG
这是成都的锦官路。在这里向北是商栈。向南是一家面管。
东西方向可以通过整个锦官路。
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"jguanlu6",
  "east" : __DIR__"jguanlu8",
  "north" : __DIR__"business",
]));

	set("outdoors","chengdu");

	setup();
	replace_program(ROOM);
}
