// Room: /u/w/wangs/a/yu38.c

inherit ROOM;

void create()
{
	set("short", "走廊");
	set("long", @LONG
走进了走廊，亦离开了百花争艳的后院，看到的却是另
一番不同的景致。廊两边种植了大片的松柏，郁郁葱葱，很
是静谧，除了阵阵鸟语与微风吹拂下的树叶沙沙声外，听不
到任何人为的声音。弯弯曲曲的走廊通向树林深处。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "southeast" : __DIR__"yu39",
  "west" : __DIR__"yu37",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
