// Room: /d/path1/ft_s13.c

inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
����һ������С·�����Բݵ��ϳ����˸�ʽ������Ұ������
��������Ͻ������ɹ�����ʱ�����������㡣
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"ft_s12",
  "north" : __DIR__"ft_s14",
]));
	set("outdoors", "path1");
	setup();
	replace_program(ROOM);
}
