//lake_e.c ���ɴ��������
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short","���ɴ����");
        set("long", @LONG
�������⣬��һƬ����ɽɫ�����ܴ���������ѩ�����У���
Ӱ���У����ֻ��ƣ�ǡ�������ɾ���ԭ������ǲ���������Ŀ��
��ʥ�������ɴ����ֻ�ǴӺ����Ͽ�ȥ��Զ��ˮ��������������
��ʲô�������ƺ���ϸ΢����֮��������ϸ�������Ҳ�������
����Դ�������������ɡ�
LONG
);
        set("exits",([
]));
        setup();
}
void show_secret(string msg,object user)
{
        if (!msg||!user)
        return;
        if (msg=="begin_night")
        {
        tell_object(user,HIW"ҹɫ�����ˣ����Ȼ���ֺ��������ż��ǵƹ⡣\n"NOR,);
        }
        return;
}
void init()
{
        add_action("do_pass","pass");
        add_action("do_swim","swim");
}
int do_pass(string arg)
{
        object me;
        me=this_player();
        if (!arg)
        return notify_fail("��Ҫ��Խ���\n");
        if (arg=="������"||arg=="maple") {
        if (me->query_temp("mark/������")) {
        write("��һͷ���������.......\n");
        message("vision",me->name()+"һͷ��������֣�ת�ۼ�Ͳ�����.......\n",environment(me),

({me}));
        me->move(__DIR__"maple_e");
        message("vision",me->name()+"���˹�����\n",environment(me),({me}));
         return 1;
}
        else return notify_fail("�㿴�˰��죬�������Ŷ��롣\n");
        }
}
int do_swim(string arg)
{
        object me;
        int busy;
        me=this_player();
        if (!arg)
        return notify_fail("��Ҫ�������Σ�\n");
        if (arg=="��"||arg=="lake") {
        if (!is_day()) {
        write("��һͷ�����ˮ�У����泩��.......\n");
        message("vision",me->name()+"һͷ�����ˮ�У�ת�ۼ�Ͳ�����.......\n",environment(me),

({me}));
        me->move(__DIR__"lakevoid");
        call_out("to_temple",(busy=3+random(3)),me);
        me->start_busy(busy);
        return 1;
}
        else return notify_fail("û��Ϲ����������ʲô�������������\n");
        }
}
void to_temple(object me)
{
        me=this_player();
        write("�����˰��죬���ڵ��˶԰���\n");
        me->move(__DIR__"lake_w");
        message("vision",me->name()+"�Ӻ��������������۵ð�����\n",environment(me),({me}));
        me->stop_busy();
}
