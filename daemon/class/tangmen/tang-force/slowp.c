// slowp.c
// �ӳ�һ�ζ��ķ�����

int exert(object me, object target)
{
	if(me->query_skill("tang-force", 1) < 150)
		return notify_fail("����ڹ���Ϊ�������޷����ƶ��ء�\n");

	if( me->query("max_force") < 200 )
		return notify_fail("����ڹ���Ϊ�������޷����ƶ��ء�\n");

	if( me->query("force") < 300 )
		return notify_fail("�����ڵ������������޷����ƶ��ķ�����\n");

	me->add("force",-300);
	tell_object(me, "���й�һ���죬��ʱ�ӻ������ڵ�ѪҺ������\n");
	if(me->is_fighting())
		me->start_busy(2);
	return 1;
}
