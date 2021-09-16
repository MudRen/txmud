///////////////////////////////////////////////////
//�µ�����area1
//mountain_road1.c

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "�ߵ�");
        set("long", @LONG
�����ߵأ��������������Ϸ���һƬ��ï��ɭ�֡�
����һƬ�����أ�����ЩС���굲ס������ߣ�������Զ
������������ɽ���൱�վ��������������ϲ�ȥ�ˡ�
LONG
        );
        set("exits", ([
        "southdown"   :  __DIR__"forest_road5",
        ]));
        set("outdoors", "area1");
        
        setup();
}

int init()
{
        add_action("do_climb", "climb");
        add_action("do_climb", "��");
}

int do_climb(string arg)
{
        object me;
        me = this_player();
        if( !arg || arg != "shan" && arg != "ɽ")
        {
                tell_object(me, "���Ĵ���������֪��Ҫ��ʲô��\n");
        }
        if ( arg =="shan" || arg =="ɽ")
        {
                message_vision(HIB"$N���˿���������ɽ�ң������˰�ɽ����\n"NOR, me);
                me->start_busy(2+random(2));
                me->move(__DIR__"mountain_road0");
                remove_call_out("climb_shan");
                call_out("climb_shan", 1, me);
        }
        return 1;
}

void climb_shan(object me)
{
        if((int)me->query("combat_exp")>=6400000 && (int)me->query("kee")>=100 && (int)me->query("sen")>=100)
        {
                me->move(__DIR__"mountain_top");
                tell_object(me, HIY"����˺ô�ľ�������������ɽ���ϡ�\n"NOR);
                message("vision", HIY""+me->name()+"һ����Ծ��������ɽ����\n"NOR, environment(me), me);
                me->add("kee", -50);
                me->add("sen", -50);
        }
        else
        {
                tell_object(me, HIR"����������ɽ��ͻȻ��һ��û��ץסʯͷ��ֱͦͦ�ؾ�ˤ����ȥ��\n"NOR);
                me->move(__DIR__"mountain_road1");
                message("vision", HIR""+me->name()+"һ����С�ģ���ɽ��ˤ��������\n"NOR, environment(me), me);
                me->unconcious();
        }
}
///////////////////////////////////////////////////
