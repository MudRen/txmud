// Room: /d/hangzhou/stree3.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
����һ��ʲ��Ҳû�еĿշ��䡣
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"spath3",
  "west" : __DIR__"spath1",
]));
	set("outdoors", "hangzhou");

	setup();
	replace_program(ROOM);
}