// Room: /d/path2/ch_k13.c

inherit ROOM;

void create()
{
	set("short", "土路");
	set("long", @LONG
这是一条黄土小路，路边杂草丛生，你四下望去，只见一片
凄凉。路上行人很少，偶尔有几个农夫挑着担子经过。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"ch_k12",
  "west" : __DIR__"ch_k14",
]));
	set("no_clean_up", 0);
	set("outdoors", "path2");
	setup();
	replace_program(ROOM);
}
