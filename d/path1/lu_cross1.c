// Room: /d/path1/lu_cross1.c

inherit ROOM;

void create()
{
	set("short", "�ּ�С·");
	set("long", @LONG
����һƬ�����֣��ߵͲ��ȵ������β�룬ʱ��һö�ɹ�
���������ߣ����������ۡ������졣������ϸ�۲죬���ѷ���
·�ںη���
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"py10",
  "northwest" : __DIR__"lu_cross2",
]));
	set("outdoors", "path1");
	setup();
	replace_program(ROOM);
}
