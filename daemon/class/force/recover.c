// recover.c

inherit SSERVER;

int exert(object me, object target)
{
	int diff, neilineed;
	int eff,now,ef,f;

	if( target != me )
		return notify_fail("��ֻ�����ڹ������Լ�����Ϣ��\n");

	if( (f = (int)me->query("force")) < 20 )
		return notify_fail("�������������\n");
	if( (ef = (int)me->query_skill("force")) < 10 )
		return notify_fail("����ڹ���Ϊ������\n");	

	eff = me->query("eff_kee");
	now = me->query("kee");

	diff = eff - now;

	if(diff < 1)
		return notify_fail("��������Ѫ��ӯ������Ҫ�й��������䡣\n");

	neilineed = diff * 50 / ef;

	if(neilineed < 1)
		neilineed = 1;

	if(neilineed > f)
		neilineed = f;
	diff = neilineed * ef / 50;

	if( diff < (eff - now) && neilineed < f )
	{
		neilineed++;
		diff = (eff - now);
	}

	me->receive_heal("kee", diff);
	me->add("force", -neilineed);

	message_vision("$N�������˼���������ɫ�������ö��ˡ�\n", me);

	if( me->is_fighting() )
		me->start_busy(1);

	return 1;
}
