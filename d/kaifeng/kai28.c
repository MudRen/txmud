// Room: /u/w/wangs/b/kai28.c

inherit ROOM;

void create()
{
	set("short", "民居");
	set("long", @LONG
这是一个富足的人家，宽宽的宅院里种满了花草，主屋是一
座两层小楼，两边还有几间偏房，一个仆役模样的中年女人正在
厨房外的水槽边洗刷物品，你问了一下，原来这里的主人就是开
封皮货行的老板。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"kai27",
]));
        set("objects",([
        __DIR__"npc/shaofu": 1,
]));

	setup();
	replace_program(ROOM);
}
