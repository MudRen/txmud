// Room: /d/path3/k_s7.c

inherit ROOM;

void create()
{
	set("short", "����·");
	set("long", @LONG
������һƬ���֣�����һ��С·�������䡣�ݵ��ϳ���һЩ
Ұ����һ����֪������ʲô��Ʒ�֡�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"k_s8",
  "north" : __DIR__"k_s6",
]));
	set("outdoors", "path3");
	setup();
	replace_program(ROOM);
}
