// Room: /wiz/louth/a/houlu2.c

inherit ROOM;

void create()
{
	set("short", "后山小路");
	set("long", @LONG
这是后山的一条小路，路的两旁都种着各种奇异的花草，
使人感觉芳香无比。漫步在这条小路上，有一种心旷神怡的
感觉。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"houlu3",
  "south" : __DIR__"houlu1",
]));
       set("outdoors","feiyu");
	setup();
	replace_program(ROOM);
}
