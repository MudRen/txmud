// Room: /d/tangmen/yz_door.c

inherit ROOM;

void create()
{
	set("short", "ҩׯС��");
	set("long", @LONG
������һ�����С�ţ��ű���һ��Сľ����д�š�ҩׯ����
��׭�֡�������һ����ɫ����ɫСʯ���̳ɵ�С·��
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"lu1",
  "north" : __DIR__"yz_xiaoyuan",
]));

	set("outdoors", "tangmen");
	setup();
	replace_program(ROOM);
}
