// Room: /d/hangzhou/linstoreroom.c

inherit ROOM;

void create()
{
	set("short", "贮藏室");
	set("long", @LONG
这里是林员外家的贮藏室，墙壁全由大块的花岗岩磊成，坚
固异常，但里面好像没有什么值钱的东西，全是一些粮食，谷物
之类的东西。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"linpath1",
]));

	setup();
	replace_program(ROOM);
}
