inherit FORCE;

void create()
{
        ::create();
        set_yy(1);
}

mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
        mixed foo;

        foo = ::hit_ob(me, victim, damage_bonus, factor);

        return foo;
}

string exert_function_file(string func)
{
        return CLASS_D("jinghai") + "/jinghai-force/" + func;
}

int valid_enable(string usage) 
{ 
        return  usage=="force";
}

int valid_learn(object me)
{
        if(me->query_skill("jinghai-force",1) >= me->query_skill("force",1))
                return notify_fail("����ڹ��ķ������������޷�ѧϰ�����񹦡�\n");
        return 1;
}

/* ���书�Ƿ���ͨ����ϰ��������������Ϊ���� */
int practice_skill(object me)
{
        if(me->query_skill("jinghai-force",1) > 250)
                return 1;
        else
                return notify_fail("������ֻ����ѧ�ġ�\n");
}

int effective_level() { return 11; }

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

