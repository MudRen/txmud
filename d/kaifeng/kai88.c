// Room: /u/w/wangs/b/kai88.c

inherit ROOM;

void create()
{
	set("short", "夷林路");
	set("long", @LONG
这是一条路面由青石铺就的街道，街道上人来人往，两边是
各式各样的商店铺面酒馆药房等等，应有尽有。五花八门的招牌
临街挑起，不时可听见贩子们的吆喝声从街上传来。这里的东北
通向夷林北路。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "northeast" : __DIR__"kai119",
  "west" : __DIR__"kai86",
]));

	set("outdoors","kaifeng");
	setup();
	replace_program(ROOM);
}
