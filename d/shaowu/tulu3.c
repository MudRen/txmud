// Room: /d/shaowu/tulu3.c

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
  "south" : __DIR__"kedian",
  "east" : __DIR__"tulu2",
  "north" : __DIR__"tulu4",
]));

	setup();
	replace_program(ROOM);
}
