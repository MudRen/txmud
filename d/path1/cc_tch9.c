// Room: /d/path1/cc_tch9.c

inherit ROOM;

void create()
{
	set("short", "����·");
	set("long", @LONG
����һ��������·�������ĳ������������������ڵ��ϣ�
��ʱ�ز�Ĩ�����Ϻ��顣·��������һƬƬ���
LONG
	);

	set("exits", ([
  "north" : __DIR__"cc_tch10",
  "southeast" : __DIR__"cc_tch8",
]));
	set("outdoors", "path1");
	setup();

	replace_program(ROOM);
}
