// Room: /u/w/wangs/b/kai125.c

inherit ROOM;

void create()
{
	set("short", "������·");
	set("long", @LONG
����һ��·������ʯ���̾͵Ľֵ����ֵ�����������������
�Ǹ�ʽ�������̵����棬Ӧ�о��С��廨���ŵĵ��������ٽ���
�𣬲�ʱ�����������ǵ�ߺ�����ӽ��ϴ��������߾��ǿ���ǵ�
�����ꡣ
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 3 */
  "southeast" : __DIR__"kai127",
  "north" : __DIR__"kai126",
  "west" : __DIR__"kai122",
]));

	set("outdoors","kaifeng");
	setup();
	replace_program(ROOM);
}
