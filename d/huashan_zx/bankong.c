// Room: /d/huashan_zx/bankong.c

inherit ROOM;

void create()
{
	set("short", "半空中");
	set("long", @LONG
你只觉得山风从耳边呼啸而过，身边的一切在飞快得向上移
动，悬崖底下的尖石迅速的朝你扑来。。。
LONG
	);

	setup();
	replace_program(ROOM);
}
