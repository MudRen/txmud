// Room: /d/hangzhou/fishshop.c

inherit ROOM;

void create()
{
	set("short", "鲜鱼店");
	set("long", @LONG
这是一间不太大的鱼店，一进门，你就看到正墙上挂了一幅
独钓寒江雪的水墨山水，看来老板不光是会做生意，还是一位饱
学之士。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"guotaie1",
]));

	setup();
	replace_program(ROOM);
}
