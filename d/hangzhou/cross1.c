// Room: /d/hangzhou/cross1.c

inherit ROOM;

void create()
{
	set("short", "路口");
	set("long", @LONG
这是民安街和国泰街的交叉口，从这里向南有一条小路可以
到达闻名遐尔的苏堤。
LONG
	);
	set("no_clean_up", 0);
	set("outdoors", "hangzhou");
	set("exits", ([ /* sizeof() == 5 */
  "south" : __DIR__"rockroad1",
  "west" : __DIR__"guotaiw1",
  "east" : __DIR__"guotaie1",
  "north" : __DIR__"minan05",
  //"southeast" : __DIR__"yongning01",
]));

	setup();
	replace_program(ROOM);
}
