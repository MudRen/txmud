// Room: /d/path1/zjz13.c

inherit ROOM;

void create()
{
	set("short", "�ּ���·");
	set("long", @LONG
����һ������С·�����Բݵ��ϳ����˸�ʽ������Ұ������
��������Ͻ������ɹ�����ʱ�����������㡣���������������
�Ҳ�������ĸо���
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"zjz12",
  "north" : __DIR__"zjz14",
]));
	set("outdoors", "path1");
	setup();
	replace_program(ROOM);
}
