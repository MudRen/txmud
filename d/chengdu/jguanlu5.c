// Room: /wiz/louth/c/jguanlu5.c

inherit ROOM;

void create()
{
	set("short", "锦官路");
	set("long", @LONG
这是成都的锦官路。在这里向北是杂货铺。向南是养马廊。
东西方向可以通过整个锦官路。
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"yangmalang",
  "west" : __DIR__"shizi",
  "east" : __DIR__"jguanlu6",
  "north" : __DIR__"zahuopu",
]));

	set("outdoors","chengdu");

	setup();
	replace_program(ROOM);
}
