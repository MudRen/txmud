// Room: /d/path2/ch_k13.c

inherit ROOM;

void create()
{
	set("short", "��·");
	set("long", @LONG
����һ������С·��·���Ӳݴ�������������ȥ��ֻ��һƬ
������·�����˺��٣�ż���м���ũ�����ŵ��Ӿ�����
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"ch_k12",
  "west" : __DIR__"ch_k14",
]));
	set("no_clean_up", 0);
	set("outdoors", "path2");
	setup();
	replace_program(ROOM);
}
