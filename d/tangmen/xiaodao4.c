// Room: /d/tangmen/xiaodao4.c

inherit ROOM;

void create()
{
	set("short", "����С��");
	set("long", @LONG
����һ��Ƨ���Ĵ���С����С�������ǿ�֦��Ҷ������ȥ��
���������ܾ����ĵģ�ż����������������
LONG
	);
	set("exits", ([
  "southeast" : __DIR__"xiaodao3",
  "north" : __DIR__"yaopu1",
]));

	set("outdoors", "tangmen");
	setup();
	replace_program(ROOM);
}
