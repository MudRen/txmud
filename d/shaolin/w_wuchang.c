// Room: /d/shaolin/w_wuchang.c

inherit ROOM;

void create()
{
	set("short", "���䳡");
	set("long", @LONG
����һ��ʲ��Ҳû�еĿշ��䡣
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"lroad2",
]));
	set("no_clean_up", 0);
	set("outdoors","shaolin");
	setup();
	replace_program(ROOM);
}
