//hotel.c ��֥��Ŀ�ջ
inherit ROOM;
void create()
{
        set("short", "�ϵ���ջ");
        set("long", @LONG
��������֥��Ψһ�Ŀ�ջ��������Ϊ�����˲��Ǻܶ࣬����
����Ҳ��һ�㡣��������Ǵ��������Ŀ��ˣ����п��������Ҵ�
������Ҳ�����峤�ġ���ջ�ϰ����������ѧ�����򣬸��峤Ҳ
�е㽻�顣
LONG
        );
        set(SAFE_ENV,1);
        set("no_sleep_room",1);
        set("item_desc", ([
        "paizi" : "¥�Ͽͷ���ÿ������������\n",
]));
        set("objects", ([
        __DIR__"npc/waiter":1,
]));
        set("exits", ([
        "east" : __DIR__"lz_wroad1",
        "up" : __DIR__"hotel2",
]));
        setup();
}
int valid_leave(object me, string dir)
{
        if ( !me->query_temp("rent_paid") && dir == "up" )
                return notify_fail("��С��һ�µ���¥��ǰ������һ������ô�ţ����ס����\n");
        if( me->query_temp("on_rided") && dir == "up")  // �ж��Ƿ���������
                return notify_fail("��С������¥��ǰ˵�������ϵ����ﻹ������¥�°ɡ�\n");
        if ( me->query_temp("rent_paid") && dir == "east" )
                me->delete_temp("rent_paid");
        return ::valid_leave(me, dir);
}
