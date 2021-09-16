// Room: /d/hangzhou/zfgarden.c

inherit ROOM;

void create()
{
	set("short", "小花园");
	set("long", @LONG
这里是一个精致的小花园，花园虽然不大，但各种花草错落
有致，一座假山掩映在树丛之中，两只长尾孔雀逡巡的踱到你的
面前，好奇的打量着你。
LONG
	);
	set("outdoors", "hangzhou");
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"zfpath3",
  "north" : __DIR__"zfpath4",
]));

	setup();
	replace_program(ROOM);
}
