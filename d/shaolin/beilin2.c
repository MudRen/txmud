// Room: /d/shaolin/beilin2.c

inherit ROOM;

void create()
{
	set("short", "碑林");
	set("long", @LONG
这里是少林寺的碑林，这里有一些名家的书法帖刻在这里，
一些碑上的字迹由于年代久远，已经模糊不精了，但仍能看现作
者那虬劲有力的笔法。这里向西和向南仍是少林寺有名的碑林。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"beilin3",
  "west" : __DIR__"beilin1",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
