// yu76.c

#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
���������������������˵��������������󺣵Ŀ�
����ʮ�ֹ��죬��������ط��������и��ָ����Ĵ�˵��
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

	if (arg != "�󺣵Ŀ���")
		return notify_fail("��Ҫ��ʲô��\n");

	message_vision(HIM"$N�����������󺣵Ŀ�����������\n\n\n"NOR,me);
	call_out("greeting",10,me);
	return 1;
}

void greeting(object me)
{
	if(!objectp(me) || (environment(me) != this_object()))
		return;

	message_vision (HIB"��Ȼ��һ�������$N�����ˣ�����\n\n\n"NOR,me);
	tell_room(__DIR__"rou1",sprintf("%s���˹�����\n",me->name()));
        me->move(__DIR__"rou1");
}
