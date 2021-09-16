// yu53.c

#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", "梅花园");
	set("long", @LONG
这里种满了梅树，花色深浅一如桃花，蒂垂丝作海棠状，
香气宜人。边上有一扇小门不知通向哪里，北边一条梅林小
路通向一座华丽的阁楼。
LONG
);

	set("exits", ([ /* sizeof() == 3 */
	"south" : __DIR__"yu52",
	"northeast" : __DIR__"yu54",
]));

	set("item_desc",([
	"door" : "一扇小小的木门，你不试着敲(knock)一下，看看主人是否给你开启？\n",
	"小门" : "一扇小小的木门，你不试着敲(knock)一下，看看主人是否给你开启？。\n",
]));

	set("objects", ([ /* sizeof() == 4 */
	__DIR__"npc/hufa4" : 1,
]));

	set("outdoors","feiyu");
	setup();
}

void init()
{
        add_action("do_knock","knock");
}

int do_knock(string arg)
{
	object me = this_player();

	if(arg != "door" && arg != "门" && arg != "小门")
		return notify_fail("你要敲什么？\n");

	if(query("exits/enter"))
		return notify_fail("门已经是开着的了。\n");

	if(me->query_temp("mark/huaner_knock"))
		return notify_fail("你已经敲过了，想把门敲烂呀？\n");

	message_vision("$N在门上轻轻的敲了几下。。。\n",this_player());
	me->set_temp("mark/huaner_knock",1);
	call_out("knock",5,me);
	return 1;
}

void knock(object me)
{
	if(!objectp(me) || (environment(me) != this_object()))
		return;

	tell_object(me,"\n屋子里传来一阵脚步声。。。\n");
	call_out("opendoor",2,me);
}

void opendoor(object me)
{
	if(!objectp(me) || (environment(me) != this_object()))
		return;

	tell_object(me,"\n环儿从里边把门打开了。\n");
	set("exits/enter", __DIR__"fyyg");
	call_out("close_door",6,me);
}

void close_door(object me)
{
	if(query("exits/enter"))
	{
		tell_room(__FILE__,"小门关上了。\n");
		delete("exits/enter");
	}

	if(objectp(me))
		me->delete_temp("mark/huaner_knock");
}

int valid_leave(object me, string dir)
{
	object ob;

	if( dir =="northeast"
	&& (me->query("combat_exp") < 600000)
	&& !me->query_temp("mark/louth_meilinge")
	&& !wizardp(me) )
        {
		if(objectp(ob = present("zhang fubing", this_object())) && living(ob))
			return notify_fail("张绋冰道：没有经过大总管的允许，谁也不能进入梅林阁！\n");
	}
	return ::valid_leave(me, dir);
}
