// Room: /d/path1/ft_s17.c

inherit ROOM;

void create()
{
	set("short", "青石官道");
	set("long", @LONG
这是奉天城南门外一条青石铺成的官道，来来往往的行人商
旅脚步匆匆。一些小贩看见你走过来，推着小车向你大声地叫喊
着。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"ft_s16",
  "north" : __DIR__"ft_s18",
]));
	set("outdoors", "path1");
	setup();
	replace_program(ROOM);
}
