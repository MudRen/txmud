// Room: /d/jinghai/zhuque8.c

inherit ROOM;

void create()
{
	set("short", "东厢房");
	set("long", @LONG
这是客厅旁的厢房，屋内干净整洁，似有人经常来打扫。墙
上挂着几幅字画，一盆翠绿的吊兰从屋角承尘上挂着的花盆里直
缀到地上，看来是有些年月了，让人不禁啧啧称奇。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "northwest" : __DIR__"zhuque6",
  "west" : __DIR__"zhuque9",
]));

	setup();
	replace_program(ROOM);
}
