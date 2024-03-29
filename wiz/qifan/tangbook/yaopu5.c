//yaotian1
#include <ansi.h>
inherit ROOM;

int do_zhao(string arg);

// Room: /d/tangmen/yaopu1.c

inherit ROOM;

void create()
{
        set("short", "药圃");
        set("long", @LONG
这里是一处很大的药苗圃，遍地开着各色怪异的小花，空气
里弥漫着香臭混杂的怪味道。
LONG
        );
        set("exits", ([
  "north" : __DIR__"yaopu1",
  "west" : __DIR__"yaopu4",
  "south" : __DIR__"yaopu9",
  "east" : __DIR__"yaopu6",
]));

        set("outdoors", "tangmen");
        set("yao", 5);

        setup();
        replace_program(ROOM);
}

void init()
{
	add_action("do_zhao","zhao");
}

int do_zhao(string arg)
{
        object me;
        int jingli_cost;

        me = this_player();
        jingli_cost = (-1) * (5 + random(15));

        if ( !arg || ( arg != "yao" ) )
                return notify_fail("你想干什么？\n");

        if ( me->query_temp("find") )
                return notify_fail("你已经找到了一株草药，可以交差了！\n");

	if ( me->query("jingli") <= ( - jingli_cost ) )
		return notify_fail("你太疲劳了，没有精力再找药了。\n");

	if ( (int)query("yao") >= 1 )
        {
		message_vision(YEL"$N蹲下身来，小心翼翼的在花圃中寻找着药草。\n"NOR, me);
		if ( random(1 + me->query("kar") - 10 ) >= 3 )
		{
			message_vision(HIG"$N不断的拨动着花圃中的草药，终于找到了一株。\n$N将这株药草小心的收在怀中。\n"NOR, me);
			new(__DIR__"obj/caoyao")->move(me);
			me->set_temp("find",1);
		}

	        me->add("jingli", jingli_cost);
		add("yao",-1);
        }
	else
                return notify_fail("这里都已经被翻遍了，没有什么可找的了。\n");

        return 1;
}