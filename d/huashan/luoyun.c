// Room: /d/huashan/zhanqiao.c

#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", "落云关");
	set("long", @LONG
这里是栈桥的尽头，是一个用木桩搭成的关隘。十几个华山
派的弟子手持长剑在守着，当中一个草棚下坐着一个老者。
LONG
);

	set("exits", ([ /* sizeof() == 2 */
 
  "west" : __DIR__"zhanqiao",
  "southdown":__DIR__"kuang",
]));

	set("outdoors", "huashan");
	setup();
}

void init()
{
	object me = this_player();

	if( me
	&& interactive( me )
	&& !wizardp(me)
	&& (me->query("class") != "huashan") )
	{
		me->move(__DIR__"zhanqiao");
		tell_object(me, HIW"“大胆狂徒，敢闯华山禁地。”对面草棚里的老者纵身而起，
  一掌拍在固定栈桥的铁链上，你的身形一晃竟被弹了回来。\n\n"NOR);
	}
}
