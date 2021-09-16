// Room: /d/changan/eroad2.c

inherit ROOM;

void create()
{
	set("short", "连德街");
	set("long", @LONG
这里是长安城的东大街，来往的人少，是城东比较繁华的地
段，三三两两的乞丐懒洋洋的靠在路边。连德街有此向北面延伸。
东面是京城最大的药铺-京东大药房。
LONG
	);
	set("outdoors", "changan");
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 3 */
  "east" : __DIR__"yaofang",
  "south" : __DIR__"eroad1",
  "north" : __DIR__"eroad3",
]));

	setup();
	replace_program(ROOM);
}
