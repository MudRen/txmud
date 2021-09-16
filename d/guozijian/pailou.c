// Room: /d/guozijian/pailou.c 

inherit ROOM; 
 
void create() 
{ 
	set("short", "琉璃牌坊");
	set("long", @LONG
你的面前屹立着一个琉璃牌坊，这个牌坊高八米，宽五米，
主体是血红色，上面刻有一些花纹，简朴但很庄重，牌楼的南北
两侧分别写有“圜桥教泽”和“学海节观”。坊内左右为黄色琉
璃瓦重檐碑亭。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
		"south" : __DIR__"yongdao2",
		"north" : __DIR__"shiqiao1",
]));

	set("outdoors","guozijian");
	setup();
	replace_program(ROOM);
}
