// Room: /d/path2/q1.c

inherit ROOM;

void create()
{
	set("short", "石子小路");
	set("long", @LONG
这是一条石子小路，路旁长满了蒿草，看样子不常有人走动，
向北面看去是一处破败的院落。
LONG
);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"q2",
  "southwest" : __DIR__"ch_k14",
]));

	setup();
	replace_program(ROOM);
}
