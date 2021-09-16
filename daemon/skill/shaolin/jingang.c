// jingang.c

inherit FORCE;

int valid_enable(string usage) { return usage=="iron-cloth"; }

int valid_learn(object me)
{
	if(me->query("max_force") < 500)
		return notify_fail("�������̫�ͣ��޷���ϰ��ղ����񹦡�\n");
	else
		return 1;
}

int practice_skill(object me)
{
	return notify_fail("��ղ�����ֻ����ѧ�ġ�\n");
}

int effective_level() { return 12;}

string *absorb_msg = ({
        "$n˫��һ�𣬽�ղ������������Ƶ����ȶ�����\n",
        "$nʩչ����ղ������еġ������־���һ�ɵ�������$N�����ڡ�\n",
        "$nʹ��һ�С��ຣ���ġ�������Ϊʵ������Ӳ���ա�\n",
        "$nʩչ����ղ��������Կ�$N��һ��֮����\n",
});

string query_absorb_msg()
{
        return absorb_msg[random(sizeof(absorb_msg))];
}

int bounce_ratio()
{
	return 10;
}

int learn_bonus()
{
	return -50;
}
int practice_bonus()
{
	return -80;
}
int black_white_ness()
{
	return -20;
}

