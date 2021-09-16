// Room: /d/guozijian/xi_jiting.c 
 
inherit ROOM; 
 
void create() 
{ 
	set("short", "西井亭");
	set("long", @LONG
这里是西井亭，这里是一片绿地，偶尔有一俩只兔子跳来跳
去，两边房子的门都锁着，东面是一条青石甬道。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
		"east" : __DIR__"yongdao1",
]));

	set("outdoors","guozijian");
	setup();
	replace_program(ROOM);
}
