// Room: /d/path2/hou_t19.c

inherit ROOM;

void create()
{
	set("short", "��ԭС·");
	set("long", @LONG
����һ����ԭС·��·��������һƬ��ɫ�Ĳ�ԭ��һЩ����
����������Ⱥ�ڲ�ԭ��ɢ��������һȺ����۳���ε������£�
������������
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "southeast" : __DIR__"hou_t18",
  "northwest" : __DIR__"hou_t20",
]));
	set("no_clean_up", 0);
	set("outdoors", "path2");
	setup();
	replace_program(ROOM);
}
