// Room: /d/path1/zjz16.c

inherit ROOM;

void create()
{
	set("short", "�ּ�С��·");
	set("long", @LONG
����һ������С·�����Բݵ��ϳ����˸�ʽ������Ұ������
��������Ͻ������ɹ�����ʱ�����������㡣���������������
�Ҳ�������ĸо���
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "northwest" : __DIR__"zjz17",
  "southeast" : __DIR__"zjz15",
]));
	set("outdoors", "path1");
	setup();
	replace_program(ROOM);
}
