// Room: /d/guozijian/shiqiao2.c 
 
inherit ROOM; 
 
void create() 
{ 
	set("short", "石桥");
	set("long", @LONG
这里是一座小石桥，桥长二丈二尺，与壁雍相连，桥上的栏
杆上刻有一些小字，桥下是一条小河，河水是从太学门外东西井
亭处引来的，河里开满了荷花，使你从很远处就可以闻到阵阵花
香。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
		"west" : __DIR__"by_east",
		"east" : __DIR__"yongdao3",
]));

	set("outdoors","guozijian");
	setup();
	replace_program(ROOM);
}
