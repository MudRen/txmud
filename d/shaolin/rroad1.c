// Room: /d/shaolin/rroad1.c

inherit ROOM;

void create()
{
	set("short", "前院过道");
	set("long", @LONG
这里是少林寺的前院过道，两边的大红墙上写有“佛”字，
显得很古朴。在不远处的草坪上两三只孔雀自在的漫步着，这是
前不久来自大理的僧人送给少林的。从这里向东是碑林，向南是
前院广场的右侧。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"f_square_r",
  "north" : __DIR__"rroad2",
  "east" : __DIR__"beilin1",
]));
        set("objects",([
        __DIR__"npc/husi_seng" : 1,
]));
	set("outdoors", "shaolin");

	setup();
	replace_program(ROOM);
}
