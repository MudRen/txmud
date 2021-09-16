// Room: /d/hangzhou/zfpath9.c

inherit ROOM;

void create()
{
	set("short", "过道");
	set("long", @LONG
这是府衙内堂的走廊，走廊上静悄悄的，偶尔有仆人低头走
过，两旁挂着灯笼将走廊照的亮堂堂的，透过调花的窗户可以看
到窗外盛开的鲜花。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"zfpath8",
  "east" : __DIR__"zfwife2",
]));

	setup();
	replace_program(ROOM);
}
