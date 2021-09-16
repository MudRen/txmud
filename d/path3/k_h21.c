// Room: /d/path3/k_h21.c

inherit ROOM;

void create()
{
	set("short", "林间小路");
	set("long", @LONG
你走到这里，只见两边绿荫葱葱，空气清新。你忍不住大口
的呼吸着自然的气息，心情一下子放松了很多。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "southeast" : __DIR__"k_h22",
  "northwest" : __DIR__"k_h20",
]));
	set("no_clean_up", 0);
	set("outdoors", "path3");
	setup();
	replace_program(ROOM);
}
