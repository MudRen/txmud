// Room: /open/k/kai98.c

inherit ROOM;

void create()
{
	set("short", "���");
	set("long", @LONG
??
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"kai184",
  "east" : __DIR__"kai97",
]));
        set("objects",([
        __DIR__"npc/dizi": 2,
]));

	setup();
	replace_program(ROOM);
}
