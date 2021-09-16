// Room: /wiz/uudd/path2/k_s19.c

inherit ROOM;

void create()
{
	set("short", "土路");
	set("long", @LONG
一条坑坑洼洼的土路在你脚下延伸，你向北边看去，有一座
小村庄孤零零的在那边，村口前面好象是几块农田，有几个农民
正在耕耘着。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "southwest" : __DIR__"k_s20",
  "north" : __DIR__"k_s18",
]));

	setup();
	set("outdoors", "shaolin");
	replace_program(ROOM);
}
