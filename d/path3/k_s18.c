// Room: /d/path3/k_s18.c

inherit DANGER_ROAD;

void create()
{
	set("short", "黄土小路");
	set("long", @LONG
这是一条黄土小路，每走一步都能带起不少尘土。你四下看
去，却荒无人迹，不由得你加快了脚步。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"k_s19",
  "north" : __DIR__"k_s17",
]));
        set("outdoors", "path3");
	setup();
	replace_program(ROOM);
}
