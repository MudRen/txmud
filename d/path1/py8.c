// Room: /d/path1/py8.c

inherit ROOM;

void create()
{
	set("short", "��·");
	set("long", @LONG
����һ�������Ļ���С·��·�ϵ�������ƥ�ķ�㣬������
����ѹ��·��ߵͲ�ƽ��
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"py9",
  "east" : __DIR__"py7",
]));
	set("outdoors", "path1");
	setup();
	replace_program(ROOM);
}
