// Room: /d/shaowu/zahuo.c

inherit ROOM;

void create()
{
	set("short", "�ӻ���");
	set("long", @LONG
����һ��ʲ��Ҳû�еĿշ��䡣
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"tulu12",
]));

	setup();
	replace_program(ROOM);
}
