// Room: /d/huashan/ligou.c

inherit ROOM;

void create()
{
	set("short", "老君犁沟");
	set("long", @LONG
这是夹陡绝石壁间的一条沟状道路，有570多级石阶，壁狭
路陡，攀登艰难。传说当初太上老君在此修炼时，见人们开山凿
路太苦了，就牵来老牛，一夜之间犁出这条山沟。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "northwest" : __DIR__"qunxian",
  "northeast" : __DIR__"husunchou",
]));
        set("outdoors", "huashan");
	setup();
	replace_program(ROOM);
}
