// Room: /d/shaolin/sleeproom.c

inherit ROOM;

void create()
{
	set("short", "休息室");
	set("long", @LONG
这里是少林寺的休息室，墙上挂着一个很大的牌子“静”，
一字排开的大通铺，整洁的被褥。从窗外你可以看到寺外的一些
景致，闻到香炉里飘来的淡淡香气，你不禁有些困了。
LONG
	);
	set(SAFE_ENV,1);
        set("sleep_room", 1);

	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"e_court",
]));

	setup();
	replace_program(ROOM);
}
