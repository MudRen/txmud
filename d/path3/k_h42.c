// Room: /d/path3/k_h42.c

inherit ROOM;

void create()
{
	set("short", "��ʯ�ٵ�");
	set("long", @LONG
����һ��ʲ��Ҳû�еĿշ��䡣
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"k_h41",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
