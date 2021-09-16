// shanya.c
// by dicky

#include <ansi.h>
inherit ROOM;
#include <room.h>

void create ()
{
  set ("short", "ɽ����");
  set ("long", @LONG
ǰ����һ���߷壬��ɽ�������������ƣ����к�⡣����ɽ��Ƚ�
���ͣ��������￴������һ���ͱڣ��ͱ��϶�����̦��𣬿���ȥ�쳣
�Ļ��֡�ɽ�����к������󣬿�ɽ��������������˵�������õ�ʱ��
��������ɽ�����˵�Х�����˶���Ϊ�����������档������������ʿ˵
��˵�е�̤ѩɽׯ�������⸽����
LONG);

	set("outdoors", "houjizhen");

	set("exits", ([ /* sizeof() == 3 */
		"eastdown" :  __DIR__"qiaobi",
	]));

	setup();
}


void init()
{
	add_action("do_climb", "climb");
}

int do_climb(string arg)
{
	object me=this_player();
	
	if( !arg || (arg!="shanya" && arg!="shan") )
		return notify_fail("��Ҫ��ʲô��\n");
	if(me->is_busy())
		return notify_fail("���æ����ʲôѽ��\n");

	message_vision(HIB"$N���˴��֣�����ʯͷ�ķ�϶��ɽ������ȥ������\n"NOR, me);
	me->start_busy(3);

	if(me->query("class")=="taxue")	
	{
	call_out("success", 0, me);
	return 1;
	}

	if(me->query("combat_exp") > 2000000)	
	{
	call_out("success", 0, me);
	return 1;
	}

	if( (int)me->query("kee") < 50 || (int)me->query("sen") < 50) {
		call_out("faila", 3, me);
		return 1;
	}

	if( (int)me->query_skill("dodge",1)+(int)me->query_skill("unarmed",1) >=10 ){
		call_out("faila", 3, me);
		return 1;
	}

	call_out("success", 3, me);
	return 1;
}
int success(object me)
{
	message_vision(HIB"$NԽ��Խ�ߣ��������������С�����\n"NOR, me);
	me->move("/d/taxue/yazhong");
	me->receive_damage("kee", 40);
	me->receive_damage("sen", 40);
	message_vision(HIY"$N����������������\n"NOR, me);
	return 1;
}
int faila(object me)
{

        tell_object(me, "������һ�����ȣ���ɽ���ϵ�������������\n");
        tell_room(environment(me), me->name()+"�����ƵĴ�ɽ���ϵ���������\n", ({me, me}));
	me->unconcious();
	return 1;
}

#include "heiyijob.h";