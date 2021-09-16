// Room: /d/huashan/sl_dong.c

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "�ٲ�");
	set("long", @LONG
��վ��ɽ���ϣ�ֻ������һ����Ȼ���ٲ����������һ����
����׹����Ԩ�����޴�����죬��ʱ�зɽ���ˮ��ɢ���������
�ϣ��㲻���е�һ�����⡣
LONG
);

	set("exits", ([ /* sizeof() == 2 */
  "eastdown" : __DIR__"huapo",
]));

	set("outdoors", "huashan");
	setup();
}

void init()
{
	int n = query_time();
	object me = this_player();

	if( me
	&& ((n >= 660) || (n <= 900))
	&& (weather_now() == "clear")
	&& (random(50 - me->query("kar")) < 8) )
		call_out("very_lucky",2,me);

	add_action("do_enter", ({"zuan"}));
}

int do_enter(string arg)
{
	int n = query_time();
	object me = this_player();

	if( arg != "�ٲ�" )
		return 0;

	if( (n < 660) || (n > 900) || (me->query_skill("dodge",1) < 160) )
		return notify_fail("�޴��ˮ��������˻�����\n");

        message_vision(HIY" $N���˼�����һ���������ٲ�Ծ�˹�ȥ��\n"NOR, me);
        if( me->move(__DIR__"dongkou") )
		tell_room(environment(me), me->name() + "���������˽�������������ʪ�������������\n",({me}));
        return 1;
}

private void very_lucky(object who)
{
	if( !who || !living(who) || (environment(who) != this_object()) )
		return;

	tell_object(who,WHT"\n�����ǿ�ҵ������ӳ���£��㾪��ķ����ٲ����������һ��ɽ����
��֪���ǲ���Ӧ������ٲ�������\n\n"NOR);
}
