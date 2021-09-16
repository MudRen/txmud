// Room: /d/path1/lmj6.c

inherit DANGER_ROAD;

void create()
{
	set("short", "羊肠小道");
	set("long", @LONG
这是一条弯弯的羊肠小道，路的两边都是庄稼地。地里的农
户正牵着老牛耕作。不时传来牧童悠扬的笛声。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "northwest" : __DIR__"lmj5",
  "southeast" : __DIR__"lmj7",
]));
	set("outdoors", "path1");
	setup();
	replace_program(ROOM);
}
