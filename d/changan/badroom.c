// Room: /d/changan/badroom.c

inherit ROOM;

void create()
{
	set("short", "土地庙");
	set("long", @LONG
这是一间破旧的的城隍庙，在你面前的神桌上供奉著一尊土
地，庙虽老旧，但是神案四周已被香火薰成乌黑的颜色，显示这
里香火还算旺盛。
LONG
);
	set(SAFE_ENV, 1);

	set("exits", ([ /* sizeof() == 3 */
  "east" : __DIR__"eroad1",
  "north" : __DIR__"backyard",
]));

	set("objects",([
	__DIR__"npc/keeper" : 1,
	]));

	setup();
	replace_program(ROOM);
}
