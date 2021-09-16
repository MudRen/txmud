// xiuyunfang.c
// by dicky

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
         set("short","���Ʒ�");
         set("long",@long
������̤ѩɽׯ�����Ʒ��������������ɴ֯���ĵط���Ѿ�ߺ��Ů
�����������ɵĸ��Ż�е��ڷ�ɴ���е���֯����Ҳ�е��ڴ��壬����
һ�߹�����һ�������ճ������е�С�£���ʱ���ĵ����ˣ����ᷢ������
��Ц���������﹤�������ǵ������������ô����⡣��Ȼ����Ҳ������
�����������飬˳��ѧ�����߻
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
             return notify_fail("��û�н����æ����������Ϲæ��ʲô�� \n");
        if(me->is_busy())
             return notify_fail("��������æ���أ�\n");
        if(me->is_fighting())
             return notify_fail("������ս����,�޷�ר�ĸɻ\n");
        if( !arg || arg != "hua" )
             return notify_fail("��Ҫ��ʲô���������Ͳ�Ҫ���ܣ�\n");

        costj = random((int)me->query("con")/3);
        costq = random((int)me->query("str")/3);

        if((int)me->query("gin") < costj 
         ||(int)me->query("kee") < costq){
          message_vision(HIR"$NͻȻ�о�����ͷ�Σ������ǲ��͹����ˡ�\n"NOR,me);
          me->unconcious();
          return 1;
        }        
        me->receive_damage("gin", costj);
        me->add("kee", -costq);
        if((int)me->query_temp("taxue/xiuhua") > 5 + random(5)){
        me->set_temp("taxue/xiuhua_over",1);
        write(RED "����˵���ã�����־��Ѿ�����ˣ���������������(task ok)�ˣ�\n"NOR);
          return 1;
        }  
        write("�������廨�룬�������ָ���£�������ʼ��һֻ�־������廨��\n");
        me->add_temp("taxue/xiuhua",1);
        me->start_busy(1);
        return 1;
}
