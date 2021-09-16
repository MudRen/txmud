// Room: /d/tangmen/lcd03.c

inherit ROOM;

void create()
{
	set("short", "泥泞小路");
	set("long", @LONG
这是一条的小岔路，地上总是像刚下过雨一样泥泞不堪，和
着一些腐烂的枯枝败叶，臭气熏天。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "northeast" : __DIR__"lcd02",
  "southwest" : __DIR__"lcd04",
]));

	set("outdoors", "tangmen");
	setup();
	replace_program(ROOM);
}
