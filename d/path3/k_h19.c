// Room: /d/path3/k_h19.c

inherit ROOM;

void create()
{
	set("short", "山路");
	set("long", @LONG
这里是牛头山山脚，山上林树幽动，似乎有人在里面。路上
几乎看不到什么行人，你不禁快步向前。南面是一片树林。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "southeast" : __DIR__"k_h20",
  "northwest" : __DIR__"k_h18",
]));
	set("no_clean_up", 0);
	set("outdoors", "path3");
	setup();
	replace_program(ROOM);
}
