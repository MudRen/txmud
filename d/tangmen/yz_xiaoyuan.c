// Room: /d/tangmen/yz_xiaoyuan.c

inherit ROOM;

void create()
{
	set("short", "СԺ��");
	set("long", @LONG
������һ��������СԺ��Ժ�����������̵�С�ݣ��м���һ
��ʯ�������滹����û�������֣�����һ�־��ס����еĸо���
�������������������ŵ���û��Ҳ��Ը�������Ƽұ�ҩׯ��
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"yz_ku",
  "south" : __DIR__"yz_door",
  "east" : __DIR__"yz_tang",
]));

	set("outdoors", "tangmen");
	setup();
	replace_program(ROOM);
}
