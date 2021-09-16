// Room: /d/shaolin/beilin3.c

inherit ROOM;

void create()
{
	set("short", "碑林");
	set("long", @LONG
这里是少林寺的碑林，走到这里已经尽是一些残碑断垣了，
倒不是说少林寺保留地不好，因为年代的久远，风沙的吹蚀，所
不少石碑都残败了。不过这里仍有不少观光客在聚精会神的临着
着石碑上的字。从这里向北是仍是牌林，西是慈云堂。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"beilin2",
  "west" : __DIR__"ciyuntang",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
