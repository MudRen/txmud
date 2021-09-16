// Room: /u/w/wangs/a/yu28.c

inherit ROOM;

void create()
{
	set("short", "走廊");
	set("long", @LONG
走在这条长廊上，但见红栏碧瓦，一派富贵气象。边上
假山小湖应有尽有，显得十分秀丽。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"yu27",
  "east" : __DIR__"yu29",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
