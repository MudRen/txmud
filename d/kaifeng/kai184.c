// Room: /open/k/kai184.c

inherit ROOM;

void create()
{
	set("short", "武馆大院");
	set("long", @LONG
这是一间什麽也没有的空房间。

LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"kai98",
]));
        set("objects",([
        __DIR__"npc/dizi": 2,
]));

	set("outdoors","kaifeng");
	setup();
	replace_program(ROOM);
}
