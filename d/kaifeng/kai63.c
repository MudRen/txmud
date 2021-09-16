// Room: /open/k/kai63.c

inherit ROOM;

void create()
{
	set("short", "���Ͽ�ջ");
	set("long", @LONG
��ջ��ǰ����һ����ˣ���˶������ŵ�һֻ���ĺ����
��д�š����Ͽ�ջ������ҿ�ջ����ǳ��ã����������Ŀ�����
���������Ъ�ţ���ջ����������������Ĵ����ϰ���ʮ������
�ӣ��������ǽ��͡����������¥�����ǿͷ��ˡ�ǽ�Ϲ���һ��
ľ����(paizi)��
LONG
	);
	set("no_sleep_room", 1);
	set(SAFE_ENV,1);
	set("item_desc", ([ /* sizeof() == 1 */
  "paizi" : "¥�Ͽͷ���ÿ������������
",
]));
	set("objects", ([ /* sizeof() == 1 */
	__DIR__"npc/waiter" : 1,
]));
	set("exits", ([ /* sizeof() == 2 */
  "up" : __DIR__"kezhan2",
  "east" : __DIR__"kai113",
]));

	setup();
}

int valid_leave(object me, string dir)
{

	if ( !me->query_temp("rent_paid") && dir == "up" )
		return notify_fail("��С��һ�µ���¥��ǰ������һ���������ţ����ס����\n");
	if( me->query_temp("on_rided") && dir == "up")  // �ж��Ƿ���������
		return notify_fail("��С������¥��ǰ˵�������ϵ����ﻹ������¥�°ɡ�\n");

	if ( me->query_temp("rent_paid") && dir == "east" )
	return notify_fail("��С���ܵ��ű���ס���͹��Ѿ��������ӣ����᲻ס��������أ�
���˻���ΪС���ź����أ��Ժ�˭��������\n");

	return ::valid_leave(me, dir);
}
