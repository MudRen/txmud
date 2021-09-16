// Room: /d/path1/lmj2.c

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
  "southwest" : __DIR__"lmj3",
  "north" : __DIR__"lmj1",
]));

	set("objects",([
	__DIR__"npc/nongfu" : 1,
]));

	set("outdoors", "path1");
	setup();
	replace_program(ROOM);
}
