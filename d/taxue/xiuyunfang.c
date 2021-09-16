// xiuyunfang.c
// by dicky

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
         set("short","绣云房");
         set("long",@long
这里是踏雪山庄的绣云房，里面是云娘纺纱织布的地方，丫鬟和婢女
们在这里轻松的干着活，有的在纺纱，有的在织布，也有的在刺绣，她们
一边工作，一边聊着日常生活中的小事，有时候聊到高兴，都会发出酣畅
的笑声，在这里工作，她们的生活过得是那么的惬意。当然，你也可以来
帮她们做事情，顺便学点针线活。
long);
         set("exits",([
             "south" : __DIR__"zoulang3",
	]));
         set("objects",([
             __DIR__"npc/yunniang" : 1,
	]));
         setup();
         replace_program(ROOM);
}

void init()
{
        add_action("do_xiu", "xiu");
}

int do_xiu(string arg)
{       
        object me;
        int costj, costq;
        me = this_player();

        if(!me->query_temp("taxue/job_xiuhua")) 
             return notify_fail("我没有叫你帮忙，你在这里瞎忙乎什么？ \n");
        if(me->is_busy())
             return notify_fail("你现在正忙着呢！\n");
        if(me->is_fighting())
             return notify_fail("你正在战斗中,无法专心干活！\n");
        if( !arg || arg != "hua" )
             return notify_fail("你要绣什么，不会做就不要承能！\n");

        costj = random((int)me->query("con")/3);
        costq = random((int)me->query("str")/3);

        if((int)me->query("gin") < costj 
         ||(int)me->query("kee") < costq){
          message_vision(HIR"$N突然感觉阵阵头晕，看来是操劳过度了。\n"NOR,me);
          me->unconcious();
          return 1;
        }        
        me->receive_damage("gin", costj);
        me->add("kee", -costq);
        if((int)me->query_temp("taxue/xiuhua") > 5 + random(5)){
        me->set_temp("taxue/xiuhua_over",1);
        write(RED "云娘说：好，这块手绢已经绣好了，你可以完成任务了(task ok)了！\n"NOR);
          return 1;
        }  
        write("你拿起绣花针，在云娘的指导下，慢慢开始在一只手绢上面绣花。\n");
        me->add_temp("taxue/xiuhua",1);
        me->start_busy(1);
        return 1;
}
