// Room: /d/shaowu/tulu11.c

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
  "south" : __DIR__"shijing",
  "east" : __DIR__"tiejiang",
  "north" : __DIR__"tulu12",
]));

	setup();
	replace_program(ROOM);
}
