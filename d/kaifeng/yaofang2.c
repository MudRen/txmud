// Room: /d/kaifeng/yaofang2.c

inherit ROOM;

void create()
{
	set("short", "药铺账房");
	set("long", @LONG
这是一间什麽也没有的空房间。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"kai111",
]));

	set("objects",([
	__DIR__"npc/doctor_hu" : 1,
]));

	setup();
	replace_program(ROOM);
}
