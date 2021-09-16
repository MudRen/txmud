// Room: /d/huashan/sl_dong.c

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "瀑布");
	set("long", @LONG
你站在山崖上，只见对面一道天然的瀑布从天而降，一条条
白练坠入深渊发出巨大的声响，不时有飞溅的水珠散落在你的身
上，你不禁感到一阵凉意。
LONG
);

	set("exits", ([ /* sizeof() == 2 */
  "eastdown" : __DIR__"huapo",
]));

	set("outdoors", "huashan");
	setup();
}

void init()
{
	int n = query_time();
	object me = this_player();

	if( me
	&& ((n >= 660) || (n <= 900))
	&& (weather_now() == "clear")
	&& (random(50 - me->query("kar")) < 8) )
		call_out("very_lucky",2,me);

	add_action("do_enter", ({"zuan"}));
}

int do_enter(string arg)
{
	int n = query_time();
	object me = this_player();

	if( arg != "瀑布" )
		return 0;

	if( (n < 660) || (n > 900) || (me->query_skill("dodge",1) < 160) )
		return notify_fail("巨大的水流把你冲了回来。\n");

        message_vision(HIY" $N跑了几步，一提气向着瀑布跃了过去。\n"NOR, me);
        if( me->move(__DIR__"dongkou") )
		tell_room(environment(me), me->name() + "从外面跳了进来。浑身上下湿得像个落汤鸡。\n",({me}));
        return 1;
}

private void very_lucky(object who)
{
	if( !who || !living(who) || (environment(who) != this_object()) )
		return;

	tell_object(who,WHT"\n在午间强烈的阳光的映照下，你惊奇的发现瀑布后面好像有一个山洞。
不知道是不是应该钻进瀑布看看。\n\n"NOR);
}
