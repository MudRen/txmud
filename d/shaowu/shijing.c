// Room: /d/shaowu/shijing.c

inherit ROOM;

void create()
{
	set("short", "ʯ��");
	set("long", @LONG
����һ��ʲ��Ҳû�еĿշ��䡣
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"tulu10",
  "west" : __DIR__"tulu7",
  "east" : __DIR__"tulu13",
  "north" : __DIR__"tulu11",
]));

	setup();
	replace_program(ROOM);
}
