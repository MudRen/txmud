// Room: /d/shaowu/chitang.c

inherit ROOM;

void create()
{
	set("short", "С����");
	set("long", @LONG
����һ��ʲ��Ҳû�еĿշ��䡣
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"tulu14",
]));

	setup();
	replace_program(ROOM);
}
