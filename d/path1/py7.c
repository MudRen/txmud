// Room: /d/path1/py7.c

inherit ROOM;

void create()
{
	set("short", "��·");
	set("long", @LONG
����һ�������Ļ���С·��·�ϵ�������ƥ�ķ�㣬������
����ѹ��·��ߵͲ�ƽ����ȥͨ�����ͤ���������¹���ı�
�ڡ�
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 3 */
  "south" : "/d/lumaji/lu1",
  "west" : __DIR__"py8",
  "east" : __DIR__"py6",
]));
	set("outdoors", "path1");
	setup();
	replace_program(ROOM);
}
