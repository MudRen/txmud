// Room: /d/path3/k_s3.c

inherit ROOM;

void create()
{
	set("short", "大路");
	set("long", @LONG
这是一条宽阔的大路，路的两旁是光秃秃的山坡。一直向北
不远就是开封城了，由此再往南就到了驻马店。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"k_s4",
  "north" : __DIR__"k_s2",
]));

	set("outdoors", "path3");
	setup();
	replace_program(ROOM);
}
