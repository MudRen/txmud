// Room: /d/tangmen/yanwu.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
������һ�����Ŀճ����ճ��������ŵ�һ���ľ����д��
һ�����ġ��䡱�֡������������������ȭ��������һλһ
����µ������˱������Ĵ�Ѳ��ָ�㡣
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"fyuan",
]));

	set("objects", ([
	__DIR__"npc/master_bu" : 1,
]));

	set("outdoors", "tangmen");
	setup();
	replace_program(ROOM);
}
