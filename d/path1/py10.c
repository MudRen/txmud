// Room: /d/path1/py10.c

inherit ROOM;

void create()
{
	set("short", "����ͤ");
	set("long", @LONG
������Ƿ���ͤ����·�ı��ߣ������˷�����ÿ�����쵽��
��ʱ��ƬƬ��Ҷʹ������������ȥ����������ͨ��¹����
��ȥͨ�򳤰��ǣ�������������֣����Ե�ɽ���ء�
LONG
	);

	set("exits", ([
  "south" : __DIR__"lmj1",
  "east" : __DIR__"py9",
  "north" : __DIR__"lu_cross1",
]));
	set("outdoors", "path1");
	setup();

	replace_program(ROOM);
}
