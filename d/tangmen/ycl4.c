// Room: /d/tangmen/ycl4.c

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
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"ycl5",
  "east" : __DIR__"ycl3",
]));

	set("outdoors", "tangmen");
	setup();
	replace_program(ROOM);
}
