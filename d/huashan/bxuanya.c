// /d/huashan/bxuenya.c

#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", "悬崖");
        set("long", @LONG
你来到一个很高的悬崖上，这里安静的很，似乎很多年没有
人来过这里。你试着向悬崖下面看，突然一阵劲风吹了上来，吓
的你打了个冷战：你竟然看不见崖底！从这里向南是陡峭的山路。
LONG
        );
        
        set("exits", ([
                "southdown" : __DIR__"bsroad2",
        ]));

        set("outdoors","huashan");

        setup();
}

int init()
{
        add_action("do_tiao","tiao");
}

int do_tiao(string arg)
{
         object me;
         me = this_player();
         if ( arg =="shan" || arg =="shanya" || 
              arg =="xuanya" || arg =="ya" )
            {
            if (me->query_temp("tiao_xuanya")>3)
               {
               me->delete_temp("tiao_xuanya");
               // 玩家死亡 grin
               me->die();
               return 1;
               }

            if ( (me->query("combat_exp") < 2000000) ||
                (me->query_skill("dodge", 1) < 200) )
               {
               if (!me->query_temp("tiao_xuanya"))
                  me->set_temp("tiao_xuanya", 1);
               else
                  me->set_temp("tiao_xuanya", me->query_temp("tiao_xuanya")+1);
               return notify_fail("想跳悬崖，不要命了？\n");
               }
         else
           {
             tell_object(me, "你运足了内力，跳下了悬崖。\n");
            tell_object(me, "不知过了多久，你慢慢见到了崖底……\n");
             me->unconcious();
             me->move(__DIR__"m_down");
             return 1;
           }
            }
         else
            {
           return 0;
            }
        
         return 1;
 
}


