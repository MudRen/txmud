// Room: /d/shaolin/gulou4.c

inherit ROOM;

void create()
{
	set("short", "鼓楼四层");
	set("long", @LONG
这里是少林寺的鼓楼四层，一上楼，你首先可以看到一个巨
大的铁鼓，漆已经剥落的很多了，旁边一个很大的铁质鼓锤，少
说也行二十多斤重，近几十年来这个铁锤从没有动过。从这里向
下是鼓楼三层。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "down" : __DIR__"gulou3",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
