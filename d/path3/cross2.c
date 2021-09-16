// Room: /d/path3/cross2.c

inherit ROOM;

void create()
{
	set("short", "林间小道");
	set("long", @LONG
这是一片树林，你快步走在林中，仔细地寻找着草地上路的
痕迹。周围一片寂静，你心头不禁掠过一丝不安。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "southeast" : __DIR__"cross3",
  "northwest" : __DIR__"cross1",
]));
	set("no_clean_up", 0);
	set("outdoors", "path3");
	setup();
	replace_program(ROOM);
}
