// Room: /d/path1/zjz10.c

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
  "west" : "/d/zuojiacun/e_kou",
  "east" : __DIR__"zjz11",
]));
	set("outdoors", "path1");
	setup();
	replace_program(ROOM);
}
