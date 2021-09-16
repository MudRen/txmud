// Room: /wiz/uudd/path2/jing.c

inherit ROOM;

void create()
{
	set("short", "水井");
	set("long", @LONG
这是一口极深的水井，用石块沏成圆桶状的井沿上支着一幅
用整根树段砍成的辘辘，你扒在井口往下望去，井里黑乎乎的，
什么也看不到。井沿周围到处是水渍、脚印，看来经常有人到这
里打水。你可以在这里打水喝(drink)。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"k_s10",
]));

	setup();
	set("outdoors", "shaolin");
	replace_program(ROOM);
}
