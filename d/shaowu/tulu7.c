// Room: /d/shaowu/tulu7.c

inherit ROOM;

void create()
{
	set("short", "��·");
	set("long", @LONG
����һ��ʲ��Ҳû�еĿշ��䡣
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"tulu6",
  "east" : __DIR__"shijing",
]));

	setup();
	replace_program(ROOM);
}
