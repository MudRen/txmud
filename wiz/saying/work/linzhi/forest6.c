//forest6.c 青藏高原通向中原的原始森林迷宫。
inherit ROOM;
void create()
{
        set("short","原始森林");
        set("long", @LONG
走在原始森林中，只见各种树木遮天蔽日。刚经过单调高原
景色的你开始还欣赏满目的绿色，渐渐的也厌烦起来，耳朵里也
充满了安静的声音，你甚至怀疑是不是只有自己一个人在，看着
千篇一律的树木，你只想赶快走出去。
LONG
        );
        set("exits", ([
        "east":__DIR__"forest4",
        "west":__DIR__"forest4",
        "south":__DIR__"forest7",
        "north":__DIR__"forest7",
]));
        setup();
}
int valid_leave(object me, string dir)
{
        if ( dir == "north"||dir == "south"||dir == "east"||dir == "west"||dir == "saying")
            me->add_temp("forest/steps",1);
        if (me->query_temp("forest/steps") >70)
         {
                me->delete_temp("forest/steps");
                if (random(10)>7||(int)me->query_temp("mark/圣树"))
                me->move(__DIR__"forest_c");
                return notify_fail("\n");
         }  
        return ::valid_leave(me,dir);
}
