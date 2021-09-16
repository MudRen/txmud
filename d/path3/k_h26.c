// Room: /d/path3/k_h26.c

inherit ROOM;

void create()
{
	set("short", "土路");
	set("long", @LONG
你走到这里，只见路的两边到处都是鱼贩，叫卖声，讨价声
此起彼伏。再向南走，就是长江渡口了。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"k_h27",
  "north" : __DIR__"k_h25",
]));
	set("no_clean_up", 0);
	set("outdoors", "path3");
	setup();
	replace_program(ROOM);
}
