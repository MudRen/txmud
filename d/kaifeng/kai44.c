// Room: /wiz/louth/k/kai44.c

inherit ROOM;

void create()
{
	set("short", "内室");
	set("long", @LONG
这是一间什麽也没有的空房间。

LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"kai38",
]));

	setup();
	replace_program(ROOM);
}
