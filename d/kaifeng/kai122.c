// Room: /u/w/wangs/b/kai122.c

inherit ROOM;

void create()
{
	set("short", "���ֱ�·");
	set("long", @LONG
����һ��·������ʯ�̾͵Ľֵ����ֵ�������������������
��ʽ�������̵����棬Ӧ�о��С��廨���ŵ������ٽ����𣬲�
ʱ�����������ǵ�ߺ�����ӽ��ϴ������ϱ��ǲ÷�ꡣ���߾���
������·�ˡ�
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"kai124",
  "west" : __DIR__"kai119",
  "east" : __DIR__"kai125",
]));

	set("outdoors","kaifeng");
	setup();
	replace_program(ROOM);
}
