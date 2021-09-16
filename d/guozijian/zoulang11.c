// Room: /d/guozijian/zoulang11.c 
 
inherit ROOM; 
 
void create() 
{ 
	set("short", "走廊");
	set("long", @LONG
这里是一个长长的环型走廊，正好绕辟雍一周，走廊的外侧
均是汉白玉栏杆，栏杆外面是一条小河，河里正盛开着荷花，阵
阵花香使你陶醉，偶尔还能看见河里的大红鲤鱼游过，小河的对
岸有一个喷水龙头，正将清澈的水喷向空中，不时有几滴小水珠
落在你的身上。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
		"north" : __DIR__"zoulang10",
		"east" : __DIR__"zoulang12",
]));

	set("outdoors","guozijian");
	setup();
	replace_program(ROOM);
}