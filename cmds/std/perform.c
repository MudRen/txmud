// perform.c
// Modified by Find.

inherit F_CLEAN_UP;

protected int try_action(object me,string skill,string martial,string ack,int flag);

int main(object me, string arg)
{
	object weapon;
	string martial, skill;
        
	if( me->is_busy() )
		return notify_fail(BUSY_MESSAGE);

	if( !stringp(arg) || (arg == "") )
		return notify_fail("��Ҫʩչʲô������ʽ��\n");

	notify_fail("�������� enable ָ��ѡ����Ҫʹ�õ��⹦��\n");

	sscanf(arg, "%s.%s", martial, arg);

	if(weapon = me->query_temp("weapon"))
	{
		if(!martial)
			martial = weapon->query("skill_type");
		if(martial == weapon->query("skill_type"))
		{
			if(stringp(skill = me->query_skill_mapped(martial)) || (martial == "throwing"))
				return try_action(me,skill,martial,arg,0);
			return 0;
		}
	}

	if( weapon = me->query_temp("secondary_weapon") )
	{
		if(!martial)
			martial = weapon->query("skill_type");
		if(martial == weapon->query("skill_type"))
		{
			if(stringp(skill = me->query_skill_mapped(martial)) || (martial == "throwing"))
				return try_action(me,skill,martial,arg,1);
			return 0;
		}
	}

	if((martial != "unarmed") && (martial != "dodge"))
		return 0;
	if(stringp(skill = me->query_skill_mapped(martial)))
		return try_action(me,skill,martial,arg,0);
	return 0;
}

protected int try_action(object me,string skill,string martial,string ack,int flag)
{
	notify_fail("����ʹ�õ��⹦��û�����ֹ��ܡ�\n");

	if( skill && SKILL_D(skill)->perform_action(me, ack, flag) )
	{
		if( (random(120) < (int)me->query_skill(skill,1)) )
			me->improve_skill(skill, 1, 1);
		return 1;
	}

	else if( SKILL_D(martial)->perform_action(me, ack, flag) )
	{
		if( (skill != "throwing") && (random(120) < (int)me->query_skill(martial, 1)) )
			me->improve_skill(martial, 1, 1);
		return 1;
	}
	return 0;
}

int help (object me)
{
        write(@HELP
ָ���ʽ��perfrom [<�书����>.]<��ʽ����> [<ʩ�ö���>]

�������ѧ���⹦(ȭ�š�����������....)��һЩ����Ĺ�����ʽ����ʽ������
�����ָ����ʹ�ã���������� enable ָ��ָ����ʹ�õ��书����ָ���书��
��ʱ�����ֵ��⹦��ָ���ȭ�Ź���ʹ������ʱ���Ǳ��е��书��

��������⹦�������಻ͬ��������ʽ������ͬ�ģ����߲����ȭ�Ÿ���������
���书(���Ṧ)�������� <�书>.<��ʽ>  �ķ�ʽָ�����磺

perform sword.powerfocus 
perform move.reflexion

���仰˵��ֻҪ�� enable �е��书��������ʽ�ģ������������ָ��ʹ�á�
HELP
        );
        return 1;
}
