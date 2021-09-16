// /d/huashan/xianshi_tomb.c

#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", HIC"先师陵园"NOR);
        set("long", @LONG
这里是华山历代师傅的陵墓，墓地肃穆庄严，但是似乎有一
股血腥的味道。墓碑上有一些文字，似乎可以参阅(canyue)。从
这里向西是禁地大门，向东是一幢漆黑的铁宅。
LONG
        );
        
        set("exits", ([
                "west" : __DIR__"jindi_gate",
                "east" : __DIR__"tiezhai",
        ]));

        set("outdoors","huashan");

        setup();
}

int init()
{
        add_action("do_canyue","canyue");
}

int do_canyue(string arg)
{
         object me;
         me = this_player();
         if ( arg =="文字")
            {
            write("你看着墓碑上的文字，深有感悟，对自己过去所犯的错误感到懊悔不已。\n");
            if( me->query("bellicosity") > 0 )
                 {
                 me->add("bellicosity", - to_int( random(me->query("kar")+50)+60 ));
                 }
            if( me->query("bellicosity") < 100 )
                 me->set("bellicosity", 100);
            me->start_busy(1);
            }
         else if ( arg =="墓碑")
            {
            write("你仔细看着墓碑上的，竟然发现墓碑缝隙中有鲜血写的文字！\n");
            if( me->query("bellicosity") < me->query("cor")*100 )
                 {
                 me->add("bellicosity", to_int( random(me->query("kar")+50)+60 ));
                 }
            me->start_busy(3);
            }
         else
            {
            return notify_fail("你要参阅什么？\n");
            }
        
         return 1;
 
}


