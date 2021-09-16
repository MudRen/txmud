// Room: /wiz/louth/a/shandong2.c

inherit ROOM;

void create()
{
	set("short", "山洞");
	set("long", @LONG
这里是宽敞干燥的大山洞，四周的石壁凿的十分平整，上面
插着几只点燃的火把，地上铺着细细的沙子，踩上去格外舒适。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"shandong1",
  "north" : __DIR__"shandong3",
]));
	replace_program(ROOM);
}
