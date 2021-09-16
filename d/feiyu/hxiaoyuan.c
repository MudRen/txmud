// Room: /wiz/louth/a/huaner_xiaoyuan.c

inherit ROOM;

void create()
{
	set("short", "小院");
	set("long", @LONG
这是一个宁静的小花园，院子里种着在南方也难得一见各种
花草，院墙上爬满了藤蔓。真实一处清静忘忧的神仙所在。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"fyyg",
]));

	set("outdoors","feiyu");

	setup();
	replace_program(ROOM);
}
