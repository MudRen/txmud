// Room: /d/path1/ft_s8.c

inherit ROOM;

void create()
{
	set("short", "����С·");
	set("long", @LONG
����һ������С·�����Բݵ��ϳ����˸�ʽ������Ұ������
��������Ͻ������ɹ�����ʱ�����������㡣����һ���ּ�С·
�������֡�
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"zjz17",
  "west" : __DIR__"ft_s7",
  "east" : __DIR__"ft_s9",
]));
	set("outdoors", "path1");
	setup();
	replace_program(ROOM);
}
