// Room: /d/guozijian/xiudao.c 
 
inherit ROOM; 
 
void create() 
{ 
	set("short", "修道堂");
	set("long", @LONG
这里是修道堂，是监生学习的地方，在这里主要是修德行，
朝廷的官员每隔一端时间，就得来这里修行一段时间。当然，在
这里，就没有官的等级了，但行事还是要小心，否则等他们修行
结束，一定会给你定制一双七寸小鞋。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
		"south" : __DIR__"zhengyi",
		"north" : __DIR__"guangye",
		"east" : __DIR__"yongdao5",
]));

	setup();
	replace_program(ROOM);
}
