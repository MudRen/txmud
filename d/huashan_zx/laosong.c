// Room: laosong.c

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","��������");
	set("long",@LONG
�������������ҡҡ������ĺ���һֻ����ӡ�����ķ��
���㲻�������������������֦����ȫ��������ǲ�Ҫ����̫
���˰ɡ�
LONG
);

	set("exits", ([ /* sizeof() == 3 */
	"down":__DIR__"siguoya2.c",
]));

	set("outdoors", "huashan_zx");
	setup();
}

void init()
{
	object me = this_player();
	int n = query_time();

	if( me && ((n >= 1380) || (n <= 300)) )
	{
		if( random(100 - me->query("kar")) < 10 )
			call_out("very_lucky",2,me);
	}
	add_action("do_enter", ({"pan","climb"}));
}

int do_enter(string arg)
{
	object me = this_player();
	int n = query_time();

	if( (n > 300) && (n < 1380))
		return 0;

	if( (arg != "����֦") && (arg != "��֦") )
		return 0;

	message_vision("$N����������֦�򶴿����˹�ȥ.\n", me);

	if(me->query_skill("dodge",1) < 150)
	{
		message_vision("\n$N����һ�����ȣ����µ�ˤ����ȥ��\n\n",me);
		me->move(__DIR__"bankong");
		me->start_busy(5);
		call_out("goto_yanwang",3,me);
		return 1;
	}

	if( me->move(__DIR__"sg_dong2") )
		tell_room(environment(me), me->name() + "���������˽�����\n",({me}));
	return 1;
}

private void very_lucky(object who)
{
	if(!who || !living(who) || (environment(who) != this_object()) )
		return;

	tell_object(who,WHT"\n��������¹⣬�㷢������ľ����Ϻ�����һ������
���Ŵ�׳������֦Ҳ�����������\n\n"NOR);
}

private void goto_yanwang(object me)
{
	if(!objectp(me))
		return;

	tell_room(__FILE__,"ֻ��������������Լ����һ���ҽС�����\n");

	me->stop_busy();
	me->move(__DIR__"yadi");
	me->receive_damage("kee",200,"trip");
	me->die();
}
