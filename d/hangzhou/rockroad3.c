// Room: /d/hangzhou/rockroad3.c

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
  "south" : __DIR__"banboo1",
  "west" : __DIR__"sudi4",
  "east" : __DIR__"house4",
  "north" : __DIR__"rockroad2",
]));

	setup();
	replace_program(ROOM);
}
