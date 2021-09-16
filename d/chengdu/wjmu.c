// Room: /wiz/louth/c/wjmu.c

inherit ROOM;

void create()
{
	set("short", "王建墓");
	set("long", @LONG
这间王建墓是为五代时前蜀皇帝王建所修的陵墓。整个墓室
很大，非常雄伟壮观。自蜀皇帝王建死去以后就有许多的盗墓者
们想借次大发横财，可是至今没有人能盗走墓室中的财宝。从这
里想东走就是锦官路。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"jguanlu4",
]));

	set("outdoors","chengdu");

	setup();
	replace_program(ROOM);
}
