// Room: /d/northft/ftn3.c

inherit ROOM;

void create()
{
	set("short", "青石小路");
	set("long", @LONG
这是奉天城北门外一条青石铺成的小路，南面就是奉天城的
北门了。路边稀疏的长着一些荒草，路上满是沙砾，阵阵北风呼
啸而过，越发给人一种凄凉的感觉。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"ftn2",
  "north" : __DIR__"ftn4",
]));

	set("outdoors", "northft");

	setup();
	replace_program(ROOM);
}
