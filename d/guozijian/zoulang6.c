// Room: /d/guozijian/zoulang6.c 
 
inherit ROOM; 
 
void create() 
{ 
	set("short", "走廊");
	set("long", @LONG
这里是一个长长的环型走廊，正好绕辟雍一周，走廊的外侧
均是汉白玉栏杆，栏杆外面是一条小河，河里正盛开着荷花，阵
阵花香使你陶醉，偶尔还能看见河里的大红鲤鱼游过，真是人见
仙境啊。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
		"west" : __DIR__"by_north",
		"east" : __DIR__"zoulang5",
]));

	set("outdoors","guozijian");
	setup();
	replace_program(ROOM);
}