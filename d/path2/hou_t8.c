// Room: /d/path2/hou_t8.c

inherit ROOM;

void create()
{
	set("short", "�ƹ�·");
	set("long", @LONG
����һ�������Ļ���С·��·��Զ���ǸߵͲ��ȵ�ɽ�𡣷�
һ��������Ʈ�Ķ��Ƿ�״�Ļ�ɳ���㲻�ɵ����ֵ�ס���۾���
·�ı�����һ���ŵ�Ҥ����
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"hou_t7",
  "west" : __DIR__"hou_t9",
]));
	set("no_clean_up", 0);
	set("outdoors", "path2");
	setup();
	replace_program(ROOM);
}
