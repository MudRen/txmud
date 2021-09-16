// Room: /d/path1/zjz1.c

inherit ROOM;

void create()
{
	set("short", "山间小路");
	set("long", @LONG
这是一条山间小路，两旁地上除了碎石什么也没有。再向北
面就是赵公口，向南一条崎岖不平的山路蜿蜒而去。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"zjz2",
  "north" : __DIR__"ft_s5",
]));
	set("outdoors", "path1");
	setup();
	replace_program(ROOM);
}
