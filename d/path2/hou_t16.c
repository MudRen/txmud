// Room: /d/path2/hou_t16.c

inherit ROOM;

void create()
{
	set("short", "С·");
	set("long", @LONG
����һ��������С·��·�ı����ǳ�Ƭ�ĸ����أ���������
һƬ��ԭ����ճ�ε��ɫ��һ�����ƻ���Ʈ����
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"hou_t15",
  "west" : __DIR__"hou_t17",
]));
	set("no_clean_up", 0);
	set("outdoors", "path2");
	setup();
	replace_program(ROOM);
}
