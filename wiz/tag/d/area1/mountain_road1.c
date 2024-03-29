///////////////////////////////////////////////////
//新的区域area1
//mountain_road1.c

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "高地");
        set("long", @LONG
你身处高地，四下张望。西南方是一片繁茂的森林。
东边一片开阔地，但有些小丘陵挡住你的视线，看不到远
处。北方有座山，相当险峻，看来不爬是上不去了。
LONG
        );
        set("exits", ([
        "southdown"   :  __DIR__"forest_road5",
        ]));
        set("outdoors", "area1");
        
        setup();
}

int init()
{
        add_action("do_climb", "climb");
        add_action("do_climb", "爬");
}

int do_climb(string arg)
{
        object me;
        me = this_player();
        if( !arg || arg != "shan" && arg != "山")
        {
                tell_object(me, "你四处看看，不知道要爬什么。\n");
        }
        if ( arg =="shan" || arg =="山")
        {
                message_vision(HIB"$N提了口气，手攀山岩，爬上了半山腰。\n"NOR, me);
                me->start_busy(2+random(2));
                me->move(__DIR__"mountain_road0");
                remove_call_out("climb_shan");
                call_out("climb_shan", 1, me);
        }
        return 1;
}

void climb_shan(object me)
{
        if((int)me->query("combat_exp")>=6400000 && (int)me->query("kee")>=100 && (int)me->query("sen")>=100)
        {
                me->move(__DIR__"mountain_top");
                tell_object(me, HIY"你费了好大的劲，最终来到了山顶上。\n"NOR);
                message("vision", HIY""+me->name()+"一个腾跃，翻上了山顶。\n"NOR, environment(me), me);
                me->add("kee", -50);
                me->add("sen", -50);
        }
        else
        {
                tell_object(me, HIR"你正爬到半山，突然手一软没有抓住石头，直挺挺地就摔了下去！\n"NOR);
                me->move(__DIR__"mountain_road1");
                message("vision", HIR""+me->name()+"一个不小心，从山上摔了下来。\n"NOR, environment(me), me);
                me->unconcious();
        }
}
///////////////////////////////////////////////////
