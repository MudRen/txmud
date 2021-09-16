// Room: /d/path1/ft_s18.c

inherit ROOM;

void create()
{
	set("short", "青石官道");
	set("long", @LONG
这是奉天城南门外一条青石铺成的官道，北面就是奉天城的
南门了。进进出出的人流拥挤在这里，你可要小心些，在这种地
方，可要看好了自已的钱财。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "north" : "/d/fengtian/out_fengtian_s",
  "south" : __DIR__"ft_s17",
]));
	set("outdoors", "path1");
	setup();
	replace_program(ROOM);
}
