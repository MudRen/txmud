// /d/huashan/bxuenya.c

#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
������һ���ܸߵ������ϣ����ﰲ���ĺܣ��ƺ��ܶ���û��
������������������������濴��ͻȻһ�󾢷紵����������
������˸���ս���㾹Ȼ�������µף������������Ƕ��͵�ɽ·��
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
               // ������� grin
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
               return notify_fail("�������£���Ҫ���ˣ�\n");
               }
         else
           {
             tell_object(me, "�����������������������¡�\n");
            tell_object(me, "��֪���˶�ã��������������µס���\n");
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


