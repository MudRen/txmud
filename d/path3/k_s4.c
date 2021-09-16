// Room: /d/path3/k_s4.c

inherit ROOM;

void create()
{
	set("short", "驻马店");
	set("long", @LONG
这里是驻马店，往来的人们通常在这里歇脚。路的左边是一
家小客店，不过现在还没有开业。在道路的东侧的树边树着一个
牌子(pai)。
LONG
	);
        set("item_desc",([
	"pai":"
	north        开封府
	south        康安寨
	southeast    铜陵
\n",
	"牌子":"
	north        开封府
	south        康安寨
	southeast    铜陵
\n",
]));

	set("exits", ([ /* sizeof() == 3 */
  "southeast" : __DIR__"cross1",
  "south" : __DIR__"k_s5",
  "north" : __DIR__"k_s3",
]));

	set("outdoors", "path3");
	setup();
	replace_program(ROOM);
}
