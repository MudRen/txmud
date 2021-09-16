// Room: /u/w/wangs/a/yu67.c

inherit ROOM;

void create()
{
	set("short", "梅花园");
	set("long", @LONG
这里种满了梅树，花色深浅一如桃花，蒂垂丝作海棠状，
香气宜人，不禁使你想起“梅花香自苦寒来”的绝句，若有
所悟。
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"yu64",
  "north" : __DIR__"yu64",
  "west" : __DIR__"yu57",
  "east" : __DIR__"yu100",
]));
       set("outdoors","feiyu");

	setup();
	replace_program(ROOM);
}
