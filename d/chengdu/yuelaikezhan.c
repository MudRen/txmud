// Room: /d/chengdu/yuelaikezhan.c

inherit ROOM;

void create()
{
	set("short", "������ջ");
	set("long", @LONG
������ǳɶ���������ջ�������Ŀ��̶�������Ͷ�ޣ���֮
��С�������������ÿ����������˶���һ�ֻص��˼ҵĸо���
�ſڵ�������д�ţ���ס��һ��һ�����������ӿ�ջ�ı������
���ܵ�����·��
LONG
);
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"wmlu5",
  "up" : __DIR__"kezhan2",
]));

	set("no_fight",1);

	set("objects",([
	__DIR__"npc/waiter" : 1,
]));

	setup();
}

int valid_leave(object me, string dir)
{
	if ( !me->query_temp("rent_paid") && dir == "up" )
		return notify_fail("��С��һ�µ���¥��ǰ˵����ס�꽻Ǯ���Ų���Ƿ��\n");

	if( me->query_temp("on_rided") && dir == "up")
		return notify_fail("��С������¥��ǰ˵�������ϵ����ﻹ������¥�°ɡ�\n");

	if( dir == "north" )
		me->delete_temp("rent_paid");

	return ::valid_leave(me, dir);
}
