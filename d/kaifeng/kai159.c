// Room: /u/w/wangs/b/kai159.c

inherit ROOM;

void create()
{
	set("short", "叉路口");
	set("long", @LONG
这是一个三岔交叉路口。北边与前松街相连，南面与后松街
相接，东边是一条小胡同，通向开封城最贫苦的地区。由青石板
铺成。有一根三丈高的旗杆上，挑起四盏大的灯笼。为夜晚行人
带来了方便。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"kai160",
  "north" : __DIR__"kai158",
  "west" : __DIR__"kai179",
]));

	set("outdoors","kaifeng");
	setup();
	replace_program(ROOM);
}
