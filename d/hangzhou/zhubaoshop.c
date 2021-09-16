// Room: /d/hangzhou/zhubaoshop.c

inherit ROOM;

void create()
{
	set("short", "珠宝店");
	set("long", @LONG
这是一间规模不大的珠宝店，生意看上去却是满不错的，据
说这里的老板很有些办法，常常有些藏边和关外的好东西，所以
杭州知府常常派人到这里挑些珠宝当做礼物。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"minan05",
]));

	setup();
	replace_program(ROOM);
}
