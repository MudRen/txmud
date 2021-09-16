// zhouyi.c

#include <ansi.h>

inherit SKILL;

string type() { return "knowledge"; }

void skill_improved(object me)
{
	int s,i,level;
	mapping skill_status;
	string *skillname;

	s = me->query_skill("zhouyi", 1);
        if( s%10==9 && me->query("kar") < 35 )
	{
	skill_status = me->query_skills();
	skillname  = keys(skill_status);
	for(i = 0; i < sizeof(skill_status); i++) 
		{
		if(skillname[i] == "zhouyi" || skillname[i] == "huan-rong") continue;
		level = skill_status[skillname[i]]-1;
		if(level < 1)
		me->delete_skill(skillname[i]);
		else
		me->set_skill(skillname[i], level);
		}
	tell_object(me, HIG "\n        由於你对周易演命的探究，你的福缘提高了。\n\n" NOR);
	me->add("kar", 1);
	}

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

