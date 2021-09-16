// Room: /d/path2/da_hou9.c

inherit ROOM;

void create()
{
	set("short", "土路");
	set("long", @LONG
你走在一条黄土小路上，不时停下来擦擦汗珠，看着无尽的
道路，心中泛起一阵迷惘。前面不远就是候马集了。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"da_hou8",
  "south" : __DIR__"da_hou10",
]));
	set("no_clean_up", 0);
	set("outdoors", "path2");
	setup();
	replace_program(ROOM);
}
