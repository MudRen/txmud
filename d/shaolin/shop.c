// Room: /wiz/uudd/path2/shop.c

inherit ROOM;

void create()
{
	set("short", "杂货店");
	set("long", @LONG
这里说是个杂货店，其实只是户人家。主人在家里的墙上开
了一个窗口，装上几块门板，就把自己的卧室变成商店了。你从
窗口伸头向里望去，屋里并没有柜台，只有一张八仙桌，上面摆
满了日常用品和一些零食，店主人就坐在床上冲你一笑。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"k_s11",
]));

	setup();
	replace_program(ROOM);
}
