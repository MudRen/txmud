// Room: /open/k/kai119.c

inherit ROOM;

void create()
{
	set("short", "���ֱ�·");
	set("long", @LONG
����һ��·������ʯ�̾͵Ľֵ����ֵ�������������������
��ʽ�������̵����棬Ӧ�о��С��廨���ŵ������ٽ����𣬲�
ʱ�����������ǵ�ߺ�����ӽ��ϴ������ϱ߾��ǿ������õ���
���ꡣ
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 3 */
  "southwest" : __DIR__"kai88",
  "east" : __DIR__"kai122",
  "south" : __DIR__"kai121",
]));

	set("outdoors","kaifeng");
	setup();
	replace_program(ROOM);
}
