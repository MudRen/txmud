// si.c �����һ�
// longjiao-blade ���ع�

#include <ansi.h>
#include <combat.h>

inherit SSERVER;

int perform(object me, object target)
{
	int skill, damage,count,temp,ap,dp;
	mapping my;
	object weapon;

	if(!me->query("family/valid_perform_si"))
		return 0;

	if(!weapon = me->query_temp("weapon"))
		return notify_fail("���޷�ʩչ�������һ\n");

	if( !target )
		target = offensive_target(me);

	if( !target
	|| !target->is_character()
	|| !me->is_fighting(target) )
                return notify_fail("�������һֻ�ܶ�ս���еĶ���ʹ�á�\n");

	if( ( skill = (int)me->query_skill("longjiao-blade",1)) < 150)
		return notify_fail("��ġ�����ն�޵������������㣬�޷�ʹ�á������һ��\n");

	if( (int)me->query("force")< 800 )
		return notify_fail("��������������޷�ʹ�á������һ��\n");

	my = me->query_entire_dbase();
	if( (my["kee"] <= my["max_kee"]/2)
	|| (my["eff_kee"] <= my["max_kee"]/2)
	|| (my["gin"] <= my["max_gin"]/2)
	|| (my["eff_gin"] <= my["max_gin"]/2)
	|| (my["sen"] <= my["max_sen"]/2)
	|| (my["eff_sen"] <= my["max_sen"]/2) )
		return notify_fail("��Ŀǰ����״�����ã����ǿ��������������������롣\n");

	damage = my["kee"];
	if(my["eff_kee"] < damage)
		damage = my["eff_kee"];
	if(my["gin"] < damage)
		damage = my["gin"];
	if(my["eff_gin"] < damage)
		damage = my["eff_gin"];
	if(my["sen"] < damage)
		damage = my["sen"];
	if(my["eff_sen"] < damage)
		damage = my["eff_sen"];

	damage = damage*70/100;

	// �������� 500��ÿ��һ���ȼ�����Ҫ100������
	count = (skill-150)/50;
	temp = (my["force"] - 500)/100;
	if(count < temp)
		count = temp;
	if(count > 7)
		count = 7;

	message_vision(sprintf(HIR"\n$N˫Ŀ���࣬����ʳ�һ˿��Ѫ��ͻȻ���һ����̫��Ѩ�߹ģ�\n����%s%sѸ���ޱȵ���$n%s��ȥ����\n\n"NOR,
		weapon->name(),HIR,HIR), me, target);

	// ������ȡ����
	ap = COMBAT_D->skill_power(me,"blade",SKILL_USAGE_ATTACK);
	dp = COMBAT_D->skill_power(target,"dodge",SKILL_USAGE_DEFENSE)/4;

	me->receive_damage("kee",damage,"tire");
	me->receive_wound("kee",damage,"tire");
	me->receive_damage("gin",damage,"tire");
	me->receive_wound("gin",damage,"tire");
	me->receive_damage("sen",damage,"tire");
	me->receive_wound("sen",damage,"tire");

	me->add("max_force",-(50+count*10));
	me->set_status_xuruo(10);
	me->start_busy(1);

	if(random(ap + dp) < dp)	// ʧ��
	{
		object env,out;
		mapping exits;
		int flag;
		string dir;

		if(!objectp(env = environment(me)) || !env->is_room())
			return 1;

		if(!mapp(exits = env->query("exits")) || !sizeof(exits))
			flag = 1;

		foreach(string ex,string file in exits)
		{
			if(!objectp(out = find_object(file)))
				out = load_object(file);
			if(!out)
				continue;
			else
			{
				dir = to_chinese(ex);
				break;
			}
		}

		if(!out || flag)
		{
			message_vision("$N�������������㿰�������$n��һ�У�����Ҳ���ŵù�����顣\n",target,me);
			target->start_busy(3);
			return 1;
		}

		message_vision(sprintf("$N��$n����ƴ���з������壬�ŵ�Ťͷ���ܡ�����������\n$N������Ķ��ӡ�\n\n",dir),
			target, me);
		target->move(out);
		tell_room(out,sprintf("%s����ײײ�����˹�������ɫɷ�ס�\n",target->name()),({target}));
		target->start_busy(1);
		return 1;
	}

	message_vision(sprintf(HIB"\n$N��%s���У�����һ��ʹ��ĲҺš�����\n"NOR,weapon->name()),target);

	damage = damage*count*15/100;
	target->start_busy(4);
	target->receive_damage("kee",damage,me);
	target->receive_wound("kee",damage,me);
	target->receive_damage("gin",damage,me);
	target->receive_wound("gin",damage,me);
	target->receive_damage("sen",damage,me);
	target->receive_wound("sen",damage,me);
	COMBAT_D->report_status(target);

	me->start_perform_busy(15);
	return 1;
}
