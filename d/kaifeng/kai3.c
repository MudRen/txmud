// Room: /u/w/wangs/b/kai3.c

inherit ROOM;

void create()
{
	set("short", "虹日路");
	set("long", @LONG
这条路通向开封城内的一些休闲景点，因而路两旁全都种满
了柔美的垂柳。虹日路原先不叫虹日路的，只是因为在数十年前，
当时还是江湖中无名小卒的大侠战天龙在这里以一招“白虹贯日”
一剑取走为祸武林的采花巨盗花怜心的首级。后人为了记念这惊
天动地的一剑，便将这条路叫做虹日路了。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"kai4",
  "south" : __DIR__"kai2",
  "east" : __DIR__"kai5",
]));

	set("outdoors","kaifeng");
	setup();
	replace_program(ROOM);
}
