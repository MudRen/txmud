// Room: /d/path3/k_s8.c

inherit ROOM;

void create()
{
	set("short", "����·");
	set("long", @LONG
������һƬ���֣�����һ��С·�������䡣���еĲݵ��Ѿ�
��̤�����߰ưˣ�ż���д����ũ��·����
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"k_s9",
  "north" : __DIR__"k_s7",
]));
	set("outdoors", "path3");
	setup();
	replace_program(ROOM);
}
