// Room: /d/path2/hou_t1.c

inherit ROOM;

void create()
{
	set("short", "С��·");
	set("long", @LONG
����һ����Ţ��С��·��·����һ��Сˮ���������ˮ����
�������ţ���Զ�����ǳ�Ƭ�ĸ����ء����治Զ���Ǻ����ˡ�
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"hou_t2",
  "north" : "/d/houmaji",
]));

	set("outdoors", "path2");
	setup();
	replace_program(ROOM);
}
