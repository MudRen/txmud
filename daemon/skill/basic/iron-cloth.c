// iron-cloth.c

inherit SKILL;

string *absorb_msg = ({
	"$n����׼�������Ų�æ��������������\n",
        "$n��Ŀ��������ȫ������Ӳ���ﵽ�۷�״̬��\n",
        "$n���١���һ�������㲻��������������ӭ��$N��\n",
});

string query_absorb_msg()
{
	return absorb_msg[random(sizeof(absorb_msg))];
}

int learn_bonus()
{
	return 10;
}
int practice_bonus()
{
	return 0;
}
int black_white_ness()
{
	return 0;
}

mixed absorb_ob(object victim, object me, int damage, int absp)
{
	int eff;

	eff = -damage/4;

	return eff;
}