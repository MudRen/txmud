// Room: /d/path1/cc_tch8.c

inherit ROOM;

void create()
{
	set("short", "����·");
	set("long", @LONG
����һ��������·�������ĳ������������������ڵ��ϣ�
��ʱ�ز�Ĩ�����Ϻ��顣·��������һƬƬ���
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "northwest" : __DIR__"cc_tch9",
  "southeast" : __DIR__"cc_tch7",
]));
	set("outdoors", "path1");

	set("objects",([
	__DIR__"npc/daoke" : 1,
]));

	setup();
	replace_program(ROOM);
}
