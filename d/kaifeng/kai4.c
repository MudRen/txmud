// Room: /u/w/wangs/b/kai4.c

inherit ROOM;

void create()
{
	set("short", "����·");
	set("long", @LONG
����·ͨ�򿪷���ڵ�һЩ���о��㣬���·����ȫ������
�������Ĵ�����·��żȻ�ܿ���������������ο�������·�ߵ�
����ָָ��㡣����������µĿ����������������ӵĳ���������
�����ʱΪ֮һ����
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"kai9",
  "south" : __DIR__"kai3",
  "west" : __DIR__"kai7",
]));

	set("outdoors","kaifeng");
	setup();
	replace_program(ROOM);
}
