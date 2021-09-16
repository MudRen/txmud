// Room: /d/huashan/wuyunfeng.c

inherit ROOM;

void create()
{
	set("short", "擦耳崖");
	set("long", @LONG
这里就是擦耳崖。你抬头仰望，只见一道黑色的山脊，宛如
一条青龙横卧空中，那就是苍龙岭。山道就在龙脊之上，路宽不
到一米，两边悬崖壁立如峭，谷壑深不见底。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "westdown" : __DIR__"xiaolu9",
]));
        set("outdoors", "huashan");
	setup();
	replace_program(ROOM);
}
