// piaoyu-steps.c
// Ʈ�경��

inherit SKILL;

string *dodge_msg = ({
        "$nһ�С�����Ʈ�㡹������һԾ����������ɣ������пհ���ӯ��������\n",
        "$nһʽ��ϸ�����ࡹ��������������棬ͽȻ�������ɡ���\n",
        "$nһʽ���紵ѩ�衹������������������Ȱ�Ʈ�����ߡ�\n"
});

int valid_enable(string usage)
{
        return (usage=="dodge");
}

int valid_learn(object me)
{
        return 1;
}

string query_dodge_msg(string limb)
{
        return dodge_msg[random(sizeof(dodge_msg))];
}

string perform_action_file(string action)
{
        return CLASS_D("rain") + "/piaoyu-steps/" + action;
}

int practice_skill(object me)
{
        if( me->query("kee") < 30 )
                return notify_fail("�������̫���ˣ���������Ʈ�경������\n");
        me->receive_damage("kee", 20,"tire");
        return 1;
}
int effective_level() { return 13;}

int learn_bonus()
{
        return 0;
}
int practice_bonus()
{
        return 0;
}
int black_white_ness()
{
        return 0;
}

