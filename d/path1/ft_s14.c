// Room: /d/path1/ft_s14.c

inherit ROOM;

void create()
{
	set("short", "青石官道");
	set("long", @LONG
这是奉天城南门外一条青石铺成的官道，路上的行人越来越
多，向南则是一片树林。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"ft_s13",
  "north" : __DIR__"ft_s15",
]));
	set("outdoors", "path1");
	setup();
	replace_program(ROOM);
}
