// Room: /d/fengtian/lang1.c

inherit ROOM;

void create()
{
	set("short", "走廊");
	set("long", @LONG
这里是通往后花园的走廊，这里可以远远看见将军府的后院
，不过一拐弯就可以先到厨房了。
LONG
	);

	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"chufang",
  "north" : __DIR__"jjf3",
]));

	setup();
	replace_program(ROOM);
}
