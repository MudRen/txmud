// Room: /d/guozijian/yilunup.c 
 
inherit ROOM; 
 
void create() 
{ 
	set("short", "彝伦堂二楼");
	set("long", @LONG
这里是彝伦堂的二楼，北面墙上除了挂了一幅出自名家之笔
的画，而南面则放着一块木制的牌匾。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
		"down" : __DIR__"yilun",
]));

	setup();
	replace_program(ROOM);
}
