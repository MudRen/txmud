// recognize.c

#include <ansi.h>

inherit SKILL;

string type() { return "knowledge"; }

int valid_learn(object me)
{
        if ((int)me->query_skill("recognize", 1)<10)
                return 1;
    return notify_fail("��ֻ��ͨ��ʵ������߼�������!\n");
}

/*
void skill_improved(object me)
{
        int s;

        s = me->query_skill("recognize", 1);
}
*/

