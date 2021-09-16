// yiqi-force.c
// by Find.

inherit FORCE;

void create()
{
	::create();
	set_yy(1);
}

mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
	mixed foo;
	/*int force;*/

	foo = ::hit_ob(me, victim, damage_bonus, factor);

	return foo;
}

string exert_function_file(string func)
{
	return CLASS_D("shaolin") + "/yiqi-force/" + func;
}

int valid_enable(string usage) 
{ 
	return	usage=="force";
}

int valid_learn(object me)
{
	if(me->query_skill("yiqi-force",1) >= me->query_skill("dacheng-fofa",1))
		return notify_fail("��ķ𷨸����������޷�ѧϰ��Ԫһ������\n");
	return 1;
}

// �ڹ��Ƿ��д�͸���׵�����������ﴫ������ɽ��ţ֮��
int query_through_armor(object me,int factor)
{
	int level,ret;

	if(!me || factor < 10)
		return 0;

	level = me->query_skill("yiqi-force",1);
	if(level < 50)
		return 0;

	ret = (level + factor)/5;
	return ret;
}

/* ���书�Ƿ���ͨ����ϰ��������������Ϊ���� */
int practice_skill(object me)
{
        if(me->query_skill("yiqi-force",1) > 250)
                return 1;
        else
                return notify_fail("��Ԫһ����ֻ����ѧ�ġ�\n");
}

int effective_level() { return 12; }

/* �˺�������ֵԽСԽ������Խ��Խ������0 Ϊ�����Ѷȡ�*/
/* ���ڴ��书����ͨ����ϰ���������Դ˵ش˺���û�ô��� */
int practice_bonus()
{
	return -50;
}


/* �˺�������ֵԽСԽ��ѧ��Խ��Խ��ѧ��0 Ϊ�����Ѷȡ�*/
int learn_bonus()
{
	return -5;
}

/* �������书С�� 75 ��ʱ���˺�������ֵԽСѧ��Խ�졣
 * �������书���� 75 ��ʱ���˺�������ֵԽ��ѧ��Խ�졣
 * �������书���� 75 ��ʱ���˺�������ֵû�����塣
 * Ҳ����˵�˺�������ֵС�����ڳ���ѧϰ����ԽѧԽ��
 * ��������ֵ�󣬳���ѧϰ���ѣ���ԽѧԽ��
 * ��������ֵΪ��������ǰ��׶��Ѷ�û�б仯
 */
int black_white_ness()
{
	return 0;
}
