// Room: /d/path1/lmj3.c

inherit ROOM;

void create()
{
	set("short", "��·");
	set("long", @LONG
����һ������С·��·�������һ�����ұ�����һ
ĶĶׯ�ڵء�·��ʱ�����˾�����һ����֪�Ǹ�����ũ����
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"lmj4",
  "northeast" : __DIR__"lmj2",
  "southeast" : __DIR__"lmj5",
]));
	set("outdoors", "path1");
	setup();
	replace_program(ROOM);
}
