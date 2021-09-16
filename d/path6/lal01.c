// Room: /d/xizang/lal01.c

inherit ROOM;

void create()
{
	set("short", "高原山道");
	set("long", @LONG
你走在高原山路上，稀薄的空气使你逐渐感到不适，看来这
就是高山反映了，你只好慢下了脚步。由此再向东就是林芝了。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "east" : "/d/xizang/linzhiw",
  "west" : __DIR__"lal02",
]));
        set("outdoors", "path6");
        set("cannot_build_home", 1);
        set("altitude", 4100);
	setup();
	replace_program(ROOM);
}
