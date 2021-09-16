// Room: /d/hangzhou/ruyanhouse.c

inherit ROOM;

void create()
{
	set("short", "如烟家");
	set("long", @LONG
这里是杭州名妓如烟的家，如烟本来住在万花楼中，因为与
杭州知府大人交好，知府特意在长安路上置办了这所住宅，用来
与如烟相聚。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"changanw4",
]));

	setup();
	replace_program(ROOM);
}
