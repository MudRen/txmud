// jiulou  长安谪仙楼

inherit ROOM;
inherit SHOW_MSG;

void create()
{
        set("short", "谪仙楼");
        set("long", @LONG
这里是长安谪仙楼，坐落于长安城西北繁华的的永泰路边，
是长安最有名的一家大酒楼，据说这家酒楼有上百家的历史，这
里的厨师都是各地的名厨，几乎什么特色菜都会烧，不时长安城
的居民喜欢来这里大饱口福，一些外地商人，举子，观光客也都
来这里点自己家乡的菜肴。跑堂的小二进进出出端酒送菜，招呼
客人，楼上是雅座。
LONG
        );

        set("night_long", @LONG
这里是长安谪仙楼，是长安最有名的一家大酒楼，这里做的
菜远近闻名，据说这家酒楼有上百家的历史。现在已经打烊了，
跑堂的没精打采的趴在柜台上。
LONG
        );

	set("exits", ([
		"west" : __DIR__"wroad1",
		"up" : __DIR__"jiulou2",
		"east" : __DIR__"chufang",
]));

	set_master("pao tang");

	set(SAFE_ENV, 1);
	set("valid_startroom", 1);
	set("no_sleep_room",1);

	set("objects",([
	__DIR__"npc/paotang" : 1,
]));

        setup();
        load_board("board_changan");
}
/*
void init()
{
	add_action("do_help","help");
}

int do_help(string arg)
{
	if( (arg == "new") && this_player() )
		this_player()->delete_temp("I_AM_NEWBIE");
	return 0;
}

int valid_leave(object me,string dir)
{
	if(me->query_temp("I_AM_NEWBIE"))
		return notify_fail("小跑堂朝你笑着说道：请您先看看 help new，那可都是生活必需品！\n");

	return ::valid_leave(me,dir);
}
*/

