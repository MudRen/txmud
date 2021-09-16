#include <ansi.h>
#include <room.h>

inherit ROOM;

void create()
{
	set("short", "密室");
	set("long", @LONG
这是个阴暗的密室，墙上的油灯发出昏暗的黄光。密室
的正中放着一套石制的桌椅，石椅上坐着一妙龄少女，面露
忧郁之色。东面有一扇小门(door)，关得严严实实。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"yu102",
]));
        set("item_desc",([
        "door" : "一扇关的严严实实的小门，你可以试着去敲(knock)一下。\n",
        "小门" : "一扇关的严严实实的小门，你可以试着去敲(knock)一下。\n",
]));
        set("objects", ([
        __DIR__"npc/master" : 1,
        __DIR__"npc/shibi2" : 1,
        __DIR__"npc/shibi1" : 1,
]) );


	setup();
	create_door("south", "木门", "north", DOOR_CLOSED);
}

void init()
{
        add_action("do_knock","knock");
}

int do_knock(string arg)
{
	object me = this_player();

	if(arg != "小门" && arg != "door")
		return notify_fail("你要敲什么？\n");

	if(!me->query_temp("louth_qupai"))
		return notify_fail("没有经过张雨懿的允许，你不能来打扰人家。\n");

	if((int)me->query_temp("louth_buxing") >= 1)
		return notify_fail("今天那个人已经不想见你了，你还是走吧。\n");

	message_vision(HIM"$N轻轻的敲了几下木门。。。\n\n"NOR,me);
	call_out("greeting",8,me);
	return 1;
}

void greeting(object me)
{
	if(!objectp(me) || (environment(me) != this_object()))
		return;

	if(random(25) < me->query("kar"))
	{
		tell_object(me,"这时木门开了，你很幸运的可以去拿绯雨令了。\n");
		set("exits/east",__DIR__"zhangroom");
	}
	else
		tell_object(me,"这时屋子里有个人道：你走吧，今天我有些不舒服。\n");
		me->set_temp("louth_buxing",1);
}
