// Room: /u/w/wangs/b/kai121.c

inherit ROOM;

void create()
{
	set("short", "乐器店");
	set("long", @LONG
开封的乐器店并不是很大，店门口谢谢的长着几株梅花。当
梅花开放时，丝竹罄笛声伴着梅花的清香，使人飘飘欲仙，不知
身在何处。店子的历史很长，据说八仙之一的韩湘子用的箫就是
从这里买的。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"kai119",
]));
        set("objects",([
        __DIR__"npc/xboss": 1,
]));

	setup();
	replace_program(ROOM);
}
