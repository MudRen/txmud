// Room: /d/path1/zjz11.c

inherit ROOM;

void create()
{
	set("short", "С��·");
	set("long", @LONG
����һ������С·��·��������һƬƬ�ĵ������ũ����
������æ����ţ����м�ֻ��ţ����߳��Ųݡ�
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"zjz10",
  "east" : __DIR__"zjz12",
]));
	set("outdoors", "path1");
	setup();
	replace_program(ROOM);
}
