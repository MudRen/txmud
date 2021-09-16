// huazhen1.c
// feng

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short",HIR"花阵"NOR);
        set("long",@LONG
这庭院只深一丈六尺三，四周都是花，隐约可见有几条小路通向四周
，阵阵花香飘来，你不觉有些昏昏欲睡。路象蜘蛛丝一样复杂，看来你是
迷路了。
LONG);
	set("outdoors","taxue");

	set("exits", ([
		"northeast" : __FILE__,
		"southeast" : __DIR__"zoulang2",
		"southwest" : __FILE__,
		"northwest" : __DIR__"huazhen2",
		"north" : __FILE__,
		"south" : __FILE__,
		"east" : __FILE__,
        ]));

        setup();
        replace_program(ROOM);
}

int valid_leave(object me, string dir)
{
        int gin_cost;
        me=this_player();
        gin_cost=(-1) * ( me->query("max_gin") ) / 20 ;
        return ::valid_leave(me, dir);
}
