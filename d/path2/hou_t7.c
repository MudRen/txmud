// Room: /d/path2/hou_t7.c

inherit ROOM;

void create()
{
	set("short", "����·");
	set("long", @LONG
����һ�������Ļ���С·��·��Զ���ǸߵͲ��ȵ�ɽ�𡣷�
һ��������Ʈ�Ķ��Ƿ�״�Ļ�ɳ���㲻�ɵ����ֵ�ס���۾���
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"hou_t6",
  "west" : __DIR__"hou_t8",
]));
	set("no_clean_up", 0);
	set("outdoors", "path2");
	setup();
	replace_program(ROOM);
}
