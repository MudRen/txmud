// Room: /d/paiyun/lu5.c

inherit ROOM;

void create()
{
	set("short", "小路");
	set("long", @LONG
一条小路弯弯曲曲向山林的深处延伸，路旁是郁郁葱葱树林
，驻足路旁你可以闻到空气里绿色的味道（wen〕。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"lu6",
  "west" : __DIR__"lu4",
  "east" : __DIR__"ta3",
  "north" : __DIR__"lu7",
]));
	set("outdoors", "paiyun");
	setup();
	replace_program(ROOM);
}
