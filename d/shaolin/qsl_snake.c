// Room: /d/shaolin/qsl_snake.c

inherit ROOM;

void create()
{
	set("short", "灌木丛");
	set("long", @LONG
这里是一片浓密的小灌木丛，东北方向远远望去是一处宏大
的寺庙。一阵山风吹来四周沙沙做响，给人一种阴森恐怖的感觉。
LONG
	);

	set("objects",([
	__DIR__"npc/snake" : 1,
]));

	setup();
}

void check_set_up()
{
	if(find_call_out("reset") == -1)
		call_out("reset", 60);
}
