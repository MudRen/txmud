// Room: /wiz/louth/c/wmlu1.c

inherit ROOM;

void create()
{
	set("short", "万明路");
	set("long", @LONG
这里是成都的万明路。由这里向南就是府道街。向北是鸭子
王烤鸭店。向东是一个僻巷。向西则通过整个万明路。
LONG
);

	set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"fdjie5",
  "west" : __DIR__"wmlu2",
  "east" : __DIR__"pixiang",
  "north" : __DIR__"yaziwang",
]));

	set("outdoors","chengdu");

	setup();
	replace_program(ROOM);
}
