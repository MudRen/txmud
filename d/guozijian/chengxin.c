// Room: /d/guozijian/chengxin.c 
 
inherit ROOM; 
 
void create() 
{ 
	set("short", "诚心堂");
	set("long", @LONG
这里是诚心堂，是监生学习的地方，这里正有几个监生站在
桌子旁边，添词和赋，不一会，就用毛笔龙飞风舞的写了起来，
看来已经小有成就。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
		"south" : __DIR__"shuaixing",
]));

	setup();
	replace_program(ROOM);
}
