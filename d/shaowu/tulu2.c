// Room: /d/shaowu/tulu2.c

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
  "west" : __DIR__"tulu3",
  "south" : __DIR__"tulu1",
  "east" : __DIR__"tulu8",
  "north" : __DIR__"shuichan",
]));

	setup();
	replace_program(ROOM);
}
