// Room: /d/path1/py9.c

inherit ROOM;

void create()
{
	set("short", "��·");
	set("long", @LONG
����һ�������Ļ���С·��·�ϵ�������ƥ�ķ�㣬������
����ѹ��·��ߵͲ�ƽ�����������Ƿ���ͤ�ˡ�
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"py10",
  "east" : __DIR__"py8",
]));
	set("outdoors", "path1");
	setup();
	replace_program(ROOM);
}
