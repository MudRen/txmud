//lake_w.c ���ɴ��������
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short","���ɴ����");
        set("long", @LONG
�������⣬��һƬ����ɽɫ�����ܴ���������ѩ�����У���
Ӱ���У����ֻ��ƣ�ǡ�������ɾ������������ǲ���������Ŀ��
��ʥ�������ɴ�������۴Ӻ����Ͽ�ȥ��Զ��ˮ��������������
��ʲô������
LONG
);
        set("exits",([
        "west":__DIR__"temple1",
]));
        setup();
}
void init()
{
        add_action("do_swim","swim");
}
int do_swim(string arg)
{
        object me;
        int busy;
        me=this_player();
        if (!arg)
        return notify_fail("��Ҫ�������Σ�\n");
        if (arg=="��"||arg=="lake") 
        {
        write("��һͷ�����ˮ�У����泩��.......\n");
        message("vision",me->name()+"һͷ�����ˮ�У�ת�ۼ�Ͳ�����.......\n",environment(me),({me}));
        me->move(__DIR__"lakevoid");
        call_out("to_maple",(busy=3+random(3)),me);
        me->start_busy(busy);
        return 1;
        }
}
void to_maple(object me)
{
        me=this_player();
        write("�����˰��죬���ڵ��˶԰���\n");
        me->move(__DIR__"lake_e");
        message("vision",me->name()+"�Ӻ��������������۵ð�����\n",environment(me),({me}));
        me->stop_busy();
}
