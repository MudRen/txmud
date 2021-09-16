// Room: /d/huashan/maonv2.c

#include <ansi.h>

inherit ROOM;

private int left,l,right,r;

void create()
{
	set("short", "ëŮ��");
	set("long", @LONG
����������һ�㣬�����Ѿ�����ů�Ͷ��ѣ���о���ֱ�ǽ�
���������������乵�ˮ�������ϵķ�����һ����ʯ��stone��
����ѹ��ʲô��ʯͷ�������ȵİ�������ӿ����ʯͷ�����˵ġ�
������ͻȻ��һ�ֲ����Ԥ��ӿ��������
LONG
);
	
	set("exits", ([ /* sizeof() == 1 */
	"northup" : __DIR__"maonv1",
]));

	set("item_desc", ([
		"stone": HIR"��ɫ�Ĵ�ʯͷ������ʪ���˵ģ����ȵ�ˮ��������ӿ������\n"NOR
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

		tell_room(__FILE__, HIR"ʯͷ��Ȼ������¡��һ�����������ȥ��¶��һ�����µĶ��ڡ�\n"NOR);
		set("exits/down", __DIR__"maonv3");
		room->set("exits/up", __FILE__);
                        tell_room(room,HIR"ѹס���ڵ�ʯͷ��Ȼ������¡��һ����¶��һ�����ϵĶ��ڡ�\n"NOR);

		left = 0;
		right = 0;

		if(wl = present("white wolf",this_object()))
		{
			message_vision(HIR"$N�͵��������˹�����\n"NOR, wl);
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
		tell_room(room,"ͷ����Ȼ�������������������ϵĶ����ֱ�ʯͷѹס�ˡ�\n");
	}

	if( query("exits/down") )
	{
		delete("exits/down");
		tell_room(__FILE__,"ʯͷ��Ȼ����¡��һ������ǰ���������������µĶ��ڸ�ס�ˡ�\n"NOR);
	}
}

int do_push(string arg)
{
	if( !arg || arg=="" )
		return 0;

	switch (arg)
	{
		case "stone":
			write(HIY"�������ƶ����ʯͷ���ƺ��������һ�����\n"NOR);
			break;

		case "stone right":
			message_vision("$N��ʯͷ�����ơ���������������ʯͷһ�����ƻ�ԭλ��\n",this_player());
			right++;
			check_trigger(this_player());
			break;

		case "stone left":
			message_vision("$N��ʯͷ�����ơ���������������ʯͷһ�����ƻ�ԭλ��\n",this_player());
			left++;
			check_trigger(this_player());
			break;

		default:
			if(sscanf(arg,"stone %*s"))
                        	message_vision("$N��������һ��ʯͷ����û���κη�Ӧ��\n"NOR,this_player());
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
			return notify_fail(sprintf("%s��ס�����ȥ·��\n",wl->name()));
	}

	return ::valid_leave(who,dir);
}

void reset()
{
        ::reset();
	left = 0; right = 0;
	l = 5+random(5),r = 3+random(3);
}
