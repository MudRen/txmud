// Room: /d/tangmen/xiaodao5.c

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
  "northeast" : __DIR__"xiaodao6",
  "southwest" : __DIR__"yaopu5",
]));

	set("outdoors", "tangmen");
	setup();
	replace_program(ROOM);
}
