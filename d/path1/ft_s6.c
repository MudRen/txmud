// Room: /d/path1/ft_s6.c

inherit ROOM;

void create()
{
	set("short", "����С·");
	set("long", @LONG
����һ������С·�����Բݵ��ϳ����˸�ʽ������Ұ������
��������Ͻ������ɹ�����ʱ�����������㡣������Զ�����Թ�
���ˡ�
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"ft_s5",
  "east" : __DIR__"ft_s7",
]));
	set("outdoors", "path1");
	setup();
	replace_program(ROOM);
}
