#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", "半空中");
	set("long", @LONG
你身在半空中，耳边是呼呼的风声。
LONG
);
	set("outdoors","feiyu");
	setup();
}

void init()
{
	if(this_player())
		call_out("greeting",3,this_player());
}

void greeting(object me)
{
	if(objectp(me) && (environment(me) == this_object()))
	{
		me->move(__DIR__"yu69");
		message_vision(HIW"$N好似神仙般从天而降，轻飘飘的落在了地上。\n"NOR,me);
	}
}
