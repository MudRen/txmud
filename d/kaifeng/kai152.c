// Room: /u/w/wangs/b/kai152.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
����һ��ʲ��Ҳû�еĿշ��䡣
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"kai149",
]));

	setup();
	replace_program(ROOM);
}
