// Room: /u/w/wangs/a/yu24.c

inherit ROOM;

void create()
{
	set("short", "走廊");
	set("long", @LONG
走在这条长廊上，但见红栏碧瓦，一派富贵气象。边上
假山小湖应有尽有，显得十分秀丽。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "southeast" : __DIR__"yu25",
  "northwest" : __DIR__"yu23",
]));
        set("objects", ([ /* sizeof() == 4 */
  __DIR__"npc/wuhuixun" : 1,
]));

	setup();
	replace_program(ROOM);
}
