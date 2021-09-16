// zhuajianfang.c
// by dicky

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
	set("short","铸剑房");
        set("long",@LONG
这里就是踏雪山庄的铸剑房了，铸剑师是踏雪靖远的四弟子踏雪苍海，他
打出来的铁器往往比人的寿命还长，手艺既好，活儿就多，天天从早忙到晚。
屋子一边摆着生铁和各种破铜乱铁，另一边摆满了各式做好的剑。由于人手不
够，他经常找山庄其他的弟子来这里帮忙。
LONG);

	set("exits",([
		"east"  : __DIR__"houyuan",
	]));

        set("objects", ([
                __DIR__"npc/dizi4" : 1,
        ]));

	setup();
}


void init()
{
        add_action("do_zhu", "zhu");      
}

int do_zhu(string arg)
{       
        object me;
        int costj, costq;
        me = this_player();
        if(!me->query_temp("taxue/job_zhujian")) 
             return notify_fail("我没有叫你帮忙，你在这里瞎忙乎什么？ \n");
        if(me->is_busy())
             return notify_fail("你现在正忙着呢！\n");
        if(me->is_fighting())
             return notify_fail("你正在战斗中,无法专心干活！\n");
        if( !arg || arg != "jian" )
             return notify_fail("你要铸造什么，不会做就不要承能！\n");

        costj = random((int)me->query("con")/3);
        costq = random((int)me->query("str")/3);

        if((int)me->query("gin") < costj 
         ||(int)me->query("kee") < costq){
          message_vision(HIR"$N手一松，铁锤不小心砸在自己的脚上。\n"NOR,me);
          me->unconcious();
          return 1;
        }        
        me->receive_damage("gin", costj);
        me->add("kee", -costq);
        if(((int)me->query_temp("taxue/zhujian") > 5 + random(5))){
        me->set_temp("taxue/zhujian_over",1);
        write(RED "踏雪苍海说：好，不错，剑铸成，你可以完成任务了(task ok)了！\n"NOR);
          return 1;
        }  
        write("你挥起铁锤，对着烧得通红的铁剑砸去，火星被溅得四处飞散。\n");
        me->add_temp("taxue/zhujian",1);
        me->start_busy(1);
        return 1;
}
