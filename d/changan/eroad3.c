// Room: /d/changan/eroad3.c

inherit ROOM;

void create()
{
	set("short", "连德街");
	set("long", @LONG
这里是长安城的东大街，由于离长安城的东门不远，所以人
也渐渐的多起来。两边一些小贩，不停的吆喝着，整条大街似乎
都在喧闹着。东门是运送皇粮的粮道，所以这附近的生意人也多
做一些五谷杂粮的生意。西面是京城最大的杂货行-龙辉商行。
LONG
	);
	set("outdoors", "changan");
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"eroad2",
  "west" : __DIR__"shanghang",
  "north" : __DIR__"eroad4",
]));

	setup();
	replace_program(ROOM);
}
