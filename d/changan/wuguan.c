// Room: /d/changan/wuguan.c

inherit ROOM;

void create()
{
	set("short", "长安武馆");
	set("long", @LONG
这里就是长安武馆，门口高高的旗杆上飘着一面红色大旗，
上绣着一个斗大的“武”字。由于长安城民风尚武，所以无论百
姓还是富绅都把弟子送到这里学一些武功。东面是武馆的练武场。
南面出门就是麒祥街。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"nroad3",
  "east"  : __DIR__"wuchang",
]));

	set("objects",([
	__DIR__"npc/dizi" : 2,
	__DIR__"npc/jiaotou" : 1,
]));
	setup();
	replace_program(ROOM);
}
