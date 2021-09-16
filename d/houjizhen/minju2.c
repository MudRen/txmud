// minju1.c
// by dicky

inherit ROOM;

void create()
{
        set("short", "民居");
        set("long", @LONG
这是一家用茅草搭的房屋，里面简单的摆放着几张旧桌椅，房屋被
打扫得一尘不染，一名女子正坐在右边靠墙的矮椅上缝补着衣服，她不
时的停下手中的活来，探头朝门外望去，好象是在等着什么人。
LONG
        );

        set("exits", ([
                "east" : __DIR__"xiaoxiang",
        ]));

	set("no_sleep_room", 1);
        set(SAFE_ENV,1);

        set("objects",([
		__DIR__"npc/chunhua" : 1,
	]));

        setup();
        replace_program(ROOM);
}
