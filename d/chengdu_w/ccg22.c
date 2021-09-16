// Room: /d/path5/ccg22.c

inherit ROOM;

void create()
{
	set("short", "怒江东岸边");
	set("long", @LONG
你来到怒江东岸岸边，江水并不很深，水流也不算急，你甚
至可以看清河底的石头和游动的鱼。江水十分清澈，你不禁想打
些水来喝，或者以备后用。这里步行就可以淌过。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"ccg23",
  "east" : __DIR__"ccg21",
]));
        set("outdoors", "chengdu_w");
	set("resource/water", 1);
        set("cannot_build_home", 1);
	setup();
	replace_program(ROOM);
}
