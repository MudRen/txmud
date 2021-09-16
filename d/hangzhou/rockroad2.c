// Room: /d/hangzhou/rockroad2.c

inherit ROOM;

void create()
{
	set("short", "碎石路");
	set("long", @LONG
你正走在一条碎石铺就的小路上，路两旁绿树成荫，繁花似
锦，真是让人着迷，往西不远，你就可以望见天下闻名的苏堤了
。
LONG
	);
	set("outdoors", "hangzhou");
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"dock2",
  "south" : __DIR__"rockroad3",
  "east" : __DIR__"guancaishop",
  "north" : __DIR__"rockroad1",
]));

	setup();
	replace_program(ROOM);
}
