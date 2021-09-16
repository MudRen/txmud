// Room: /u/w/wangs/b/kai135.c

inherit ROOM;

void create()
{
	set("short", "夷林东路");
	set("long", @LONG
这是一条路面由碎石子铺就的街道，街道上人来人往，两边
是各式各样的商店铺面，应有尽有。五花八门的店铺招牌临街挑
起，不时可听见贩子们的吆喝声从街上传来。从这里在往北就是
开封城的东大街。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "southwest" : __DIR__"kai147",
  "northeast" : __DIR__"kai133",
]));

	set("outdoors","kaifeng");
	setup();
	replace_program(ROOM);
}
