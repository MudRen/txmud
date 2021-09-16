// Room: /d/path3/k_h4.c

inherit ROOM;

void create()
{
	set("short", "土路");
	set("long", @LONG
这是一条土路，坑坑洼洼的十分难走，你不得不十分地注意
着脚下，搞不好就要拌上一跤。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"k_h3",
  "east" : __DIR__"k_h5",
]));
	set("no_clean_up", 0);
	set("outdoors", "path3");
	setup();
	replace_program(ROOM);
}
