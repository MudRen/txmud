// Room: /u/w/wangs/b/kai135.c

inherit ROOM;

void create()
{
	set("short", "���ֶ�·");
	set("long", @LONG
����һ��·������ʯ���̾͵Ľֵ����ֵ�����������������
�Ǹ�ʽ�������̵����棬Ӧ�о��С��廨���ŵĵ��������ٽ���
�𣬲�ʱ�����������ǵ�ߺ�����ӽ��ϴ���������������������
����ǵĶ���֡�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "southwest" : __DIR__"kai147",
  "northeast" : __DIR__"kai133",
]));

	set("outdoors","kaifeng");
	setup();
	replace_program(ROOM);
}
