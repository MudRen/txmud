// Room: /d/path3/k_h23.c

inherit ROOM;

void create()
{
	set("short", "��·");
	set("long", @LONG
����һ��������·��·�Ķ�������һƬ�����де����֣���
���ǿ��ĵ����ͷˮţ�����������е�ת��תȥ��
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"k_h24",
  "north" : __DIR__"k_h22",
]));
	set("no_clean_up", 0);
	set("outdoors", "path3");
	setup();
	replace_program(ROOM);
}
