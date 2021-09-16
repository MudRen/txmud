// Room: /d/path5/ccg23.c

inherit ROOM;

void create()
{
	set("short", "怒江江中");
	set("long", @LONG
你挽起裤腿，小心溢溢地走在怒江江中，冰凉的江水缓缓从
你却下流过。一条不知名的小鱼正用嘴啄你的脚，你晃了晃腿，
小鱼忽地游开了一点，却依然不舍得离去。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"ccg24",
  "east" : __DIR__"ccg22",
]));
        set("outdoors", "chengdu_w");
        set("cannot_build_home", 1);
	setup();
	replace_program(ROOM);
}
