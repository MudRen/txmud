// ziqi.c
// ��������,����ϼ�񹦡����ع�

#include <ansi.h>

int exert(object me, object target)
{
	int s = me->query_skill("zixia-force",1), effect, last;

	if(!me->query("family/master_yue_teach"))
		return 0;

	if(me->query_temp("apply/huashan-sword"))
		return notify_fail("������ʩչ���������������������й��ˡ�\n");

	if(me->query("force") < 150)
		return notify_fail("��������������޷�ʩչ��������������\n");

	if(s < 100)
		return notify_fail("��ġ���ϼ�񹦡��ȼ��������޷�ʩչ������������\n");

	effect = 8 + 100/15;

	last = 120 + effect*5;

	message_vision(HIY"\n$N�����������ᵤ����ֱ��ʮ����¥��������������һ�֣��漴��ʧ...\n\n"NOR,me);
	me->set_temp("apply/huashan-sword",effect);
	me->add("force",-150);
	me->start_perform_busy(8);
	call_out("stop_up",last,me);
	return 1;
}

protected void stop_up(object who)
{
	if(!who)
		return;

	if(who->query_temp("apply/huashan-sword"))
	{
		who->delete_temp("apply/huashan-sword");
		tell_object(who,"\n������ڹ�һй��������������Ч����ʧ�ˡ�\n\n");
	}
}
