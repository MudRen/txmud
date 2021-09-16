// Room: /wiz/louth/k/kai20.c

inherit ROOM;

void create()
{
	set("short", "民居");
	set("long", @LONG
这是一所普通的民居，屋内的陈设非常简朴，可是四处都收
拾的紧趁利落，可见主人是是一位精明能干之人。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"kai19",
]));
        set("objects",([
        __DIR__"npc/laohan": 1,
]));

	setup();
	replace_program(ROOM);
}
