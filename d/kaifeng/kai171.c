// Room: /u/w/wangs/b/kai171.c

inherit ROOM;

void create()
{
	set("short", "胡同口");
	set("long", @LONG
胡同口位于开封城之东南，这里是开封城最贫困的一角。住
户大多是些贫苦人家。胡同两边都有民居，但这些民居几乎没有
一间是完整的。残杂的屋宇，肮脏的沟渠，营养不良的面孔，使
这条胡同看起来简直就像人间地狱。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 4 */
  "northeast" : __DIR__"kai174",
  "south" : __DIR__"kai164",
  "west" : __DIR__"kai172",
]));

	set("outdoors","kaifeng");

	setup();
	replace_program(ROOM);
}
