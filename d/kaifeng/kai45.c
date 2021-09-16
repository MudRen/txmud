// Room: /u/w/wangs/b/kai45.c

inherit ROOM;

void create()
{
	set("short", "马店");
	set("long", @LONG
不用看招牌，只要听见从这里不时传出的马嘶及马蹄踢踏声
中你就可以知道这里是什么地方了。这里的摆设也与别家不同，
宽敞的中堂里在靠门的一方斜摆着一张小柜台，直对大门的墙上
挂着一张横幅的八骏图，除此之外一无所有，但这里通往后院的
门到是很宽敞，足可以容下四匹马同时进出。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"kai43",
  "east" : __DIR__"kai46",
]));
        set("objects",([
        __DIR__"npc/huoji":1,
]));

	setup();
	replace_program(ROOM);
}
