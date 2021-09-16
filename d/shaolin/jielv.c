// Room: /d/shaolin/jielv.c

inherit ROOM;

void create()
{
	set("short", "戒律院");
	set("long", @LONG
这里就是有名的少林寺戒律院，这里的主持执法极为严格，
一但发现有违反戒律的僧人，绝不会徇私留情。南边有一个刑架，
是对犯僧执行杖责用的。从这里向东是清冷石屋，向西则是青石
甬道。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"yongdao3",
  "west" : __DIR__"shiwu",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
