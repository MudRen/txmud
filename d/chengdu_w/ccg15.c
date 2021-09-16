// Room: /d/path5/ccg15.c

inherit ROOM;

void create()
{
	set("short", "盘山路");
	set("long", @LONG
你走到一条高原山路上，看着身边的高山直耸云天。时而有
云朵飘过蓝蓝的天空，你倍感空气清新。四周一遍静寂，看不到
任何人烟。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "southeast" : __DIR__"ccg14",
  "westup" : __DIR__"ccg16",
]));
        set("outdoors", "chengdu_w");
        set("cannot_build_home", 1);
	setup();
	replace_program(ROOM);
}
