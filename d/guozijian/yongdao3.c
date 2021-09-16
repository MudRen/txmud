// Room: /d/guozijian/yongdao3.c 
 
inherit ROOM; 
 
void create() 
{ 
	set("short", "甬道");
	set("long", @LONG
这里是一条用青砖铺成的甬道，两边种植了几种蔬菜，是供
监生们使用的，颇有些回归自然的感觉，甬道东面是率性堂。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
		"west" : __DIR__"shiqiao2",
		"east" : __DIR__"shuaixing",
]));

	set("outdoors","guozijian");
	setup();
	replace_program(ROOM);
}
