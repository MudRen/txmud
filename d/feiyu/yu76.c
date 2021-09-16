// yu76.c

#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", "听雨祠");
	set("long", @LONG
这里是绯雨阁的听雨祠，据说在这里可以听到大海的哭
声，十分诡异，关于这个地方绯雨阁里有各种各样的传说。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"yu75",
]));

	setup();
}

void init()
{
        add_action("do_ting",({ "listen","ting" }));
}

int do_ting(string arg)
{
        object me = this_player();

	if (arg != "大海的哭声")
		return notify_fail("你要听什么？\n");

	message_vision(HIM"$N静静的聆听大海的哭声．．．．\n\n\n"NOR,me);
	call_out("greeting",10,me);
	return 1;
}

void greeting(object me)
{
	if(!objectp(me) || (environment(me) != this_object()))
		return;

	message_vision (HIB"忽然，一股旋风把$N卷走了．．．\n\n\n"NOR,me);
	tell_room(__DIR__"rou1",sprintf("%s走了过来。\n",me->name()));
        me->move(__DIR__"rou1");
}
