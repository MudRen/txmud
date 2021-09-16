// Room: /wiz/louth/a/shandong3.c

inherit ROOM;

void create()
{
	set("short", "山洞");
	set("long", @LONG
这里是宽敞干燥的大山洞，四周的石壁凿的十分平整，上面
插着几只点燃的火把，地上铺着细细的沙子，踩上去格外舒适。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "east" : __DIR__"shandong4",
  "south" : __DIR__"shandong2",
  "north" : __DIR__"shandong5",
]));
	setup();
	replace_program(ROOM);
}
