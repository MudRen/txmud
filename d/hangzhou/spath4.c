// Room: /d/hangzhou/spath4.c

inherit ROOM;

void create()
{
	set("short", "林间小路");
	set("long", @LONG
这是一条林间小路，你只能从地上被踏歪的杂草来识别前进
的方向。忽然一只不知名的东西从你面前窜过，吓了你一跳。想
南方的树林多有毒虫，你不由得不小心谨慎。东面树丛中隐露出
一间茅屋。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"spath5",
  "east" : __DIR__"shouse1",
  "north" : __DIR__"spath3",
]));
	set("outdoors", "hangzhou");

	setup();
	replace_program(ROOM);
}
