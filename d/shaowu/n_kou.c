// Room: /d/shaowu/n_kou.c

inherit ROOM;

void create()
{
	set("short", "�山��");
	set("long", @LONG
����һ��ʲ��Ҳû�еĿշ��䡣
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"tulu12",
]));

	setup();
	replace_program(ROOM);
}
