// Room: /d/tangmen/xiaodao7.c

inherit ROOM;

void create()
{
	set("short", "����С��");
	set("long", @LONG
����һ��Ƨ���Ĵ���С����С�������ǿ�֦��Ҷ������ȥ��
���������ܾ����ĵģ�ż����������������
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "southwest" : __DIR__"xiaodao6",
  "north" : __DIR__"lu1",
]));

	set("outdoors", "tangmen");
	setup();
	replace_program(ROOM);
}
