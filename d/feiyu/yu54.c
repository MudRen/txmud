// Room: /u/w/wangs/a/yu54.c

inherit ROOM;

void create()
{
	set("short", "梅林小路");
	set("long", @LONG
这里种满了梅树，花色深浅一如桃花，蒂垂丝作海棠状，
香气宜人，不禁使你想起“梅花香自苦寒来”的绝句，若有
所悟。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "southwest" : __DIR__"yu53",
  "northeast" : __DIR__"yu55",
]));
       set("outdoors","feiyu");

	setup();
	replace_program(ROOM);
}
