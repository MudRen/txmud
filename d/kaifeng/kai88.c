// Room: /u/w/wangs/b/kai88.c

inherit ROOM;

void create()
{
	set("short", "����·");
	set("long", @LONG
����һ��·������ʯ�̾͵Ľֵ����ֵ�������������������
��ʽ�������̵�����ƹ�ҩ���ȵȣ�Ӧ�о��С��廨���ŵ�����
�ٽ����𣬲�ʱ�����������ǵ�ߺ�����ӽ��ϴ���������Ķ���
ͨ�����ֱ�·��
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "northeast" : __DIR__"kai119",
  "west" : __DIR__"kai86",
]));

	set("outdoors","kaifeng");
	setup();
	replace_program(ROOM);
}
