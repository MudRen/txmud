// Room: /d/tangmen/ycl5.c

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
  "south" : __DIR__"ycl4",
  "northwest" : __DIR__"ycl6",
]));

	set("outdoors", "tangmen");
	setup();
	replace_program(ROOM);
}
