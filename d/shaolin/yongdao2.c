// Room: /d/shaolin/yongdao2.c

inherit ROOM;

void create()
{
	set("short", "青石甬道");
	set("long", @LONG
这里是少林寺的一条青石甬道，从这里向北一般的香客和游
人就不让去了，因为后院有少林的藏经阁、方丈楼等重地。从这
里向南和向北是青石甬道，西边是铜人阵入口，东面是罗汉阵入
口。
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"yongdao1",
  "north" : __DIR__"yongdao3",
  "east" : __DIR__"luohan1",
  "west" : __DIR__"tongren1",
]));
        set("objects",([
        __DIR__"npc/husi_seng" : 1,
]));
	set("outdoors", "shaolin");

	setup();
	replace_program(ROOM);
}
