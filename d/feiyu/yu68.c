#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
�����ڰ���У������Ǻ����ķ�����
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
		message_vision(HIW"$N�������ɰ�����������ƮƮ�������˵��ϡ�\n"NOR,me);
	}
}
