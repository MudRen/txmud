// Room: /d/hangzhou/house1.c

inherit ROOM;

void create()
{
	set("short", "民房");
	set("long", @LONG
这是一间普通的民房，这样的房子在杭州城的边缘常常能够
找到，住在这里的一般是城里的小商贩或是小店铺的主人，他们
整天忙忙碌碌的只是为了一顿饱饭，以及这样一个遮雨的地方。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"stoneroad1",
]));

	setup();
	replace_program(ROOM);
}
