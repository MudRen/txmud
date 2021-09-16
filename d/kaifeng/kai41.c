// Room: /u/w/wangs/b/kai41.c

inherit ROOM;

void create()
{
	set("short", "小赌馆");
	set("long", @LONG
掀开门口脏兮兮的布帘走了进来，一阵吆五喝六的叫声便在
你耳畔萦绕不去，这里灯光昏暗，十来个人围着几张小方桌席地
而坐，他们赌的是牌九，赌注都不甚大，每人跟前的桌面上都摆
放着十几两散碎银子。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"kai54",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
