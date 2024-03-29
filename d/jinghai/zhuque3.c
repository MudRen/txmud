// Room: /d/jinghai/zhuque3.c

#include <cross_river.h>

inherit CROSS_RIVER_BANK;

void create()
{
	set("short", "码头");
	set("long", @LONG
这里是一个用岩石堆砌成的小码头，码头边挤满了要到靖海
岛的人群，但只有几艘小帆船停泊在岸边，人们一窝蜂地往船上
涌去，船夫们一边大声喝斥一边拼命地维持着秩序，一条大汉站
在岸边像赶鸭子般把人群驱驱散，看来这人是个管事的，要上船
得靠他了。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "northwest" : __DIR__"zhuque2",
  "west" : __DIR__"zhuque12",
]));
        set("objects",([
        __DIR__"npc/wei" : 1,
]));

	set_boat_file(__DIR__"duchuan");
	set_max_passenger(10);
	set_yell_msg("$N扯着嗓子喊道：“船家！！我要去明月岛！！”\n");

	set("outdoors","jinghai");
	setup();
}

// 重载这个函数使静海的人不收钱
protected int valid_passenger(object who)
{
	if(who->query("class") == "jinghai")
	{
		who->set_temp("payed_duchuan", 1);
		return 1;
	}

	else return ::valid_passenger(who);
}
