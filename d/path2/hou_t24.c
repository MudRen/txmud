// Room: /d/path2/hou_t24.c

inherit ROOM;

void create()
{
	set("short", "С��·");
	set("long", @LONG
����һ����ԭС·��·��������һƬ��ɫ�Ĳ�ԭ����ԭ�ϳ�
�Ÿ��ָ�����Ұ���ݡ�����ȥ�͵���ˮ���ˡ�
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"hou_t23",
  "north" : "/d/tianshui/skou",
]));
	set("no_clean_up", 0);
	set("outdoors", "path2");
	setup();
	replace_program(ROOM);
}
