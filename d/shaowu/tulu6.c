// Room: /d/shaowu/tulu6.c

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
  "west" : __DIR__"tulu5",
  "east" : __DIR__"tulu7",
  "north" : __DIR__"gengdi",
]));

	setup();
	replace_program(ROOM);
}
