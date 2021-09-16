// Room: /d/fengtian/lf2.c

inherit ROOM;

void create()
{
	set("short", "天井");
	set("long", @LONG
这是一间什麽也没有的空房间。
LONG
	);

	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"lf1",
  "east" : __DIR__"lf3",
]));

	set("outdoors", "fengtian");
	set("cannot_build_home",1);

	setup();
	replace_program(ROOM);
}
