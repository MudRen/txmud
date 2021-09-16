// heal.c
// by dicky

#include <ansi.h>

#define SKILL_FORCE	"taxue-force"

int exert(object me, object target)
{
	int eff,max,busy;

	if( me->is_fighting() )
		return notify_fail("ս�����޷��й����ˣ�\n");

	if(me->query("max_force") < 120)
		return notify_fail("����ڹ���Ϊ�������޷��й����ˡ�\n");

	if( me->query("force") < 100 )
		return notify_fail("��������������޷��й����ˡ�\n");

	if( (eff=me->query("eff_kee")) < (max=me->query("max_kee")) / 3 )
		return notify_fail("���Ѿ����˹��أ����������й�ֻ��������Σ�գ�\n");

	if((target==me?eff:target->query("eff_kee")) >= (target==me?max:target->query("max_kee")))
		return notify_fail(sprintf("%sĿǰ��û�����ˡ�\n",target==me?"��":target->name()));

	if( (target != me) && (environment(me) != environment(target)))
		return notify_fail("��Ҫ���˵Ķ��������\n");

	if(target==me)
		message_vision(HIW"$N��ϥ������������ԣ�ȫ�������������죬ͷ��������һ˿������\n"NOR,me);
	else
		message_vision(HIG"$N��ϥ������˫�ֵ�ס$n�ĺ��ģ�ȫ�������������죬ͷ��������һ˿������\n"NOR,
			me,target);

	me->add("force",-100);
	call_out("finish_healing",(busy = 5+random(5)),me,target);
	me->start_busy(busy);
	return 1;
}

void finish_healing(object me,object target)
{
	int now,eff,max,add,can;

	if(!me)
		return;

	if(!target || (environment(target) != environment(me)))
	{
		write("�����˵Ķ����Ѿ��뿪�����\n");
		return;
	}

	can = 15+me->query_skill(SKILL_FORCE,1)/6;
	now = target->query("kee");
	eff = target->query("eff_kee");
	max = target->query("max_kee");

	add = max-eff<can?max-eff:can;
	target->add("eff_kee",add);
	add = (now+add/2)>max?max-now:add/2;
	target->add("kee",add);
	tell_object(target,HIG"��ֻ����һ˿����֮������������һ�ܣ����ϵ���ʹ�ö��ˡ�\n"NOR);
	message_vision(HIW"$N�й�Բ����վ��������\n"NOR,me);
	me->stop_busy();
}