// Room: /d/path1/lmj1.c

inherit ROOM;

void create()
{
	set("short", "С·");
	set("long", @LONG
һ������С·ͨ��ǰ����·�������һ�����ұ�����һ
ĶĶׯ�ڵء�·��ʱ�����˾�����һ����֪�Ǹ�����ũ����
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"lmj2",
  "north" : __DIR__"py10",
]));

	set("objects",([
	__DIR__"npc/nongfu" : 1,
]));

	set("outdoors", "path1");
	setup();
	replace_program(ROOM);
}
