// Room: /d/path1/ft_s7.c

inherit ROOM;

void create()
{
	set("short", "����С·");
	set("long", @LONG
����һ������С·�����Բݵ��ϳ����˸�ʽ������Ұ������
��������Ͻ������ɹ�����ʱ�����������㡣
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"ft_s6",
  "east" : __DIR__"ft_s8",
]));
	set("outdoors", "path1");
	setup();
	replace_program(ROOM);
}
