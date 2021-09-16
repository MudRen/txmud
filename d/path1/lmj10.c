// Room: /d/path1/lmj10.c

inherit DANGER_ROAD;

void create()
{
	set("short", "羊肠小道");
	set("long", @LONG
这是一条弯弯的羊肠小道，路的一边都是庄稼地，地里的农
户正牵着老牛耕作。北面一条小路通向鹿马集的南口。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"lmj9",
  "east" : __DIR__"lmj11",
  "north" : "/d/lumaji/s_kou",
]));
	set("outdoors", "path1");
	setup();
	replace_program(ROOM);
}
