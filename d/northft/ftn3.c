// Room: /d/northft/ftn3.c

inherit ROOM;

void create()
{
	set("short", "��ʯС·");
	set("long", @LONG
���Ƿ���Ǳ�����һ����ʯ�̳ɵ�С·��������Ƿ���ǵ�
�����ˡ�·��ϡ��ĳ���һЩ�Ĳݣ�·������ɳ�������󱱷��
Х������Խ������һ�������ĸо���
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"ftn2",
  "north" : __DIR__"ftn4",
]));

	set("outdoors", "northft");

	setup();
	replace_program(ROOM);
}
