// Room: /d/shaowu/s_kou.c

inherit ROOM;

void create()
{
	set("short", "���Ͽ�");
	set("long", @LONG
����һ��ʲ��Ҳû�еĿշ��䡣
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"tulu1",
]));

	setup();
	replace_program(ROOM);
}
