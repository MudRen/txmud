// Room: /d/fengtian/xf1.c

inherit ROOM;

void create()
{
	set("short", "厢房");
	set("long", @LONG
由会客厅通过向北就到了这间厢房，厢房是将军小憩的地方
，收拾的非常雅致，这里也算将军的书房了，将军时常在这里会
见一些重要的客人。
LONG
	);

	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"jjf3",
]));

	setup();
	replace_program(ROOM);
}
