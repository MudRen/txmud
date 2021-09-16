// Room: /d/path1/cc_tch15.c

inherit ROOM;

void create()
{
	set("short", "土路");
	set("long", @LONG
这是一条黄土小路，再向南去，是一片树林，远处看去，仿
佛像一绿色城墙。北面不远就是“渡马坡”了。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"cc_tch14",
  "north" : __DIR__"cc_tch16",
]));
	set("outdoors", "path1");
	setup();
	replace_program(ROOM);
}
