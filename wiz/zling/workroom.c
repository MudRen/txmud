// workroom.c

#include <ansi.h>

inherit ROOM;

void create ()
{
    set ("short", "�����ǵ�С��");
    set("long", "���ؼҿ������ؼҿ�����\n");
    set("objects",([
        __DIR__"npc/test" : 1,
    ]));

  set("exits", ([ /* sizeof() == 1 */
   "down" : __DIR__"txmap",
]));

  setup();
}

void init()
{
        mixed *local;
        int  t;
        local = localtime(time()*60);
        t = local[2] * 60 + local[1];       
        add_action("do_look", "look");
}

/*
30-260        ��ҹ
260-510       ����
510-630       �糿
630-810       ����
810-990       ����
990-1170      ����
1170-1360     ����
1360-�ڶ���30 ҹ��
*/

int do_look()
{
        mixed *local;
        int  t;
        local = localtime(time()*60);
        t = local[2] * 60 + local[1];
      
        if( t > 30 && t < 510)
        {
                set("long", HIY"������û��˯���������ǿɿ�ʼ�����ˡ��������ʱ��������϶���������\n"NOR);
        }
        if( t > 510 && t < 630)
        {
                set("long", HIY"�����Ѿ��ϰ��ˣ�Ӧ�ÿ��Կ����������ˣ��пմ�Ҷ�����������\n"NOR);
        }
        if( t < 810 && t > 630)
        {
                set("long", HIW"���緹�ˣ�������û�г���ȥ�԰ɡ�\n"NOR);
        }
        if( t < 990 && t > 810)
        {
                set("long", HIG"��������������į��ʱ���Լ�һ�������ϲ��Է�����......\n"NOR);
        }
        if( t < 1360 && t > 990)
        {
                set("long", HIR"û������,ֻ��cs,vb delphi sql ������......\n"NOR);
        }
        if( t < 30 || t > 1360)
        {
                set("long", BLU"ҹ���˾��ˣ�������ֽ��˯���ˡ�\n"NOR);
        }
}
int valid_leave(object me,string dir)
{
        if(!me)
                return 0;

if(dir == "down" || dir == "d")
        {
                if(sizeof(filter_array(deep_inventory(me),(: $1->is_jinghai_book() :))))
                        return notify_fail("����������ס��˵��������կ��֮�������ɵ伮����Я���鷿����\n");
        }

        return ::valid_leave(me,dir);
}

