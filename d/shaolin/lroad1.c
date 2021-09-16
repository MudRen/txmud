// Room: /d/shaolin/lroad1.c

inherit ROOM;

void create()
{
	set("short", "前院过道");
	set("long", @LONG
这里是少林寺的前院过道，过道的两边两排旱柳，绿荫荫的，
西边有一个小水池，可以听到潺潺的水声。当然，出家人不深溺
于声色，也没有人在这里驻足。从这里路过的僧人多是匆匆忙忙
的。从这里向西是功德林，向北是过道伸向远方，向南是广场左
侧。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"f_square_l",
  "north" : __DIR__"lroad2",
  "west" : __DIR__"gongde1",
]));
        set("objects",([
        __DIR__"npc/husi_seng" : 1,
]));
	set("outdoors", "shaolin");

	setup();
	replace_program(ROOM);
}
