// Room: /d/huashan/yy_dong.c

inherit ROOM;

void create()
{
	set("short", "迎阳洞");
	set("long", @LONG
这是一个天然的石洞，洞内透出一股湿气。下垂的钟乳石不
时地滴下一滴滴水珠，发出各种各样的声响。洞的深处放有一些
干草，像是有人在这里休息。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "southdown" : __DIR__"lin1",
]));

	setup();
	replace_program(ROOM);
}
