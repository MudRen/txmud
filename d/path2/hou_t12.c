// Room: /d/path2/hou_t12.c

inherit ROOM;

void create()
{
	set("short", "С��·");
	set("long", @LONG
����һ�������Ļ���С·��·��Զ���ǸߵͲ��ȵ�ɽ�𡣷�
һ��������Ʈ�Ķ��Ƿ�״�Ļ�ɳ���㲻�ɵ����ֵ�ס���۾���
·��������һ���ŵ�Ҥ����
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"hou_t11",
  "west" : __DIR__"hou_t13",
]));
	set("no_clean_up", 0);
	set("outdoors", "path2");
	setup();
	replace_program(ROOM);
}
