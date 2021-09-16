// Room: /d/hangzhou/linyuanzi.c

inherit ROOM;

void create()
{
	set("short", "天井");
	set("long", @LONG
绕过影壁墙，你正站在林员外府第的前院里，偌大的院子全
部由青石铺地，清洁得一尘不染，北面是一排小平房，南面则是
一排马圈。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"linhorse",
  "west" : __DIR__"linhouse",
  "east" : __DIR__"linneiyuan",
  "north" : __DIR__"linchaifang",
]));
	set("outdoors", "hangzhou");

	setup();
	replace_program(ROOM);
}
