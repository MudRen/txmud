// Room: /d/path3/k_s9.c

inherit ROOM;

void create()
{
	set("short", "康安寨");
	set("long", @LONG
这里就是江湖中无人不知的康安寨了，镇上的一切都是寨主
康金刀的产业。据闻此人为人豪爽，广交好友，江湖中人无论谁
有困难来到这里他都会伸一把手。不少成名人士都受过他的帮助，
再加上康金刀为富济贫，出手大方，这里也就成了江湖中避难的
好场所。来到这里的，不论多大仇恨，都不在他地界上动手。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"k_s10",
  "north" : __DIR__"k_s8",
]));
	set("outdoors", "path3");
	setup();
	replace_program(ROOM);
}
