// Room: /d/huashan/shitai.c

inherit ROOM;

void create()
{
	set("short", "石台");
	set("long", @LONG
洞的左边有一个石台，和床一般大小，摸上去有些温暖的感
觉，到像是用玉制成的。但找这么大的玉似乎不大可能。还是先
去里面看看吧！
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"dongkou",
  "north" : __DIR__"dongtian",
]));

set("item_desc", ([
	"床" : "你弯下身去，仔细地向床看去。只见床的侧面刻着
一行小字“苦玉温床”。你不禁心中一动！\n",
]));
	setup();
	replace_program(ROOM);
}
