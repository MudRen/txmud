// Room: /d/path2/da_hou3.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
����һ����᫲�ƽ��С·��·�������Ǹ����ء�����ĸ���
����������׳���ߴ����Ҷ��ס��������ߣ���ֻ��һƬ��ãã
����ǰ������ȥ��
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"da_hou2",
  "south" : __DIR__"da_hou4",
]));
	set("no_clean_up", 0);
	set("outdoors", "path2");
	setup();
	replace_program(ROOM);
}
