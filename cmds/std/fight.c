// fight.c

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	object obj, old_target,ride;

	seteuid(getuid());

	if( !wizardp(me) && environment(me)->query(SAFE_ENV) )
		return notify_fail("�����ֹս����\n");

	if(!arg || !objectp(obj = present(arg, environment(me))))
		return notify_fail("���빥��˭��\n");

	if( !obj->is_character() )
		return notify_fail("�����һ�㣬�ǲ��������\n");

	if(obj->query(NO_KILL) || obj->is_master())
		return notify_fail("�Է������������ս��\n");

        if(obj->query_temp("netdead"))
                return notify_fail("��С�Ӷ�����������������˵�ɡ�\n");

	if(obj->query_temp("boss_behind"))
		return notify_fail(gender_pronoun(obj->query("gender"))+"���ϰ���"+
		gender_pronoun(obj->query("gender"))+"����أ���һ����ٺ�"+
		gender_pronoun(obj->query("gender"))+"�����ɡ�\n"); // by Find.

	if (in_edit(obj) || in_input(obj) || obj->query_temp("netdead"))
		return notify_fail ("�����ѹ����ٽ�����.\n");

	if( obj->is_fighting(me) )
		return notify_fail("���ͣ����ͣ����ͣ�\n");

	if( !living(obj) )
		return notify_fail(obj->name() + "�Ѿ��޷�ս���ˡ�\n"); 

	if(obj==me)	return notify_fail("�㲻�ܹ����Լ���\n");

	if(me->query("kee") < me->query("max_kee")/3)
		return notify_fail("������������֧�����Ǳ���ĺá�\n");

	// added by Find.
	if( ride = obj->query_temp("have_been_rided"))
	{
		if(ride == me)
			return notify_fail(sprintf("��������%s������ô����ѽ��\n",obj->name()));
		else
		return notify_fail(sprintf("%sŤ��Ť���ӣ���ͷת���������ĵط���\n",obj->name()));
	}
	// end.

	if( userp(obj) && (object)obj->query_temp("pending/fight")!=me )
	{
		message_vision("\n$N����$n˵����" 
			+ RANK_D->query_self(me) 
			+ me->name() + "�����"
			+ RANK_D->query_respect(obj) + "�ĸ��У�\n\n", me, obj);
		if( objectp(old_target = me->query_temp("pending/fight")) )
			tell_object(old_target, YEL + me->name() + "ȡ���˺�����Ե���ͷ��\n" NOR);
		me->set_temp("pending/fight", obj);
		tell_object(obj, YEL "�����Ը��ͶԷ����б��ԣ�����Ҳ��" + me->name() + "("+(string)me->query("id")+")"+ "��һ�� fight ָ�\n" NOR);
		write(YEL "���ڶԷ�������ҿ��Ƶ���������ȶԷ�ͬ����ܽ��б��ԡ�\n" NOR);
		return 1;
	}

	if( obj->query("can_speak") )
	{
		message_vision("\n$N����$n˵����" 
			+ RANK_D->query_self(me) 
			+ me->name() + "�����"
			+ RANK_D->query_respect(obj) + "�ĸ��У�\n\n", me, obj);

		notify_fail("������" + obj->name() + "��������������\n");
		if( !userp(obj) && !obj->accept_fight(me) ) return 0;

		me->fight_ob(obj);
		obj->fight_ob(me);
	}

	else
	{
		message_vision("\n$N���һ������ʼ��$n����������\n\n", me, obj);
		me->fight_ob(obj);
		obj->kill_ob(me);
	}

	if(objectp(ride) && !userp(ride))
	{			
		message_vision("$N��$n�󺰣����Ҵ�����������⣬�������������\n",ride,me);
		ride->kill_ob(me);
		me->fight(ride);
	}

	return 1;
}
int help(object me)
{
  write(@HELP
ָ���ʽ : fight <����>
 
���ָ��������һ������ֽ̡������ǡ��д����ա���������ʽ��ս��������
�㵽Ϊֹ�����ֻ����������������������ˣ����ǲ��������е�  NPC ��ϲ��
��ܣ���������״����ı���Ҫ��ᱻ�ܾ���
 
�������ָ��: kill

PS. ����Է���Ը����������ս������Ȼ���������� kill ָ�ʼս������
    �� fight �� kill �������뿴 'help combat'.
HELP
    );
    return 1;
}
