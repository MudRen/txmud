// Room: /d/shaowu/tulu12.c

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
  "west" : __DIR__"zahuo",
  "south" : __DIR__"tulu11",
  "north" : __DIR__"n_kou",
]));

	setup();
	replace_program(ROOM);
}
