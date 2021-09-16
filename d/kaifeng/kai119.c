// Room: /open/k/kai119.c

inherit ROOM;

void create()
{
	set("short", "夷林北路");
	set("long", @LONG
这是一条路面由青石铺就的街道，街道上人来人往，两边是
各式各样的商店铺面，应有尽有。五花八门的招牌临街挑起，不
时可听见贩子们的吆喝声从街上传来。南边就是开封城最好的乐
器店。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 3 */
  "southwest" : __DIR__"kai88",
  "east" : __DIR__"kai122",
  "south" : __DIR__"kai121",
]));

	set("outdoors","kaifeng");
	setup();
	replace_program(ROOM);
}
