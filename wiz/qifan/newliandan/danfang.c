//danfang.c by qifan

#include <ansi.h>
#include <room.h>
inherit ROOM;

int do_liandan();
int do_stop();

void create()
{
    set("short", "炼药房");
    set("long", @LONG

这里除了一个大药炉外什么也没有，整个房间里弥漫着一种丹药味。

LONG );

set("exits", ([
         "west" : __DIR__"yz_xiaoyuan",
    ]));

set("objects", ([
                __DIR__"obj/yaotong": 1,
                __DIR__"obj/yaolu": 1,
                 ]) );
     setup();
}

int init()
{
        add_action("do_liandan","liandan"); 
        add_action("do_stop","stop");
        add_action("do_get","get");
}

int do_liandan()
{       int kar;
        string str;
        object me = this_player();
        
        // 变量说明:yxld==允许炼丹
        //          nlcs==能炼次数
        //          ldcs==能炼次数
        //          ldwp==炼丹物品参数,目前分2000 4000
        
        if(!me->query_temp("yxld"))
                    return notify_fail("你原料都没给药童，怎么炼？\n");
        if(me->is_busy()) 
                   return notify_fail("你现在正忙着呢！\n");
        if(me->query("kee")<20||me->query("sen")<20)
                   return notify_fail("你还是先休息一下吧，炼丹很耗气血和精神的哦。\n");
                
         kar = me->query("kar")*2;
        if (!me->query_temp("nlcs")) me->set_temp("nlcs",random(kar)/5);
                
        me->start_busy(3+random(4));
        message_vision(MAG"$N鼓动真气，把自己毕生的修行化做一团真火喷向丹炉。\n"NOR, me);
       
        me->receive_damage("kee",random(5));
        me->receive_damage("sen",random(10));

        if (random(kar)>3)
            {
            if( me->query_temp("ldcs")>=me->query_temp("nlcs"))
                {
		
		kar=random(7);// 节省变量, 不提倡这样 :P
me->set_temp("ldcs",(int)me->query_temp("ldcs")/2);
		if(kar==0)
		    {
                message_vision(HIR"炉里的火猛的一跳，炼出来一颗丹药!\n"NOR,me);
 	        message_vision(CYN"$N喜出望外,跳起时差点碰了头。\n"NOR,me);
	        new(__DIR__"obj/danyao")->move(me);
                destruct(this_object());
                me->start_busy(1);
                    }
    		else if(kar==1)
    		    {
                message_vision(HIR"炉里的火猛的一跳，炼出来一颗丹药!\n"NOR,me);
 	        message_vision(CYN"$N喜出望外,跳起时差点碰了头。\n"NOR,me);
	        new(__DIR__"obj/danyao")->move(me);
                destruct(this_object());
                me->start_busy(1);
                   }
                else if(kar==2) 
                   {    
                message_vision(HIR"炉里的火猛的一跳，炼出来一颗丹药!\n"NOR,me);
 	        message_vision(CYN"$N喜出望外,跳起时差点碰了头。\n"NOR,me);
	        new(__DIR__"obj/danyao")->move(me);
                destruct(this_object());
                me->start_busy(1);
                   }   
    		else 
    		   {   
                message_vision(HIR"炉里的火猛的一跳，炼出来一颗丹药!\n"NOR,me);
 	        message_vision(CYN"$N喜出望外,跳起时差点碰了头。\n"NOR,me);
	        new(__DIR__"obj/danyao")->move(me);
                destruct(this_object());
                me->start_busy(1);
                   }
       
  	        me->delete_temp("yxld");
		me->delete_temp("ldcs");
		me->delete_temp("nlcs");
		me->delete_temp("ldwp");
                      log_file("liandan",sprintf("%s(%s)(%s)\n",
				geteuid(me),str,ctime(time()) ) );
    	        return 1;
    	       }
    	    else {
    	        message_vision(HIR"只见炉里的火更旺了。。。\n"NOR,me);
    	        me->add_temp("ldcs",1);
    	        return 1;
    	         }
    	  }
        else 
           	{
                me->receive_wound("kee", random(10));  
                me->receive_wound("sen",random(15));
                message_vision(RED"$N行功时突然走火入魔，口喷鲜血栽倒在地。\n"NOR,me );
                me->add_temp("ldcs",1);
     		me->unconcious();
     		 return 1;
     		}
}

int do_stop()
{
object me=this_player();
if (!me->query_temp("yxld")) return notify_fail ("你并没有在炼丹，无需中止。\n");
me->delete_temp("yxld");
me->delete_temp("ldcs");
me->delete_temp("ldwp");
me->delete_temp("nlcs");
message_vision("$N思前想后,中止了炼丹。\n",me );
return 1;
}

int valid_leave(object me, string dir)
{       
        
        if (dir == "up" && me->query_temp("yxld") ) {
               
                return notify_fail("小药童对你说到：炼完丹再走吧！\n");
        return ::valid_leave(me, dir);
        }
        return 1;
}

int do_get(string arg)
{
        string from;
        object me = this_player();
        object env;
        
        if( !arg ) return 0;
                
        if( sscanf(arg, "%s from %s", arg, from)==2 )
            {
                env = present(from, me);
                if(!env) env = present(from, environment(me));
                if(!env) return 0;
                if(env->is_character() && !living(env))
                      {  tell_object(me,"小药童对你摇了摇头。\n");
                         return 1;
                      }
            }
        
        else {
                env = present(arg, environment(me));
 if(!env) return 0;
                if(env->is_character() && !living(env))
                      {  tell_object(me,"小药童对你摇了摇头。\n");
                         return 1;
                      }
             }
                        
        return 0;
}               