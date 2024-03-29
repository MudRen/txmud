// Room: /d/huashan/maonv2.c

#include <ansi.h>

inherit ROOM;

private int left,l,right,r;

void create()
{
	set("short", "毛女洞");
	set("long", @LONG
又向下走了一层，空气已经不是暖和而已，你感觉简直是进
了蒸笼。地上有涔涔的水流。向南的方向还有一个巨石（stone）
好像压着什么，石头下面灼热的白气呼呼涌出。石头潮渌渌的。
你心里突然有一种不祥的预感涌了上来。
LONG
);
	
	set("exits", ([ /* sizeof() == 1 */
	"northup" : __DIR__"maonv1",
]));

	set("item_desc", ([
		"stone": HIR"黑色的大石头，上面湿渌渌的，灼热的水气从四周涌出来。\n"NOR
]) );

	set("objects", ([
		__DIR__"npc/wolf2":1,
]));
	setup();
}

void init()
{
	add_action("do_push", "push");
}

private void check_trigger(object who)
{
        object room,wl;

	if(!who || !userp(who) || (environment(who) != this_object()))
		return;

        if( (left == l)
	&& (right == r)
	&& !query("exits/down") )
	{
		if( !room = find_object(__DIR__"maonv3") )
			room = load_object(__DIR__"maonv3");
		if(!room)
			return;

		tell_room(__FILE__, HIR"石头忽然发出轰隆的一声，向后倒了下去，露出一个向下的洞口。\n"NOR);
		set("exits/down", __DIR__"maonv3");
		room->set("exits/up", __FILE__);
                        tell_room(room,HIR"压住洞口的石头忽然发出轰隆的一声，露出一个向上的洞口。\n"NOR);

		left = 0;
		right = 0;

		if(wl = present("white wolf",this_object()))
		{
			message_vision(HIR"$N猛的向你扑了过来。\n"NOR, wl);
			wl->kill_ob(who);
			wl->check_env(who);
		}

		call_out("close_passage", 15);
	}
}

private void close_passage()
{
        object room;

	if( room = find_object(__DIR__"maonv3") )
	{
		room->delete("exits/up");
		tell_room(room,"头顶忽然发出轧轧的声音，向上的洞口又被石头压住了。\n");
	}

	if( query("exits/down") )
	{
		delete("exits/down");
		tell_room(__FILE__,"石头忽然发轰隆的一声，向前倒了下来，将向下的洞口盖住了。\n"NOR);
	}
}

int do_push(string arg)
{
	if( !arg || arg=="" )
		return 0;

	switch (arg)
	{
		case "stone":
			write(HIY"你试著推动这块石头，似乎可以左右滑动。\n"NOR);
			break;

		case "stone right":
			message_vision("$N将石头往右推。。。，「喀啦」石头一晃又移回原位。\n",this_player());
			right++;
			check_trigger(this_player());
			break;

		case "stone left":
			message_vision("$N将石头往左推。。。，「喀啦」石头一晃又移回原位。\n",this_player());
			left++;
			check_trigger(this_player());
			break;

		default:
			if(sscanf(arg,"stone %*s"))
                        	message_vision("$N胡乱推了一下石头，但没有任何反应。\n"NOR,this_player());
			else
				return 0;
	}
	return 1;
}

int valid_leave(object who,string dir)
{
	object wl;

	if(dir == "down")
	{
		if(wl = present("white wolf",this_object()))
			return notify_fail(sprintf("%s拦住了你的去路。\n",wl->name()));
	}

	return ::valid_leave(who,dir);
}

void reset()
{
        ::reset();
	left = 0; right = 0;
	l = 5+random(5),r = 3+random(3);
}
