#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
��ͺͺ�������ϣ�ֻ�м�����ʵ�����١�
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
        message_vision("$N�۵�Ҫ�����������������¶�.\n",me);
}

