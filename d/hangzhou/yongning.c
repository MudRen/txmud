// Room: /d/hangzhou/yongning.c

inherit ROOM;

void create()
{
	set("short", "永宁街口");
	set("long", @LONG
这里是永宁街和国泰路交会的地方，这里向东就是杭州府衙
所在的国泰街，南北则是比较清静的永宁路。
LONG
	);
	set("outdoors", "hangzhou");
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"blacksmith",
  "south" : __DIR__"yongnings1",
  "east" : __DIR__"guotaiw3",
  "north" : __DIR__"yongningn1",
]));

	setup();
	replace_program(ROOM);
}
