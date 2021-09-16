// Room: /u/w/wangs/b/kai4.c

inherit ROOM;

void create()
{
	set("short", "虹日路");
	set("long", @LONG
这条路通向开封城内的一些休闲景点，因而路两旁全都种满
了柔美的垂柳。路上偶然能看到几名外地来的游客正对着路边的
景致指指点点。你呼吸着清新的空气，耳边再无噪杂的尘世喧嚣，
心情顿时为之一畅。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"kai9",
  "south" : __DIR__"kai3",
  "west" : __DIR__"kai7",
]));

	set("outdoors","kaifeng");
	setup();
	replace_program(ROOM);
}
