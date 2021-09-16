// yazhong.c
// by dicky

#include <ansi.h>
inherit ROOM;
#include <room.h>
string look_shi();

void create ()
{
  set ("short", "��ɽ��");
  set ("long",@LONG
ɽ������Ұ��������Χ��ɫ�������������ɽ�岻֪���ж�ߣ���
�����в������ߣ������������ƣ�Ҳ��֪�ж���ˡ�ǰ���п���ʯ(shi)��
����д��һЩ�֣����������û����������飬��û��Ƿ��ء�
LONG);

	set("outdoors", "taxue");

	set("exits", ([ /* sizeof() == 3 */
	"down": "/d/houjizhen/shanya",
	]));

	set("item_desc", ([
		"shi" :  (: look_shi :),
	]));

	setup();
}

void init()
{
	add_action("do_climb", "climb");
}

string look_shi()
{
	return
	HIY"\n"
	"   ������������������������������   \n"
	"   ������                  ������   \n"
	"   ������     ̤ѩʥ��     ������   \n"
	"   ������     ��ȥ�޻�     ������   \n"
	"   ������                  ������   \n"
        "   ������������������������������   \n"NOR;
}

int do_climb(string arg)
{
	object me=this_player();
	
	if( !arg || (arg!="shanya" && arg!="shan") )
		return notify_fail("��Ҫ��ʲô��\n");
	if( me->is_busy())
		return notify_fail("�����ں�æ����ʲôѽ��\n");
	
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

	if( random((int)me->query_kar()) <= 5){
		call_out("faila", 3, me);
		return 1;
	}

	call_out("success", 3, me);
	return 1;
}
int success(object me)
{
	message_vision(HIB"$NԽ��Խ�ߣ��������������С�����\n"NOR, me);
	me->move(__DIR__"yashang");
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
