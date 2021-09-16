// Room: /d/huashan/jiufang.c

inherit ROOM;

void create()
{
	set("short", "酿酒房");
	set("long", @LONG
这里就是华山派的酿酒房，华山派酿的“七里香”是远近有
名的好酒。酿酒原是华山派的第一大收入，后来发现了玄铁矿，
华山铸的“华山铁剑”又大出风头，成了武林中人最常用的随身
兵器。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "northeast" : __DIR__"shanquan",
 
]));
        set("outdoors", "huashan");
	setup();
	replace_program(ROOM);
}
