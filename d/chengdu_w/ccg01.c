// Room: /d/path5/ccg01.c

inherit ROOM;

void create()
{
	set("short", "青石官道");
	set("long", @LONG
这是一条用青石板铺成的大路。路人来来往往的人很多，还
有许多小贩在沿街叫卖，呈现出一遍繁华的景象。由此再向东走
就到成都西门了。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"ccg02",
  "east" : "/d/chengdu/out_chengdu_w",
]));
        set("outdoors", "chengdu_w");
        set("cannot_build_home", 1);
	setup();
	replace_program(ROOM);
}
