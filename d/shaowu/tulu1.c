// Room: /d/shaowu/tulu1.c

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
  "south" : __DIR__"s_kou",
  "east" : __DIR__"nongjia",
  "north" : __DIR__"tulu2",
]));

	setup();
	replace_program(ROOM);
}
