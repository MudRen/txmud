// Room: /d/path2/hou_t9.c

inherit ROOM;

void create()
{
	set("short", "�ƹ�·");
	set("long", @LONG
����һ�������Ļ���С·��·��Զ���ǸߵͲ��ȵ�ɽ�𡣷�
һ��������Ʈ�Ķ��Ƿ�״�Ļ�ɳ���㲻�ɵ����ֵ�ס���۾���
���治ʱ�����޴����ˮ����
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"hou_t8",
  "west" : __DIR__"hou_t10",
]));
	set("no_clean_up", 0);
	set("outdoors", "path2");
	setup();
	replace_program(ROOM);
}
