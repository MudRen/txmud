// Room: /d/tangmen/door2.c

inherit ROOM;

void create()
{
	set("short", "��·");
	set("long", @LONG
����һ��С��·�����治Զ���Ƽұ�����·�����ǻ��ܿ���
������ɫ�Ҵҵ��������������Ǹ��ʵ�ɽ�ڣ�һ����С·����
ɽ��������������Զ�����졣
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "northwest" : __DIR__"ycl1",
  "east" : __DIR__"gd2",
]));

	set("outdoors", "tangmen");
	setup();
	replace_program(ROOM);
}
