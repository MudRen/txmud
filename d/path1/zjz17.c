// Room: /d/path1/zjz17.c

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
  "north" : __DIR__"ft_s8",
  "southeast" : __DIR__"zjz16",
]));
	set("outdoors", "path1");
	setup();
	replace_program(ROOM);
}
