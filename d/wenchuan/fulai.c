// kezhan.c ������ջ

inherit ROOM;

void create()
{
	set("short", "������ջ");
	set("long", @LONG
�������봨�����һ�ҿ�ջ������ǳ���¡��������������
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
		"paizi" : "¥�Ͽͷ���ÿ��ʮ����������\n",
	]));

	set("objects", ([
		__DIR__"npc/waiter_1" : 1,
	]));

	set("exits", ([
		"west" : __DIR__"shilu3",
		"up"   : __DIR__"kezhan2",
	]));

	setup();
}

int valid_leave(object me, string dir)
{

	if ( !me->query_temp("rent_paid") && dir == "up" )
		return notify_fail("��С��һ�µ���¥��ǰ������һ���������ţ����ס����\n");
	if( me->query_temp("on_rided") && dir == "up")
		return notify_fail("��С������¥��ǰ˵�������ϵ����ﻹ������¥�°ɡ�\n");

	if ( me->query_temp("rent_paid") && dir == "south" )
	return notify_fail("��С���ܵ��ű���ס���͹��Ѿ��������ӣ����᲻ס��������أ�
���˻���ΪС���ź����أ��Ժ�˭��������\n");

	return ::valid_leave(me, dir);
}
