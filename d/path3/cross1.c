// Room: /d/path3/cross1.c

inherit ROOM;

void create()
{
	set("short", "林间小道");
	set("long", @LONG
这是一片树林，西此面就是驻马店了。你走在林中，依稀可
以发现草地上路的痕迹。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "southeast" : __DIR__"cross2",
  "northwest" : __DIR__"k_s4",
]));
	set("no_clean_up", 0);
	set("outdoors", "path3");
	setup();
	replace_program(ROOM);
}
