// Room: /wiz/louth/a/yu58.c

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
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"road1",
  "southup" : __DIR__"yu59",
  "north" : __DIR__"yu57",
]));
       set("outdoors","feiyu");

	setup();
	replace_program(ROOM);
}
