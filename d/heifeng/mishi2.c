// Room: /d/heifeng/mishi2.c

inherit LIGHT_ROOM;

void create()
{
	set("short", "密室");
	set("long", @LONG
这是一间什麽也没有的空房间。
LONG
	);

	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"midao4",
]));

	setup();
}
