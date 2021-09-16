// dc_dan.c 

#include <ansi.h>

inherit ITEM;

int do_eat(string arg);
void poi_myself(object me);

void create()
{
        set_name(HIC+"�ϳ�����"+NOR, ({"duanchang dan", "dan", "dc"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", BLU"
    ����һ��������������������û����ɵ��鵤��"+HIB+"
�鵤��Ө��͸���������⣬��ʯ��֮���Ҳ����Ȼ"+HIC+"
ʧɫ����˵���˴˵����������������Ƕ���������"+HIC+"
ʿ����������䱦�������鵤Ҳ����������Ѫ�е�"+HIB+"
�綾����˶���ʮ�����ң�û�м�ʮ��Ĺ���֧�֣�"+NOR+BLU+"
�������»ᵱ���ж�������ǧ�����ء�            \n"+NOR);
                set("value", 0);
        }
        setup();
}

void init()
{
        add_action("do_eat", "eat");
}

int do_eat(string arg)
{
        int t;

        object me = this_player();

        if (!id(arg))
        return notify_fail("��Ҫ��ʲô��\n");

    // �������ʱ�䣬24Сʱ����һ��
    if (me->query("dc_dan_delay")>0)
        {
       t=time() - me->query("dc_dan_delay")+1;
           if (t<3600*24)
           {
                   tell_object(me, HIR"
�㽫�ϳ�����������ȥ��ֻ���øγ���ϣ������գ������
��ǰ���ڵľ綾��û��ɢȥ����\n"NOR);
           me->start_busy(2);
                   call_out("poi_myself",2,me);
                   return 1;
           }
        }

        if ( (int)me->query("max_force",1) < 1000 )
        {
           tell_object(me, "���������������¶���ס�ϳ��������ǲ�Ҫ�Եĺá�\n");
           return 1;
        }
        else
        {
                me->add("max_force", 10);
                me->add("force", 100);
                me->set("dc_dan_delay",time());

                message_vision(HIC "$N����һ�Ŷϳ����񵤣�һ������˲ʱ�߱�ȫ�������ޱȣ�\n" NOR, this_player());
        }

        me->start_busy(5);
        destruct(this_object());
        return 1;
}

void poi_myself(object me)
{
        if (random(me->query("kar",1)) < 15)
        {
                message_vision(HIR"\n$NͻȻ�о������籬��һ�����ܣ�������Ѫ�����ڵ�������һϢ��\n"NOR, me);
                me->die();
        }
        else
        {
                message_vision(HIR"$N�о������ʹ����Ҫʧȥֻ�������ǲ�֪��ʲô��������ֹס����ʹ��\n"NOR, me);
                me->start_busy(5);
        }
    destruct(this_object());
}


