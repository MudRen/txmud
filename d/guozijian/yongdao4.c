// Room: /d/guozijian/yongdao4.c 
 
inherit ROOM; 
 
void create() 
{ 
	set("short", "甬道");
	set("long", @LONG
这里是一条用青砖铺成的甬道，两边为墀，是诸生列队欢迎
皇帝的地方，甬道的北侧通向彝伦堂。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
		"north" : __DIR__"yilun",
		"south" : __DIR__"shiqiao3",
]));

	set("outdoors","guozijian");
	setup();
	replace_program(ROOM);
}
