// Room: /u/w/wangs/b/kai133.c

inherit ROOM;

void create()
{
	set("short", "���ֶ�·");
	set("long", @LONG
����һ��·������ʯ���̾͵Ľֵ����ֵ�����������������
�Ǹ�ʽ�������̵����棬Ӧ�о��С��廨���ŵĵ��������ٽ���
�𣬲�ʱ�����������ǵ�ߺ�����ӽ��ϴ��������߾��ǿ���ǵ�
С��԰��
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "northeast" : __DIR__"kai131",
  "southwest" : __DIR__"kai135",
  "west" : __DIR__"kai134",
]));

	set("outdoors","kaifeng");
	setup();
	replace_program(ROOM);
}
