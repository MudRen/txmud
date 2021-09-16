// Room: /d/path1/ft_s15.c

inherit ROOM;

void create()
{
	set("short", "青石官道");
	set("long", @LONG
这是奉天城南门外一条青石铺成的官道，来来往往的行人商
旅脚步匆匆。几个捕快骑马抢道向南而去，一看就知是有要案在
身。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"ft_s14",
  "north" : __DIR__"ft_s16",
]));
	set("outdoors", "path1");
	setup();
	replace_program(ROOM);
}
