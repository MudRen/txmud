// Room: /d/hangzhou/house5.c

inherit ROOM;

void create()
{
	set("short", "后院");
	set("long", @LONG
这是一个不大的院落，院子上面的架子上爬满了藤蔓，中间
放着石桌石椅，边上的小水塘里还养着鱼，非常雅致。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"house2",
  "west" : __DIR__"house6",
]));

	set("cannot_build_home",1);
	set("outdoors","hangzhou");

	setup();
	replace_program(ROOM);
}
