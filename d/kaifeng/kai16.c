// Room: /u/w/wangs/b/kai16.c

inherit ROOM;

void create()
{
	set("short", "����·");
	set("long", @LONG
����·ͨ�򿪷���ڵ�һЩ���о��㣬���·����ȫ������
�������Ĵ�����·��żȻ�ܿ���������������ο�������·�ߵ�
����ָָ��㡣����������µĿ����������������ӵĳ���������
�����ʱΪ֮һ����·����һ�����µ���ͤ���������ע�⣬ȥ
��Ϣһ��ɡ�
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"kai9",
  "north" : __DIR__"kai19",
  "west" : __DIR__"kai10",
]));

	set("outdoors","kaifeng");
	setup();
	replace_program(ROOM);
}
