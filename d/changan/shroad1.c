// shroad1  南环路

inherit ROOM;

void create()
{
        set("short", "南环路");
        set("long", @LONG
这里是长安城的南环路，是长安四条主街道之一，由于是紧
邻皇城的内环路，所以戒备森严，巡捕、御林军来往不断，一般
老百姓都不来这里，所以显得非常清净。北面高大的宫墙显示出
无比的华丽和又是千百年来权贵的象征。南面是由得道高僧法空
长老住持的皇家寺院宝象寺。
LONG
        );

	set("exits", ([
		"south"		   : __DIR__"baoxiang",
                "west"             : __DIR__"whroad4",
                "east"             : __DIR__"shroad2",
 ]) );

	set("outdoors","changan");
        setup();
	replace_program(ROOM);
}
