// yi.c
// ���л�Ӱ yi
// �������[tianchan-steps] ���ع�

#include <ansi.h>
#include <combat.h>

int perform(object me, object target)
{
	int skill,mp,tp, n, i, nub;
	object env, *enemy;
	mapping exits;
	string *dirs = ({});

	if(me->is_busy())
		return notify_fail("����һ������û����ɣ��޷�ʹ�á��ҷ�ȱ�����\n");

	if((skill = me->query_skill("tianchan-steps",1)) < 180)
		return notify_fail("��ġ�����������������㣬û�����л�Ӱ��\n");

	if(!n = sizeof(enemy = me->query_enemy()))
		return notify_fail("�����л�Ӱ������ս����ʹ�õļ��ܡ�\n");

	if( me->query("force") < 100 )
		return notify_fail("����������㣬�޷�ʩչ�����л�Ӱ����\n");

	if(!(env = environment(me)) || !sizeof(exits = env->query("exits")) )
		return notify_fail("�˵��޷�ʩչ�����л�Ӱ����\n");

	foreach(string dir, string file in exits)
	{
		if(env->valid_leave(me, dir))
			dirs += ({ file });
	}

	if(!sizeof(dirs))
		return notify_fail("�˵��޷�ʩչ�����л�Ӱ����\n");

	me->add("force",-100);

	message_vision(HIB"\n$N���м�ת���ż���һè����ʩչ�������л�Ӱ����\n", me);

	mp = COMBAT_D->skill_power(me,"dodge",SKILL_USAGE_DEFENSE);

	if(n>4)
		n=4;
	for(i=0; i<n; i++)
	{
		int tmp;
		if( tp < (tmp = COMBAT_D->skill_power(enemy[i],"dodge",SKILL_USAGE_DEFENSE)) )
		{
			tp = tmp;
			nub = i;
		}
	}

	if(mp >= random(tp*0.6))	// �ɹ�
	{
		if(!me->move(dirs[random(sizeof(dirs))]))
			return notify_fail("�˵ص��д���������֪ͨ����Ա����\n");
		tell_room(env, sprintf("��ֻ������ǰ��Ӱһ�Σ�ʧȥ��%s����Ӱ��\n", me->name()));
		me->start_busy(1);
		return 1;
	}

	message_vision("$N������$n����ͼ��һ����ס��$n����·��\n", enemy[nub], me);
	me->start_busy(2);

	me->start_perform_busy(12);
	return 1;
}
