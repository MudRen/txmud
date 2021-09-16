// Room: /wiz/louth/a/houlu5.c

inherit ROOM;

void create()
{
	set("short", "后山小路");
	set("long", @LONG
这是后山的一条小路，路的两旁都种着各种奇异的花草，
使人感觉芳香无比。北边有一座小亭子，掩映在花丛之中，
显得十分别致。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "northwest" : __DIR__"houlu6",
  "southwest" : __DIR__"houlu4",
]));
       set("outdoors","feiyu");
	setup();
	replace_program(ROOM);
}
