// Room: /d/huashan/xiaolu3.c

inherit ROOM;

void create()
{
	set("short", "林间小路");
	set("long", @LONG
一些苔生植物铺满了小路。你走在小路上，不得不打起十分
精神。风一吹来，树叫沙沙地作响，林中传来溪水流动的声音。
你掉头望去，却找不到水在何处。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "northup" : __DIR__"juling_zu",
  "southdown" : __DIR__"xiaozi_feng",
]));
        set("outdoors", "huashan");
	setup();
	replace_program(ROOM);
}
