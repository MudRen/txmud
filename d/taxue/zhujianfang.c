// zhuajianfang.c
// by dicky

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
	set("short","������");
        set("long",@LONG
�������̤ѩɽׯ���������ˣ�����ʦ��̤ѩ��Զ���ĵ���̤ѩ�Ժ�����
������������������˵��������������ռȺã�����Ͷ࣬�������æ����
����һ�߰��������͸�����ͭ��������һ�߰����˸�ʽ���õĽ����������ֲ�
������������ɽׯ�����ĵ����������æ��
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
             return notify_fail("��û�н����æ����������Ϲæ��ʲô�� \n");
        if(me->is_busy())
             return notify_fail("��������æ���أ�\n");
        if(me->is_fighting())
             return notify_fail("������ս����,�޷�ר�ĸɻ\n");
        if( !arg || arg != "jian" )
             return notify_fail("��Ҫ����ʲô���������Ͳ�Ҫ���ܣ�\n");

        costj = random((int)me->query("con")/3);
        costq = random((int)me->query("str")/3);

        if((int)me->query("gin") < costj 
         ||(int)me->query("kee") < costq){
          message_vision(HIR"$N��һ�ɣ�������С�������Լ��Ľ��ϡ�\n"NOR,me);
          me->unconcious();
          return 1;
        }        
        me->receive_damage("gin", costj);
        me->add("kee", -costq);
        if(((int)me->query_temp("taxue/zhujian") > 5 + random(5))){
        me->set_temp("taxue/zhujian_over",1);
        write(RED "̤ѩ�Ժ�˵���ã����������ɣ���������������(task ok)�ˣ�\n"NOR);
          return 1;
        }  
        write("����������������յ�ͨ���������ȥ�����Ǳ������Ĵ���ɢ��\n");
        me->add_temp("taxue/zhujian",1);
        me->start_busy(1);
        return 1;
}
