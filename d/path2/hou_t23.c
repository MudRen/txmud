// Room: /d/path2/hou_t23.c

inherit ROOM;

void create()
{
	set("short", "С��·");
	set("long", @LONG
����һ����ԭС·��·��������һƬ��ɫ�Ĳ�ԭ����ԭ�ϳ�
�Ÿ��ָ�����Ұ���ݡ�һЩ��������������Ⱥ�ڲ�ԭ��ɢ������
��һȺ����۳���ε������£�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"hou_t24",
  "south" : __DIR__"hou_t22",
]));
	set("no_clean_up", 0);
	set("outdoors", "path2");
	setup();
	replace_program(ROOM);
}
