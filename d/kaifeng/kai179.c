// Room: /u/w/wangs/b/kai179.c

inherit ROOM;

void create()
{
	set("short", "胡同");
	set("long", @LONG
胡同是一条狭长的巷子，这里是开封城最贫困的一角。住户
大多是些贫苦人家。胡同两边都有民居，但这些民居几乎没有一
间是完整的。残杂的屋宇，肮脏的沟渠，营养不良的面孔，使这
条胡同看起来简直就像人间地狱。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"kai176",
  "east" : __DIR__"kai159",
]));
	set("outdoors","kaifeng");

	setup();
	replace_program(ROOM);
}
