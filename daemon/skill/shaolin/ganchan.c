// ganchan.c
// by Find.

inherit SKILL;

string *dodge_msg = ({
	"ֻ��$n˫��ɶ�������ٿ�����Ա�һ����$N����ʽ��ȫ��ա�\n",
	"$nһʽ���������ơ���˲�����Ѳ�������Ӱ��\n",
	"$n˫��һ�ţ�ת����Ʈ���߳�֮�⣬$N����ʽ��$n˿������\n",
	"ֻ��$n����һš������ߣ�$N���з�������ա�\n"
});

int valid_enable(string usage) 
{ 
	return (usage == "dodge") || (usage == "move"); 
}

int valid_learn(object me) { return 1; }

string query_dodge_msg(string limb)
{
       return dodge_msg[random(sizeof(dodge_msg))];
}

int effective_level() { return 12;}

int practice_skill(object me)
{
        if( (int)me->query("kee") < 40 )
                return notify_fail("�������̫���ˣ�������ϰ�˲��ϲ���\n");
        me->receive_damage("kee", 30, "tire");
        return 1;
}

/* �˺�������ֵԽСԽ������Խ��Խ������0 Ϊ�����Ѷȡ�*/
int practice_bonus()
{
	return -50;
}


/* �˺�������ֵԽСԽ��ѧ��Խ��Խ��ѧ��0 Ϊ�����Ѷȡ�*/
int learn_bonus()
{
	return -20;
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
	return -20;
}
