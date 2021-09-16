// Room: /d/path3/cross3.c

inherit ROOM;

void create()
{
	set("short", "山脚小路");
	set("long", @LONG
这是一片树林，你快步走在林中，仔细地寻找着草地上路的
痕迹。周围一片寂静，你心头不禁掠过一丝不安。前面隐约一座
大山，那就是马鞍山了。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "southeast" : __DIR__"cross4",
  "northwest" : __DIR__"cross2",
]));
	set("no_clean_up", 0);
	set("outdoors", "path3");
	setup();
	replace_program(ROOM);
}
