// Room: /d/hangzhou/zfpath7.c

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
	set("exits", ([ /* sizeof() == 3 */
  //"west" : __DIR__"zfpath5",
  "west" : __DIR__"zfroom",
  "east" : __DIR__"zfzf",
  "north" : __DIR__"zfpath8",
]));

	setup();
	replace_program(ROOM);
}
