// Room: /d/guozijian/yongdao2.c 
 
inherit ROOM; 
 
void create() 
{ 
	set("short", "甬道");
	set("long", @LONG
这里是一条用青砖铺成的甬道，两边长满了青草，甬道北面
立着一个牌坊，，南面则是太学门，东侧是钟亭，西侧是鼓亭。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
		"north" : __DIR__"pailou",
		"south" : __DIR__"tx_gate",
]));

	set("outdoors","guozijian");
	setup();
	replace_program(ROOM);
}
