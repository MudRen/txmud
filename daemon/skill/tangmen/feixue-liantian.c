// feixue-liantian.c ��ѩ����/�ع� xue.c �����ѩ

inherit SKILL;

mapping *action = ({
([      "action":"$N��һ�ʹһʽ����ѩ��ǰ�塹��ֻ��������������ö$wǰ��������$n��$l���",
        "dodge" : -10,
        "damage": 45,
        "damage_type":  "����",
	"post_action":  (: call_other, __FILE__, "throw_weapon" :),
]),
([      "action":"$N���κ��ظ߸�Ծ��ʹһʽ����ѩ�������������ö$w��$n�������",
        "dodge" : -10,
        "damage": 60,
        "damage_type":  "����",
	"post_action":  (: call_other, __FILE__, "throw_weapon" :),
]),
([      "action":"$Nһʽ����ѩ�����硹����һ������ö$w���Ӷ���������$n����Ȼתͷ��$n���ķ�ȥ",
        "dodge" : 45,
        "damage": 130,
        "damage_type":  "����",
	"post_action":  (: call_other, __FILE__, "throw_weapon" :),
]),
([      "action":"$N����ͻ�ص������������һ����ʹһ�С���ѩ�Ժ��졹�����а��۵���ö$w��Ѹ�ײ����ڶ�֮������$n����",
        "dodge" : 10,
        "damage": 55, 
        "damage_type":  "����",
	"post_action":  (: call_other, __FILE__, "throw_weapon" :),
]),
([      "action":"$N����һ��������$n��󣬷���һʽ����������ѩ����������ö$w��$n�ĺ���Ҫ����ȥ",
        "dodge" : 35,
        "damage": 160,
        "damage_type":  "����",
	"post_action":  (: call_other, __FILE__, "throw_weapon" :),
]),
([      "action":"$Nһʽ����ѩ��Ǭ������ͻȻ˫���������£�ʮ��ö$w�������ط���$n��ǰ��",
        "dodge" : 60,
        "damage": 155,
        "damage_type":  "����",
	"post_action":  (: call_other, __FILE__, "throw_weapon" :),
]),
});

int valid_learn(object me)
{
        object ob;

        if( !(ob = me->query_temp("weapon"))
        || (string)ob->query("skill_type") != "throwing" )
                return notify_fail("û�а�������ô����ѩ���졣\n");

        if( (int)me->query("max_force") < 50 )
        if( (int)me->query("max_force") < 50 ) 
                return notify_fail("��������������޷�ѧϰ��ѩ���졣\n");
        if( (me->query_skill("tang-force",1) <= 15)
        || (me->query_skill("feixue-liantian",1) >= me->query_skill("tang-force",1)) )
                return notify_fail("��������ڹ���Ϊ�������޷�ѧϰ��ѩ���졣\n");

        return 1;
}

int valid_enable(string usage)
{
        return usage=="throwing" || usage=="parry" || usage=="unarmed";}

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

int practice_skill(object me)
{
        if( (int)me->query("kee") < 30 || (int)me->query("force") < 3 )
                return notify_fail("�����������������û�а취��ϰ��ѩ���졣\n");
        me->receive_damage("kee", 30, "tire");
        me->receive_damage("kee", 30, "tire"); 
        me->add("force", -3);
        write("�㰴����ѧ����һ���ѩ���졣\n");
        return 1;
}

int effective_level() { return 12;}

int learn_bonus()
{
        return -20;
}

int practice_bonus()
{
        return -40;
}

int black_white_ness()
{
        return -10;
}

string *parry_msg = ({ 
        "$n��ָһ����һö$v����һ��������$N��$w��\n",
});

string *unarmed_parry_msg = ({
        "$n���ִ����ö$v������ǰ����ܲ�͸�磬$N���γ�ȥ�˹��ơ�\n",
});

string query_parry_msg(object weapon)
{
        if( weapon )
                return parry_msg[random(sizeof(parry_msg))];
        else
                return unarmed_parry_msg[random(sizeof(unarmed_parry_msg))];
}

string perform_action_file(string action)
{
        return CLASS_D("tangmen") + "/feixue-liantian/" + action;
}
