// Room: /u/w/wangs/b/kai19.c

inherit ROOM;

void create()
{
	set("short", "虹日路");
	set("long", @LONG
这条路通向开封城内的一些休闲景点，因而路两旁全都种满
了柔美的垂柳。路上偶然能看到几名外地来的游客正对着路边的
景致指指点点。这里是虹日路的尽头了，往南是风景如画的休闲
胜地，东边是一条黑乎乎的小巷。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"kai16",
  "west" : __DIR__"kai20",
  "east" : __DIR__"kai21",
]));

	set("outdoors","kaifeng");
	setup();
	replace_program(ROOM);
}
