// Room: /d/hangzhou/rockroad2.c

inherit ROOM;

void create()
{
	set("short", "��ʯ·");
	set("long", @LONG
��������һ����ʯ�̾͵�С·�ϣ�·�����������񣬷�����
���������������ԣ�������Զ����Ϳ������������������յ���
��
LONG
	);
	set("outdoors", "hangzhou");
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"dock2",
  "south" : __DIR__"rockroad3",
  "east" : __DIR__"guancaishop",
  "north" : __DIR__"rockroad1",
]));

	setup();
	replace_program(ROOM);
}
