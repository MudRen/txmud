// Room: /u/w/wangs/b/kai127.c

inherit ROOM;

void create()
{
	set("short", "���ֶ�·");
	set("long", @LONG
����һ��·������ʯ���̾͵Ľֵ����ֵ�����������������
�Ǹ�ʽ�������̵����棬Ӧ�о��С��廨���ŵĵ��������ٽ���
�𣬲�ʱ�����������ǵ�ߺ�����ӽ��ϴ��������߾��ǿ���ǵ�
ˮ���ꡣ
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 3 */
  "northwest" : __DIR__"kai125",
  "southeast" : __DIR__"kai129",
  "east" : __DIR__"kai128",
]));

	set("outdoors","kaifeng");
	setup();
	replace_program(ROOM);
}
