// Room: /d/tangmen/ycl3.c

inherit ROOM;

void create()
{
	set("short", "��С·");
	set("long", @LONG
����һ���������۵�С·��������һСƬ�Ͱ������֣�����
�Ƕ��͵�ɽ�ڡ�����������ʯ�ӣ��еĻ��ܼ����������������
����������
LONG
	);
	set("exits", ([
  "southeast" : __DIR__"ycl2",
  "west" : __DIR__"ycl4",
]));

	set("outdoors", "tangmen");
	setup();
	replace_program(ROOM);
}
