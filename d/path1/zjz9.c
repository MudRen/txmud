// Room: /d/path1/zjz9.c

inherit ROOM;

void create()
{
	set("short", "С��·");
	set("long", @LONG
һ��С·��ͨȥ����Զ��������Ҵ塣·��ߵͲ�ƽ����
�඼��ׯ�ڵء�������һƬ���֣�����һ��С·��֪ͨ��η���
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"zjz8",
  "east" : "/d/zuojiacun/lu1",
]));
	set("outdoors", "path1");
	setup();
	replace_program(ROOM);
}
