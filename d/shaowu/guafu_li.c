// Room: /d/shaowu/guafu_li.c

inherit ROOM;

void create()
{
	set("short", "��Ѹ���");
	set("long", @LONG
����һ��ʲ��Ҳû�еĿշ��䡣
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"tulu10",
]));

	setup();
	replace_program(ROOM);
}
