// shroad3  南环路

inherit ROOM;

void create()
{
        set("short", "南环路");
        set("long", @LONG
这里是长安城的南环路，是长安四条主街道之一，由于是紧
邻皇城的内环路，所以戒备森严，巡捕、御林军来往不断，北面
高大的宫墙显示出无比的华丽和又是千百年来权贵的象征。南面
是皇宫近卫军驻扎的禁卫营，门口是两排雄赳赳的禁军把守。
LONG
        );

	set("exits", ([
                "west"             : __DIR__"shroad2",
                "east"             : __DIR__"shroad4",
                "south"            : __DIR__"jinwei",
 ]) );

	set("outdoors","changan");
        setup();
	replace_program(ROOM);
}
