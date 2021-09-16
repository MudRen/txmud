// Room: /d/hangzhou/jiyuan01.c

inherit ROOM;

void create()
{
	set("short", "雅间过厅");
	set("long", @LONG
这里通向万花楼的后花厅，后花厅是万花楼最有名的三朵金
花待客的场所，能够一探香闺的客人非富即贵，寻常人等是根本
没法一亲芳泽的。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"jiyuan",
  "east" : __DIR__"jiyuan02",
]));

	setup();
	replace_program(ROOM);
}
