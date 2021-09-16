// Room: /d/path3/k_s10.c

inherit ROOM;

void create()
{
	set("short", "竹林路");
	set("long", @LONG
你走在小路上，两边稀稀落落的长着一些竹子，有些已经枯
黄了。风一吹过，竹叶发出哗哗的声响。由此再向北走就到康安
寨了。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"k_s11",
  "north" : __DIR__"k_s9",
]));
        set("outdoors", "path3");
	setup();
	replace_program(ROOM);
}
