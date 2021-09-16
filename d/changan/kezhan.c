// Room: /u/xiaozhen/kezhan.c

inherit ROOM;

void create()
{
	set("short", "������ջ");
	set("long", @LONG
�����ǳ��������һ�ҿ�ջ������ǳ���¡��������������
����������������ס�꣬�����иϿ��ľ��ӣ���������̼֡���
һ���ţ���Ϳ���С����ͣ��æµ���к��ſ��ˣ�����һ���ߴ�
�Ĺ�̨�����߰������賣��������̨���ǳ�̳��̳�����ף���ǰ
������������������аڷ���һЩ���Σ����Ѳ��ĸɸɾ�����ǽ
�Ϲ���һ������(paizi)��
LONG
	);

	set(SAFE_ENV,1);
        set("no_sleep_room",1);

	set("item_desc", ([
		"paizi" : "¥�Ͽͷ���ÿ�����������\n",
	]));

	set("objects", ([
		__DIR__"npc/waiter_1" : 1,
	]));

	set("exits", ([
		"east" : __DIR__"sroad9",
		"up" : __DIR__"kezhan2",
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
