// Room: /d/path1/lu_cross4.c

inherit ROOM;

void create()
{
	set("short", "����С��");
	set("long", @LONG
����һƬ�����֣��ߵͲ��ȵ������β�룬ʱ��һö�ɹ�
���������ߣ����������ۡ������졣������ϸ�۲죬���ѷ���
·�ںη���
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "northwest" : __DIR__"lu_cross5",
  "southeast" : __DIR__"lu_cross3",
]));
	set("outdoors", "path1");
	setup();
	replace_program(ROOM);
}
