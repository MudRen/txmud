// Room: /d/guozijian/yongdao1.c 
 
inherit ROOM; 
 
void create() 
{ 
	set("short", "甬道");
	set("long", @LONG
这里是一条用青砖铺成的甬道，两边长满了青草，每隔几米
种了一颗柏树，柏树的树干看起来苍劲古朴，恐怕至少有几百年
的历史了，甬道北面通向太学门，南面则是集贤门，东西两侧是
井亭。
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
		"west" : __DIR__"xi_jiting",
		"east" : __DIR__"dong_jiting",
		"north" : __DIR__"tx_gate",
		"south" : __DIR__"gzj_gate",
]));

	set("NORIDE","此处为国家文考重地，文官下轿，武官下马。\n");
	set("outdoors","guozijian");
	setup();
	replace_program(ROOM);
}
