// Room: /d/tangmen/ycl7.c

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
  "southeast" : __DIR__"ycl6",
  "north" : __DIR__"ycl8",
]));

	set("outdoors", "tangmen");
	setup();
	replace_program(ROOM);
}
