// Room: /d/shaowu/tianye.c

inherit ROOM;

void create()
{
	set("short", "��Ұ");
	set("long", @LONG
����һ��ʲ��Ҳû�еĿշ��䡣
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"tulu14",
]));

	setup();
	replace_program(ROOM);
}
