// Room: /d/chengdu/scd04.c

inherit ROOM;

void create()
{
	set("short", "青石官道");
	set("long", @LONG
这是一条用青石板铺成的大路。路人来来往往的人很多，还
有许多小贩在沿街叫卖，呈现出一遍繁华的景象。由此再向北走
就到成都南门了。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"scd03",
  "southwest" : "/d/tangmen/lcd01",
]));

	set("outdoors", "chengdu");

	setup();
	replace_program(ROOM);
}
