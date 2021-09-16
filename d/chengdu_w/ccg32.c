// Room: /d/path5/ccg32.c

inherit ROOM;

void create()
{
	set("short", "高原山路");
	set("long", @LONG
你走到一条高原山路上，四周一望无际。蓝蓝的天空上飘着
朵朵白云，偶尔有苍鹰在头项滑翔而过。你警惕地看了看，只见
四周一遍静寂，看不到一个人。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "southeast" : __DIR__"ccg31",
  "westup" : __DIR__"ccg33",
]));
        set("outdoors", "chengdu_w");
        set("cannot_build_home", 1);
	setup();
	replace_program(ROOM);
}
