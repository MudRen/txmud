// Room: /d/shaolin/qsl_room.c

inherit ROOM;

void create()
{
	set("short", "灌木丛");
	set("long", @LONG
这里是一片浓密的小灌木丛，东北方向远远望去是一处宏大
的寺庙。一阵山风吹来四周沙沙做响，给人一种阴森恐怖的感觉。
LONG
	);

	setup();
	replace_program(ROOM);
}
