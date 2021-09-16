// Room: /d/huashan/xiaolu5.c

inherit ROOM;

void create()
{
	set("short", "林间小路");
	set("long", @LONG
这是一个叉路口，抬眼望去，全是丛丛的树林。你走在小路
上，耳边传来一阵流水声。北面是上山的小路，侧面还有一条小
路向东弯延。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 3 */
  "northup" : __DIR__"xiaolu6",
  "east" : __DIR__"quanshui",
  "southwest" : __DIR__"lin2",
]));
        set("outdoors", "huashan");
	setup();
	replace_program(ROOM);
}
