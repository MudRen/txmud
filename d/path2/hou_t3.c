// Room: /d/path2/hou_t3.c

inherit ROOM;

void create()
{
	set("short", "С��·");
	set("long", @LONG
����һ����Ţ��С��·��·����һ��Сˮ���������ˮ����
�������ţ���Զ�����ǳ�Ƭ�ĸ����ء�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"hou_t2",
  "south" : __DIR__"hou_t4",
]));
	set("no_clean_up", 0);
	set("outdoors", "path2");
	setup();
	replace_program(ROOM);
}
