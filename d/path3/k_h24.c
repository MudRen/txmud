// Room: /d/path3/k_h24.c

inherit ROOM;

void create()
{
	set("short", "��·");
	set("long", @LONG
����һ��������·��·�Ķ�������һƬ�����де����֣���
���ǿ��ĵ����ͷˮţ�����������е�ת��תȥ��ż������
�����ĸ�����
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"k_h25",
  "north" : __DIR__"k_h23",
]));
	set("no_clean_up", 0);
	set("outdoors", "path3");
	setup();
	replace_program(ROOM);
}
