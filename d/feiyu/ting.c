// Room: /wiz/louth/a/ting.c

inherit ROOM;

void create()
{
	set("short", "绯雨听竹轩");
	set("long", @LONG
这是一间什麽也没有的空房间。
LONG
	);

	set(SAFE_ENV,1);

	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/yedie" : 1,
]));
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"caodi5",
]));

	setup();
	replace_program(ROOM);
}
