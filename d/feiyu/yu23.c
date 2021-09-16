// Room: /u/w/wangs/a/yu23.c

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
  "southeast" : __DIR__"yu24",
  "west" : __DIR__"yu22",
]));
       set("outdoors","feiyu");

	setup();
	replace_program(ROOM);
}
