// Room: /u/w/wangs/a/yu29.c

inherit ROOM;

void create()
{
	set("short", "走廊");
	set("long", @LONG
走在这条长廊上，但见红栏碧瓦，一派富贵气象。边上
假山小湖应有尽有，显得十分秀丽。这条走廊通向了南边一
间寝室，不知是什么所在。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"yu30",
  "west" : __DIR__"yu28",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
