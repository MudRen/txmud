// Room: /wiz/uudd/path2/k_s14.c

inherit ROOM;

void create()
{
	set("short", "土路");
	set("long", @LONG
小路在这里分成了三个方向，西边是一片茂密的树林，东面
是一个伐木厂，不时传来一阵阵锯木头的声音，北边就是有名的
李记狗肉店，一阵阵狗肉的香味扑鼻而来。
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"tree",
  "east" : __DIR__"woodfac",
  "south" : __DIR__"k_s13",
  "north" : __DIR__"liroom",
]));

	setup();
	set("outdoors", "shaolin");
	replace_program(ROOM);
}
