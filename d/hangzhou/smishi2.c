// Room: /d/hangzhou/smishi2.c

inherit ROOM;

void create()
{
	set("short", "密室");
	set("long", @LONG
这是一间什麽也没有的空房间。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"smishi4",
  "west" : __DIR__"smishi1",
  "east" : __DIR__"smishi3",
]));

	setup();
	replace_program(ROOM);
}
