// Room: /d/shaolin/e_wuchang.c

inherit ROOM;

void create()
{
	set("short", "���䳡");
	set("long", @LONG
����һ��ʲ��Ҳû�еĿշ��䡣
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"rroad2",
]));
	set("no_clean_up", 0);
	set("outdoors","shaolin");
	setup();
	replace_program(ROOM);
}
