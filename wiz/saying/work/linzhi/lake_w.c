//lake_w.c 巴松措湖西岸。
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short","巴松措湖岸");
        set("long", @LONG
工巴寺外，是一片湖光山色。四周春花烂漫，雪峰阵列，倒
影湖中，枫林环绕，恰如世外仙境。工巴寺外是藏族人民心目中
的圣湖，巴松措湖。放眼从湖面上看去，远处水气弥漫，看不出
有什么东西。
LONG
);
        set("exits",([
        "west":__DIR__"temple1",
]));
        setup();
}
void init()
{
        add_action("do_swim","swim");
}
int do_swim(string arg)
{
        object me;
        int busy;
        me=this_player();
        if (!arg)
        return notify_fail("你要往哪里游？\n");
        if (arg=="湖"||arg=="lake") 
        {
        write("你一头钻进湖水中，好舒畅啊.......\n");
        message("vision",me->name()+"一头钻进湖水中，转眼间就不见了.......\n",environment(me),({me}));
        me->move(__DIR__"lakevoid");
        call_out("to_maple",(busy=3+random(3)),me);
        me->start_busy(busy);
        return 1;
        }
}
void to_maple(object me)
{
        me=this_player();
        write("你游了半天，终于到了对岸。\n");
        me->move(__DIR__"lake_e");
        message("vision",me->name()+"从湖里游了上来，累得半死。\n",environment(me),({me}));
        me->stop_busy();
}
