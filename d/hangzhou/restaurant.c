// /d/hangzhou/restaurant.c

inherit ROOM;

void create()
{
        set("short", "������ջ");
        set("long", @LONG
һ�����ţ���Ϳ���������ǽ�Ϲ���һ�����ң����������
�֡�Цӭ���¿͡����ƹ�������һ�����������ΰ�ʶ���ŵ���
�����룬����һ����Ⱦ������С�������ڿ죬����䣬�ƹ��ӭ
�˹��������͹٣����Ǵ�⣬����ס�ꣿ��������ȴ���Ǳ��ؿ�
�������������и�¥��ֱ�϶�¥���ſڹ���һ������(paizi)��
LONG
        );
        set("exits", ([ 
            "south"  : __DIR__"changanw1",
            "up"  : __DIR__"rl2",
]));

	set("item_desc", ([
		"paizi" : "¥�Ͽͷ���ÿ��һ��������\n",
	]));

	set(SAFE_ENV,1);
        set("no_sleep_room",1);

	set("objects",([
	__DIR__"npc/waiter" : 1,
]));
        setup();
}

int valid_leave(object me, string dir)
{

	if ( !me->query_temp("rent_paid") && dir == "up" )
		return notify_fail("������һ�³嵽¥��ǰ��ס�㣬����һ������ô�ţ����ס����\n");
	if( me->query_temp("on_rided") && (dir == "up"))  // �ж��Ƿ���������
		return notify_fail("�����嵲��¥��ǰ˵�������ϵ����ﻹ������¥�°ɡ�\n");

	if ( me->query_temp("rent_paid") && (dir == "south") )
	return notify_fail("�������ܵ��ű���ס���͹��Ѿ��������ӣ���ô��ס��������أ�
���˻���ΪС���ź����أ��Ժ�˭��������\n");

	return 1;
}
