// Room: /u/w/wangs/b/kai125.c

inherit ROOM;

void create()
{
	set("short", "夷林中路");
	set("long", @LONG
这是一条路面由碎石子铺就的街道，街道上人来人往，两边
是各式各样的商店铺面，应有尽有。五花八门的店铺招牌临街挑
起，不时可听见贩子们的吆喝声从街上传来。北边就是开封城的
豆腐店。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 3 */
  "southeast" : __DIR__"kai127",
  "north" : __DIR__"kai126",
  "west" : __DIR__"kai122",
]));

	set("outdoors","kaifeng");
	setup();
	replace_program(ROOM);
}
