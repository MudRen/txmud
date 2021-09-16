// Room: /d/hangzhou/smishi1.c

inherit ROOM;

void create()
{
	set("short", "密室");
	set("long", @LONG
这是一间什麽也没有的空房间。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"huolong",
  "east" : __DIR__"smishi2",
]));

	setup();
	replace_program(ROOM);
}
