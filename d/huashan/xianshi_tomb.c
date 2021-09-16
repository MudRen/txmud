// /d/huashan/xianshi_tomb.c

#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", HIC"��ʦ��԰"NOR);
        set("long", @LONG
�����ǻ�ɽ����ʦ������Ĺ��Ĺ������ׯ�ϣ������ƺ���һ
��Ѫ�ȵ�ζ����Ĺ������һЩ���֣��ƺ����Բ���(canyue)����
���������ǽ��ش��ţ�����һ����ڵ���լ��
LONG
        );
        
        set("exits", ([
                "west" : __DIR__"jindi_gate",
                "east" : __DIR__"tiezhai",
        ]));

        set("outdoors","huashan");

        setup();
}

int init()
{
        add_action("do_canyue","canyue");
}

int do_canyue(string arg)
{
         object me;
         me = this_player();
         if ( arg =="����")
            {
            write("�㿴��Ĺ���ϵ����֣����и��򣬶��Լ���ȥ�����Ĵ���е��ûڲ��ѡ�\n");
            if( me->query("bellicosity") > 0 )
                 {
                 me->add("bellicosity", - to_int( random(me->query("kar")+50)+60 ));
                 }
            if( me->query("bellicosity") < 100 )
                 me->set("bellicosity", 100);
            me->start_busy(1);
            }
         else if ( arg =="Ĺ��")
            {
            write("����ϸ����Ĺ���ϵģ���Ȼ����Ĺ����϶������Ѫд�����֣�\n");
            if( me->query("bellicosity") < me->query("cor")*100 )
                 {
                 me->add("bellicosity", to_int( random(me->query("kar")+50)+60 ));
                 }
            me->start_busy(3);
            }
         else
            {
            return notify_fail("��Ҫ����ʲô��\n");
            }
        
         return 1;
 
}


