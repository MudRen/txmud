// Room: /d/path5/ccg03.c

inherit ROOM;

void create()
{
	set("short", "青石板路");
	set("long", @LONG
这是一条用青石板铺成的大路。路人来来往往的人很多，还
有许多小贩在沿街叫卖，呈现出一遍繁华的景象。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"ccg04",
  "east" : __DIR__"ccg02",
]));
        set("outdoors", "chengdu_w");
        set("cannot_build_home", 1);
	setup();
	replace_program(ROOM);
}
