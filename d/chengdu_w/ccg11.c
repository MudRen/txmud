// Room: /d/path5/ccg11.c

inherit ROOM;

void create()
{
	set("short", "山林大道");
	set("long", @LONG
你走在一条山林大路上，只见两旁郁郁葱葱的全是参天大树，
随着山势起伏。不时林中传来动物的声声嚎叫，你不由得加快了
前进的步伐。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "southwest" : __DIR__"ccg12",
  "northeast" : __DIR__"ccg10",
]));
        set("outdoors", "chengdu_w");
        set("cannot_build_home", 1);
	setup();
	replace_program(ROOM);
}
