//lake_e.c 巴松措湖东岸。
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short","巴松措湖岸");
        set("long", @LONG
枫树林外，是一片湖光山色。四周春花烂漫，雪峰阵列，倒
影湖中，枫林环绕，恰如世外仙境。原来这就是藏族人民心目中
的圣湖，巴松措湖。只是从湖面上看去，远处水气弥漫，看不出
有什么东西，似乎有细微的梵唱之声，你仔细听听，找不到声音
的来源，可能是天籁吧。
LONG
);
        set("exits",([
]));
        setup();
}
void show_secret(string msg,object user)
{
        if (!msg||!user)
        return;
        if (msg=="begin_night")
        {
        tell_object(user,HIW"夜色降临了，你忽然发现湖中心闪着几星灯光。\n"NOR,);
        }
        return;
}
void init()
{
        add_action("do_pass","pass");
        add_action("do_swim","swim");
}
int do_pass(string arg)
{
        object me;
        me=this_player();
        if (!arg)
        return notify_fail("你要穿越哪里？\n");
        if (arg=="枫树林"||arg=="maple") {
        if (me->query_temp("mark/枫树林")) {
        write("你一头钻进枫树林.......\n");
        message("vision",me->name()+"一头钻进枫树林，转眼间就不见了.......\n",environment(me),

({me}));
        me->move(__DIR__"maple_e");
        message("vision",me->name()+"走了过来。\n",environment(me),({me}));
         return 1;
}
        else return notify_fail("你看了半天，不得其门而入。\n");
        }
}
int do_swim(string arg)
{
        object me;
        int busy;
        me=this_player();
        if (!arg)
        return notify_fail("你要往哪里游？\n");
        if (arg=="湖"||arg=="lake") {
        if (!is_day()) {
        write("你一头钻进湖水中，好舒畅啊.......\n");
        message("vision",me->name()+"一头钻进湖水中，转眼间就不见了.......\n",environment(me),

({me}));
        me->move(__DIR__"lakevoid");
        call_out("to_temple",(busy=3+random(3)),me);
        me->start_busy(busy);
        return 1;
}
        else return notify_fail("没事瞎往湖里跳干什么？不想活啦？！\n");
        }
}
void to_temple(object me)
{
        me=this_player();
        write("你游了半天，终于到了对岸。\n");
        me->move(__DIR__"lake_w");
        message("vision",me->name()+"从湖里游了上来，累得半死。\n",environment(me),({me}));
        me->stop_busy();
}
