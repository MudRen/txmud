// Room: /u/w/wangs/b/kai131.c

inherit ROOM;

void create()
{
	set("short", "���ֶ�·");
	set("long", @LONG
����һ��·������ʯ���̾͵Ľֵ����ֵ�����������������
�Ǹ�ʽ�������̵����棬Ӧ�о��С��廨���ŵĵ��������ٽ���
�𣬲�ʱ�����������ǵ�ߺ�����ӽ��ϴ��������߾��ǿ���ǵ�
��ݡ�
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 3 */
  "northeast" : __DIR__"kai129",
  "southwest" : __DIR__"kai133",
  "east" : __DIR__"kai132",
]));

	set("outdoors","kaifeng");
	setup();
	replace_program(ROOM);
}
