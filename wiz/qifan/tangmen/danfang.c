//danfang.c by qifan

#include <ansi.h>
#include <room.h>
inherit ROOM;

int do_liandan();
int do_stop();

void create()
{
    set("short", "��ҩ��");
    set("long", @LONG

�������һ����ҩ¯��ʲôҲû�У�����������������һ�ֵ�ҩζ��

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
        
        // ����˵��:yxld==��������
        //          nlcs==��������
        //          ldcs==��������
        //          ldwp==������Ʒ����,Ŀǰ��2000 4000
        
        if(!me->query_temp("yxld"))
                    return notify_fail("��ԭ�϶�û��ҩͯ����ô����\n");
        if(me->is_busy()) 
                   return notify_fail("��������æ���أ�\n");
        if(me->query("kee")<20||me->query("sen")<20)
                   return notify_fail("�㻹������Ϣһ�°ɣ������ܺ���Ѫ�;����Ŷ��\n");
                
         kar = me->query("kar")*2;
        if (!me->query_temp("nlcs")) me->set_temp("nlcs",random(kar)/5);
                
        me->start_busy(3+random(4));
        message_vision(MAG"$N�Ķ����������Լ����������л���һ���������¯��\n"NOR, me);
       
        me->receive_damage("kee",random(5));
        me->receive_damage("sen",random(10));

        if (random(kar)>3)
            {
            if( me->query_temp("ldcs")>=me->query_temp("nlcs"))
                {
		
		kar=random(7);// ��ʡ����, ���ᳫ���� :P
me->set_temp("ldcs",(int)me->query_temp("ldcs")/2);
		if(kar==0)
		    {
                message_vision(HIR"¯��Ļ��͵�һ����������һ�ŵ�ҩ!\n"NOR,me);
 	        message_vision(CYN"$Nϲ������,����ʱ�������ͷ��\n"NOR,me);
	        new(__DIR__"obj/danyao")->move(me);
                destruct(this_object());
                me->start_busy(1);
                    }
    		else if(kar==1)
    		    {
                message_vision(HIR"¯��Ļ��͵�һ����������һ�ŵ�ҩ!\n"NOR,me);
 	        message_vision(CYN"$Nϲ������,����ʱ�������ͷ��\n"NOR,me);
	        new(__DIR__"obj/danyao")->move(me);
                destruct(this_object());
                me->start_busy(1);
                   }
                else if(kar==2) 
                   {    
                message_vision(HIR"¯��Ļ��͵�һ����������һ�ŵ�ҩ!\n"NOR,me);
 	        message_vision(CYN"$Nϲ������,����ʱ�������ͷ��\n"NOR,me);
	        new(__DIR__"obj/danyao")->move(me);
                destruct(this_object());
                me->start_busy(1);
                   }   
    		else 
    		   {   
                message_vision(HIR"¯��Ļ��͵�һ����������һ�ŵ�ҩ!\n"NOR,me);
 	        message_vision(CYN"$Nϲ������,����ʱ�������ͷ��\n"NOR,me);
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
    	        message_vision(HIR"ֻ��¯��Ļ�����ˡ�����\n"NOR,me);
    	        me->add_temp("ldcs",1);
    	        return 1;
    	         }
    	  }
        else 
           	{
                me->receive_wound("kee", random(10));  
                me->receive_wound("sen",random(15));
                message_vision(RED"$N�й�ʱͻȻ�߻���ħ��������Ѫ�Ե��ڵء�\n"NOR,me );
                me->add_temp("ldcs",1);
     		me->unconcious();
     		 return 1;
     		}
}

int do_stop()
{
object me=this_player();
if (!me->query_temp("yxld")) return notify_fail ("�㲢û����������������ֹ��\n");
me->delete_temp("yxld");
me->delete_temp("ldcs");
me->delete_temp("ldwp");
me->delete_temp("nlcs");
message_vision("$N˼ǰ���,��ֹ��������\n",me );
return 1;
}

int valid_leave(object me, string dir)
{       
        
        if (dir == "up" && me->query_temp("yxld") ) {
               
                return notify_fail("Сҩͯ����˵�������굤���߰ɣ�\n");
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
                      {  tell_object(me,"Сҩͯ����ҡ��ҡͷ��\n");
                         return 1;
                      }
            }
        
        else {
                env = present(arg, environment(me));
 if(!env) return 0;
                if(env->is_character() && !living(env))
                      {  tell_object(me,"Сҩͯ����ҡ��ҡͷ��\n");
                         return 1;
                      }
             }
                        
        return 0;
}               