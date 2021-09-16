// Room: /d/tangmen/lin.c

#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", "Ũ������");
	set("long", @LONG
������һƬŨ�ܵ����֣�����Ĵ���������գ�ż���м���
����͸�������������ǿ�֦��Ҷ�����������������˲��������ա�
LONG
	);

	set("outdoors", "tangmen");
	setup();
}

void init()
{
	object me = this_player();

	if( (random(10) < 7)
	|| !userp(me)
	|| (me->query("class") == "tangmen")
	|| me->query_temp("been_recommend_to_tangmen") )
		return;

	call_out("do_ansuan", 2, me);
}

protected void do_ansuan(object me)
{
	int flag = random(10)<5?1:0, n;
	string *limbs;

	if( !me || (environment(me) != this_object()) )
		return;

	tell_object(me, sprintf(HIB"\nͻȻ��ಡ���һ�����������һֻ���ڡ�\n%s\n\n"NOR,
		flag?"��Ͻ�һ������˹�ȥ���³���һ���亹��":
		sprintf("һ�¶��������%s�ϡ�", (n=sizeof(limbs = me->query("limbs")))?
		limbs[random(n)]:"��")));

	if(!flag)
	{
		me->receive_damage("kee", 10);
		if(random(10) < 2)
			me->apply_condition("tangdu", 2);
	}
}
