// Room: /wiz/louth/c/fdjie4.c

inherit ROOM;

void create()
{
	set("short", "府道街");
	set("long", @LONG
这里是府道街。从这里向北可以通到鸭子王烤鸭店。一直向
南走是锦官路。东面是周记当铺。
LONG
);

	set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"fdjie3",
  "east" : __DIR__"dangpu",
  "north" : __DIR__"fdjie5",
]));

	set("outdoors","chengdu");

	setup();
	replace_program(ROOM);
}
