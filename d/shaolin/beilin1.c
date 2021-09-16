// Room: /d/shaolin/beilin1.c

inherit ROOM;

void create()
{
	set("short", "碑林");
	set("long", @LONG
这里是少林寺的碑林，有历代的文人墨客所写的诗文，不远
处有两个孤零的白塔。不少喜爱书法的人，都在这里拓着碑文上
上字迹。从这里向西是过道，向东则仍是大片的碑林。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"beilin2",
  "west" : __DIR__"rroad1",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
