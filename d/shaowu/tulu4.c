// Room: /d/shaowu/tulu4.c

inherit ROOM;

void create()
{
	set("short", "��·");
	set("long", @LONG
����һ��ʲ��Ҳû�еĿշ��䡣
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"caodi",
  "south" : __DIR__"tulu3",
  "north" : __DIR__"tulu5",
]));

	setup();
	replace_program(ROOM);
}
