// Room: /u/w/wangs/b/kai146.c

inherit ROOM;

void create()
{
	set("short", "兵营");
	set("long", @LONG
这里是一座临街而建的兵营，距离开封的东城门只有几步之
遥。兵营门口旌旗飘扬，偶尔可以看见兵士进出换岗，并且不动
声色地寻视着四周。兵营里面到处都有官兵来来回回地走动，有
一名武将正在指挥士兵列队操练。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"kai144",
]));

        set("objects",([
        __DIR__"npc/guanbing" : 4,
]));

	setup();
	replace_program(ROOM);
}
