// Room: /d/shaolin/6zumiao.c

inherit ROOM;

void create()
{
	set("short", "六祖庙");
	set("long", @LONG
这里是少林寺的六祖庙，正中供有六祖慧能的法像，碧幢金
漆，南边有一块大石碑，上面刻有慧能大师当年所作的偈语：菩
提原非树，明镜亦非台。本来无一物，何处惹尘埃。从这里向西
是鼓楼，向东是西广场。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"w_square",
  "west" : __DIR__"gulou1",
]));

	set("objects",([
	__DIR__"npc/kongse" : 1,
]));

	setup();
	replace_program(ROOM);
}
