// Room: /d/shaowu/tulu14.c

inherit ROOM;

void create()
{
	set("short", "�շ���");
	set("long", @LONG
����һ��ʲ��Ҳû�еĿշ��䡣
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"tulu13",
  "east" : __DIR__"tianye",
  "north" : __DIR__"chitang",
]));

	setup();
	replace_program(ROOM);
}