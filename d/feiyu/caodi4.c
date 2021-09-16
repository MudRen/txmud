// caodi4.c

#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", "院门口");
	set("long", @LONG
眼前是一片僻静的小院，四周静悄悄的没有一点动静，院子
的围墙并不高，院门关得严严实实的，门上有一个敲门用的铜环。
门边有一块木牌(pai)格外醒目。里面没有一丝生息。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"caodi3",
]));

        set("item_desc", ([ 
                "木牌" : HIR"
                        擅
                        闯
                        绯
                        雨
                        听
                        竹
                        轩
                        者
                      『死』\n"NOR,
                "pai" : HIR"
                        擅
                        闯
                        绯
                        雨
                        听
                        竹
                        轩
                        者
                      『死』\n"NOR,
        "door" : "一扇紧紧的关着的小木门，你可以试着去敲(knock)一下。\n",
        "木门" : "一扇紧紧的关着的小木门，你可以试着去敲(knock)一下。\n",
]));
        set("outdoors","feiyu");
	setup();
}
void init()
{
        add_action("do_knock","knock");
        add_action("do_push","push");
        add_action("do_break","break");
}

int do_knock(string arg)
{
        object me = this_player();

	if(arg != "door" && arg != "木门")
		return notify_fail("你要敲什么？\n");

	message_vision("$N在小木门上轻轻的敲了几下。。。\n\n",me);
        me->set_temp("mark/louth_knock",1);
        call_out("greeting",8,me);
        return 1;
}

int do_push(string arg)
{
        object me = this_player();

	if(arg != "door" && arg != "木门")
		return notify_fail("你要推什么？\n");

	if(!me->query_temp("mark/louth_knock"))
		return notify_fail("你使劲推了推小木门，但是没有推动。\n");

	message_vision("$N轻轻推开了小木门。\n",me);
	set("exits/enter",__DIR__"caodi5");
	me->delete_temp("mark/louth_knock");
	return 1;
}

int do_break(string arg)
{
	object me = this_player();

	if(arg != "door" && arg != "木门")
		return notify_fail("你想干什么？\n");

	message_vision(HIB"$N大喝一声，伸出双掌向小木门拍去。\n"NOR,me);
	message_vision("院子里忽然闪出一条倩影，对着$N冷笑几声。\n",me);
	write("她娇喝一声：禁止擅闯绯雨听竹轩！\n");
	write(HIR"忽然，她一剑向你刺来。\n"NOR);
	me-> unconcious();
        return 1;
}

void greeting(object me)
{
	if(!objectp(me) || (environment(me) != this_object()))
		return;

	tell_object(me,"院子里有个声音说道：进来吧。\n");
}
