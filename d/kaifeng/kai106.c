// Room: /u/w/wangs/b/kai106.c

inherit ROOM;

void create()
{
	set("short", "开封南街");
	set("long", @LONG
宽阔的南大街上到处是南来北往的商客，有的人面带喜色，
有的愁容满面，看来在开封这座商业舞台上站稳脚跟并不是很容
易的事情啊，有很多人一夜之间暴富，也有人倾刻之间便倾家荡
产，人世间的悲欢离合就在这里一幕幕的上演着。西面是李记药
铺，东边是一间香粉屋。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"kai103",
  "south" : __DIR__"kai113",
  "west" : __DIR__"kai111",
  "east" : __DIR__"kai112",
]));

	set("outdoors","kaifeng");
	setup();
	replace_program(ROOM);
}
