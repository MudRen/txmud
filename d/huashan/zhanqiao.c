// Room: /d/huashan/zhanqiao.c

inherit ROOM;

void create()
{
	set("short", "空中栈桥");
	set("long", @LONG
这是一座架在两山之间的栈桥，桥下浮云游过，雾气漫漫，
恍若仙境。华山派自从发现了这个矿场，为了采矿就修了这座栈
桥。东边有几个华山派弟子在守着，你如果不是华山派的人，到
这里观光一下就算了，别再向东去了。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
 
  "west" : __DIR__"shanlu2",
  "east":__DIR__"luoyun",
]));

	set("outdoors", "huashan");
	setup();
	replace_program(ROOM);
}
