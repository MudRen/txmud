// Room: /d/path4/hed27.c

inherit ROOM;

void create()
{
	set("short", "青石大道");
	set("long", @LONG
这是一间什麽也没有的空房间。

LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : "/d/dali/out_dali_e",
  "east" : __DIR__"hed26",
]));
	set("outdoors", "path4");
	setup();
	replace_program(ROOM);
}
