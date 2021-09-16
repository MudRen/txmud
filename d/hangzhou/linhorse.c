// Room: /d/hangzhou/linhorse.c

inherit ROOM;

void create()
{
	set("short", "马圈");
	set("long", @LONG
这里有数间马圈一字排开，里面的马匹更是匹匹膘肥体壮，
毛色光鲜，有的仰头长嘶，有的低首摆尾。看来林员外甚是爱惜
这些马匹，而这里也确实匹匹都是千里挑一的好马。
LONG
	);

	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"linyuanzi",
]));

	set("objects",([
	RIDE_DIR"zouluo" : 1,
]));

	setup();
	replace_program(ROOM);
}
