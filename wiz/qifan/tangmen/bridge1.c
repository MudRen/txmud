// Room: /d/tangmen/bridge1.c

inherit ROOM;

void create()
{
	set("short", "С����");
	set("long", @LONG
����һ������С�ţ��峺���׵�Ϫˮ�������������԰���һ
���������ɵ���ʣ���ֻС����������質����������������һ
�ֳ�Ȼ���׵ĸо���
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"xiaoyuan",
  "south" : __DIR__"door",
]));

	set("outdoors", "tangmen");

	setup();
	replace_program(ROOM);
}
