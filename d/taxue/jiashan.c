// houhuayuan.c
// by dicky

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
	set("short","假山");
	set ("long",@long
这是一座花园旁边的假山，假山旁边种满了山茶花，巨石参杂在山茶花
中，此所谓: “千呼万唤始出来, 犹报琵琶半遮面”更增姿媚。 抬头望去, 
只见一根古藤（teng）蜒伸在花园墙上。一股清泉从假山上涌出，尝一口沁
人心脾。
long);
         set("resource/water", 1);

         set("exits",([

             "northeast" : __DIR__"huayuan",
	]));

        set("objects", ([
                __DIR__"npc/dizi7" : 1,
        ]));

         set("item_desc",([
             "teng" : "一条顺着墙壁攀延而上的绿树藤。\n"
	]));
	setup();
}
/*
int init()
{
	add_action("do_pa","pa");
}
                
int do_pa(string arg)
{
         object me;
         me = this_player();
         if (arg != "teng")
         return notify_fail("你要做什么？\n");
         if ( arg =="teng")
         { 
         write("你沿着大树藤爬了上去。\n");
         message("vision",
         me->name() + "沿着大树藤爬了上去。\n",
                     environment(me), ({me}) );
         me->move(__DIR__"shuteng");
         message("vision",
                  me->name() + "从沿着树藤爬了上来。\n",
                             environment(me), ({me}) );
                }
                return 1;
}
*/     