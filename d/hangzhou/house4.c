// Room: /d/hangzhou/house4.c

inherit ROOM;

void create()
{
	set("short", "小摊");
	set("long", @LONG
这是一间普通的民房，这样的房子在杭州城的边缘常常能够
找到，住在这里的一般是城里的小商贩或是小店铺的主人，他们
整天忙忙碌碌的只是为了一顿饱饭，以及这样一个遮雨的地方。
LONG
	);
	set("outdoors", "hangzhou");
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"rockroad3",
]));

	setup();
	replace_program(ROOM);
}
