// Room: /d/path1/cc_tch10.c

inherit ROOM;

void create()
{
	set("short", "����·");
	set("long", @LONG
����һ��������·��·�ϵ������Ѿ�������ˡ������ڻ���
��ԭ�ϣ���ʱ�ز�Ĩ�����Ϻ��顣·��������һƬƬ�����֡�
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"cc_tch9",
  "north" : __DIR__"cc_tch11",
]));
	set("outdoors", "path1");
	setup();
	replace_program(ROOM);
}
