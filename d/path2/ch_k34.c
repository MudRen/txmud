// Room: /d/path2/ch_k34.c

inherit ROOM;

void create()
{
	set("short", "平丘");
	set("long", @LONG
这里是平丘，位于黄河以南开封府的北面，离黄河渡口不是
很远。路边时有一些小贩卖一些包子之类的食品，皮薄馅大，味
道还算不错。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"ch_k33",
  "southdown" : __DIR__"ch_k35",
]));
	set("no_clean_up", 0);
	set("outdoors", "path2");
	setup();
	replace_program(ROOM);
}
