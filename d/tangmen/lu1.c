// Room: /d/tangmen/lu1.c

inherit ROOM;

void create()
{
	set("short", "ʯ��С·");
	set("long", @LONG
����һ������ɫ����ɫСʯ���̳ɵ�С·���������˸����
�������������һƬ���ܵ�С���֣����治Զ��һ��С��ʡ�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"yz_door",
  "south" : __DIR__"xiaodao7",
]));

	set("outdoors", "tangmen");
	setup();
	replace_program(ROOM);
}
