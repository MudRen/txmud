// Room: /d/hangzhou/zfwife2.c

inherit ROOM;

void create()
{
	set("short", "二夫人卧房");
	set("long", @LONG
这是杭州知府二夫人的房间，二夫人是知府大人早年在别地
当知县时所娶的贫家女子，为知府生有一女。二夫人的房间陈设
的甚是简朴。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"zfpath9",
]));

	setup();
	replace_program(ROOM);
}
