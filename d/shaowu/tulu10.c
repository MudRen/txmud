// Room: /d/shaowu/tulu10.c

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
  "west" : __DIR__"guafu_li",
  "south" : __DIR__"tulu9",
  "east" : __DIR__"doufu",
  "north" : __DIR__"shijing",
]));

	setup();
	replace_program(ROOM);
}
