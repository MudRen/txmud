// ehroad1  东环路

inherit ROOM;

void create()
{
        set("short", "东环路");
        set("long", @LONG
这里是长安城的东环路，是长安四条主街道之一，由于是紧
邻皇城的内环路，所以戒备森严，巡捕、御林军来往不断，一般
老百姓都不来这里，所以显得非常清净。西面高大的宫墙显示出
无比的华丽和又是千百年来权贵的象征。东面是凌烟阁。
LONG
        );

	set("exits", ([
		"east"		   : __DIR__"ly-ge",
                "south"            : __DIR__"shroad4",
                "north"            : __DIR__"ehroad2",
]) );
	set("outdoors","changan");
        setup();
	replace_program(ROOM);
}
