// Room: /d/path3/k_s19.c

inherit DANGER_ROAD;

void create()
{
	set("short", "土路");
	set("long", @LONG
这是一条黄土小路，每走一步都能带起不少尘土。你四下看
去，却荒无人迹，不由得你加快了脚步。南边不时传来滔滔的水
声。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"k_s20",
  "north" : __DIR__"k_s18",
]));
        set("outdoors", "path3");
	setup();
	replace_program(ROOM);
}
