// Room: /wiz/louth/c/jguanlu8.c

inherit ROOM;

void create()
{
	set("short", "锦官路");
	set("long", @LONG
这是成都的锦官路。向北就是府道街。向东就是菀枫棋院。
向西可以通过整个锦官路.
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"jguanlu7",
  "north" : __DIR__"fdjie1",
]));

	set("outdoors","chengdu");

	setup();
	replace_program(ROOM);
}
