// Room: /u/w/wangs/b/kai129.c

inherit ROOM;

void create()
{
	set("short", "���ֶ�·");
	set("long", @LONG
����һ��·������ʯ���̾͵Ľֵ����ֵ�����������������
�Ǹ�ʽ�������̵����棬Ӧ�о��С��廨���ŵĵ��������ٽ���
�𣬲�ʱ�����������ǵ�ߺ�����ӽ��ϴ��������߾��ǿ���ǵ�
�೦�ꡣ
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 3 */
  "northwest" : __DIR__"kai127",
  "southwest" : __DIR__"kai131",
  "west" : __DIR__"kai130",
]));

	set("outdoors","kaifeng");
	setup();
	replace_program(ROOM);
}
