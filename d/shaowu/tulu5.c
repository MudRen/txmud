// Room: /d/shaowu/tulu5.c

inherit ROOM;

void create()
{
	set("short", "��·");
	set("long", @LONG
����һ��ʲ��Ҳû�еĿշ��䡣
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"w_kou",
  "south" : __DIR__"tulu4",
  "east" : __DIR__"tulu6",
  "north" : __DIR__"roupu",
]));

	setup();
	replace_program(ROOM);
}
