// Room: /d/tangmen/ycl8.c

inherit ROOM;

void create()
{
	set("short", "��С·");
	set("long", @LONG
����һ���������۵�С·��������һСƬ�Ͱ������֣�����
�Ƕ��͵�ɽ�ڡ�����������ʯ�ӣ��еĻ��ܼ����������������
������������ǰ����һ�Ѵִ��ԭľ��ס��ȥ·��
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"ycl7",
]));

	set("outdoors", "tangmen");
	setup();
	replace_program(ROOM);
}
