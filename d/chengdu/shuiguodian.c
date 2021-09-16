// Room: /wiz/louth/c/shuiguodian.c

inherit ROOM;

void create()
{
	set("short", "水果店");
	set("long", @LONG
这是成都的一家很有名气的水果店，每年各地的水果贩子都
会来这里销售他们那里特产的水果。所以每年这个水果店都会有
各地的奇珍异果出售。从这里出去就是万明路。
LONG
	);
	set("exits", ([
  "northeast" : __DIR__"dian2",
  "south" : __DIR__"wmlu5",
]));
        set("objects",([
        __DIR__"npc/xinboss" : 1,
]));

	setup();
	replace_program(ROOM);
}
