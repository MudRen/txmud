// Room: /d/path1/lmj4.c

inherit ROOM;

void create()
{
	set("short", "��·");
	set("long", @LONG
����һ������С·��·�ı�����һ�����ϱ�����һ
ĶĶׯ�ڵء�·��ʱ�����˾�����һ����֪�Ǹ�����ũ����
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"cc_tch5",
  "east" : __DIR__"lmj3",
]));
	set("outdoors", "path1");
	setup();
	replace_program(ROOM);
}
