// Room: /d/lumaji/lu1.c

inherit ROOM;

void create()
{
	set("short", "¹������");
	set("long", @LONG
һ����С�Ļ���С·бб�������ţ����Գ��ŸߵͲ������
�ݣ�͸���Ӳݴԣ�����Կ���һȺ������ڶ���Ĳ�ԭ�ϱ��ܡ�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : "/d/path1/py7",
  "south" : __DIR__"lu2",
]));
	set("outdoors", "lumaji");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
