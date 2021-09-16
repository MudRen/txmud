// Room: /d/path3/k_h36.c

inherit ROOM;

void create()
{
	set("short", "石土路");
	set("long", @LONG
这是一条石土路，路的一侧都是一些水稻田，而另一侧则盖
有几间小茅草屋。几个农汉正围在一堆儿抽烟聊天，不时传来阵
阵笑声。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"k_h37",
  "north" : __DIR__"k_h35",
]));
	set("no_clean_up", 0);
	set("outdoors", "path3");
	setup();
	replace_program(ROOM);
}
