// Room: /d/path3/k_h34.c

inherit ROOM;

void create()
{
	set("short", "林荫路");
	set("long", @LONG
这是一条林荫小路，路面不十分宽敞，但也不显得狭窄。路
边的花草红红绿绿，十分惹人喜爱。前面不远有一片小竹林，显
得格外挺拔。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "southeast" : __DIR__"k_h35",
  "north" : __DIR__"k_h33",
]));
	set("no_clean_up", 0);
	set("outdoors", "path3");
	setup();
	replace_program(ROOM);
}
