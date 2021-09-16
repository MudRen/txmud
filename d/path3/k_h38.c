// Room: /d/path3/k_h38.c

inherit ROOM;

void create()
{
	set("short", "青石官道");
	set("long", @LONG
这是一条用青石铺成的官道，道路上人来人往，显得十分热
闹。你边走边看，也说不清是不是想买些什么。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"k_h39",
  "north" : __DIR__"k_h37",
]));
	set("no_clean_up", 0);
	set("outdoors", "path3");
	setup();
	replace_program(ROOM);
}
