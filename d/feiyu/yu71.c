#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", "悬崖上");
	set("long", @LONG
光秃秃的悬崖上，只有几根结实的蔓藤。
LONG
	);
       set("outdoors","feiyu");
	setup();
}

int init()
{
        object me;
        me=this_player();
        call_out("greeting",4,me);
}
void greeting(object me)
{
        me->move(__DIR__"yu63");
        message_vision("$N累的要死，终于爬上了悬崖顶.\n",me);
}

