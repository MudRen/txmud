// Room: /d/shaolin/caidi.c

inherit ROOM;

void create()
{
	set("short", "菜地");
	set("long", @LONG
这里是少林寺的一大片菜地，少林弟子如果犯了戒，又不至
于去面壁，往往发到这里种菜。这里的菜将供应全寺，只见四下
大片的绿油油的蔬菜，几个小僧正忙着挑水浇园。从这里向北是
西跨院。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"w_court",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
