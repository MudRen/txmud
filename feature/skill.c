// skill.c
// Modified by Find.

#include <ansi.h>
#include <dbase.h>

mapping skills = ([]);
mapping learned = ([]);
mapping skill_map = ([]);

protected nosave int max_skill_level = 0;

int query_max_skill_level() { return max_skill_level; }

protected void count_max_skill_level()
{
	if(max_skill_level < 50)
		max_skill_level = 50;

	if(!mapp(skills) || !sizeof(skills))
		return;

	foreach(string sk, int lv in skills)
	{
		if(sk == "chanting")
			continue;
		if(max_skill_level < lv)
			max_skill_level = lv;
	}
}

int modify_skill(string skill)
{
	mapping yjj;

	if( (this_object()->query("class") != "shaolin")
	|| !previous_object()
	|| (geteuid(previous_object()) != ROOT_UID) )
		return 0;

	if( (query_skill_class(skill) != "shaolin") )
		return 0;

	if(!mapp(yjj = this_object()->query("family/yijin-jing"))
	|| undefinedp(yjj["level"])
	|| yjj["level"] <= 0
	|| yjj["level"] > 12)
		return 0;

	// 100 ����ǰû������ֵ
	if(!mapp(skills) || undefinedp(skills[skill]) || (skills[skill] < 100) )
		return 0;

	if(yjj["level"] <= 2)
		return yjj["level"];

	if(yjj["level"] <= 9)
		return 2 + (yjj["level"] - 2)*2;

	return 16 + (yjj["level"] - 9) * 10;
}

mapping query_skills()
{
	return skills;
}

void delete_all_skills()
{
	skills = ([]);
	learned = ([]);
	skill_map = ([]);
}

string *query_skills_name()
{
	if(mapp(skills))
		return keys(skills);
	else
		return 0;
}

mapping query_learned() { return learned; }

void set_skill(string skill, int val)
{
        if( !find_object(SKILL_D(skill))
        && file_size(SKILL_D(skill)+".c") < 0 )
                error("F_SKILL: No such skill (" + skill + ")\n");

        if( !mapp(skills) ) skills = ([ skill: val ]);
        else skills[skill] = val;

// added by find.
        if(!userp(this_object()) || wizardp(this_object()))
                return;
        if( !wizardp(this_object())
	&& (previous_object() && (previous_object()->query_wiz_flag()
	|| sscanf(file_name(previous_object()),WIZ_DIR"%*s")))
	|| (this_player(1) && wizardp(this_player(1))) )
        {
	sys_log("set_skill",sprintf("(%s) set_skill (%s) skill:%s, val:%d, pre_obj:%s\n",
		this_player(1)?geteuid(this_player(1)):geteuid(previous_object()),
		geteuid(this_object()),skill,val,
                previous_object()?file_name(previous_object()):"none"));
        }
// end.

}

int delete_skill(string skill)
{
	string where,*basics;
	int i;

	if( mapp(skills) )
	{
		if(undefinedp(skills[skill]))
			return 0;
		map_delete(skills, skill);

		 /* Modified by Find. �����������ص� bug. */
		if(mapp(skill_map))
		{
			if(!sscanf(SKILL_D(skill),"/daemon/skill/%s/"+skill,where))
				return 0;
			if(where == "basic")
				map_delete(skill_map,skill);
			else
			{
				basics = keys(skill_map);
				for(i=0;i<sizeof(basics);i++)
				{
					if(skill_map[basics[i]] == skill)
						map_delete(skill_map,basics[i]);
				}
			}
		}

		if( mapp(learned) )
		{
			map_delete(learned, skill);
			return undefinedp(learned[skill]);
		}
		return undefinedp(skills[skill]);
	}
	return 0;
}

// This function 'map' a skill <skill> to another skill <mapped_to>.
// If 2nd argument not given, cancel the mapped skill <skill>.
varargs void map_skill(string skill, string mapped_to)
{
        if( !mapped_to && mapp(skill_map) ) {
                map_delete(skill_map, skill);
                return;
        }

        if( !find_object(SKILL_D(skill))
        &&      file_size(SKILL_D(skill)+".c") < 0 )
                error("F_SKILL: No such skill (" + skill + ")\n");

        if( !mapp(skills) || undefinedp(skills[mapped_to]) )
                return;
                
        if( !mapp(skill_map) ) skill_map = ([ skill: mapped_to ]);
        else skill_map[skill] = mapped_to;
}

string query_skill_mapped(string skill)
{
        if( mapp(skill_map) && !undefinedp(skill_map[skill]) )
                        return skill_map[skill];
                 else{
        return 0;}
}

varargs int query_skill(string skill, int raw) /*Modified by Find*/
{
	object weapon;  // added by find.

	if( !raw )
	{
		int s,level;
		s = query_temp("apply/" + skill);
		if( mapp(skills) )
		{
			if(undefinedp(skills[skill]))
				return s;
			s += skills[skill] / 2;
			if( mapp(skill_map) )
			{
				if( skill_map[skill])
				{
					level = (int) (SKILL_D(skill_map[skill])->effective_level());
					if(!level) level = 10;
				}
				else
					level = 0;
// added by find.>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
// 1. �������û��������,���ĸ߼� parry ��������.
// 2. ������������������书������� enable �ĸ߼� parry ���಻��,�߼� parry Ҳ��������.
				if(skill == "parry")
				{
					if(!weapon = this_object()->query_temp("weapon"))
						level = 0;
					else if(level != 0)
					{
						int tmp;
						if(!SKILL_D(skill_map[skill])->valid_enable(weapon->query("skill_type")))
							level = 0;
						else if( tmp = (SKILL_D(skill_map[skill])->effective_parry_level()) )
							level = tmp;
					}
				}
// end.<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

				s += (skills[skill_map[skill]]+modify_skill(skill_map[skill])+query_temp(sprintf("apply/%s",skill_map[skill]))) * level / 10;
			}
		}
		return s;
	}
	if( mapp(skills) && !undefinedp(skills[skill]) )
		return skills[skill] + modify_skill(skill);
	else
		return 0;
}

mapping query_skill_map()
{
	return skill_map;
}

int skill_death_penalty()
{
	string *sk;
	int i;
	if( !mapp(skills) ) return 0;

	sk = keys(skills);
	if( !mapp(learned) )
		for(i = 0; i<sizeof(sk); i++)
		{
			skills[sk[i]]--;
			if( skills[sk[i]]<0 ) delete_skill(sk[i]);
		}
	else
		for(i = 0; i<sizeof(sk); i++)
		{
			if( (int)learned[sk[i]] > (skills[sk[i]]+1) * (skills[sk[i]]+1) / 2 )
				map_delete(learned, sk[i]);
			else
			{
				skills[sk[i]]--;
				if( skills[sk[i]]<0 ) delete_skill(sk[i]);
			}
		}
	if(max_skill_level > 50)
		max_skill_level--;
	return 1;
}

varargs void 
improve_skill(string skill, int amount, int weak_mode)
{
        if( !find_object(SKILL_D(skill))
        && file_size(SKILL_D(skill)+".c") < 0 )
                error("F_SKILL: No such skill (" + skill + ")\n");

	if( !weak_mode || !userp(this_object()) )
	{
		if( !mapp(skills) ) skills = ([]);
		if( undefinedp(skills[skill]) ) skills[skill] = 0;
        }

        if( !amount ) amount = 1;

	if( !mapp(learned) )
		learned = ([ skill : amount ]);
        else
		(int)learned[skill] += amount;

        if( (!weak_mode || !userp(this_object()))
	&& learned[skill] > (skills[skill] + 1) * (skills[skill] + 1) )
	{
                skills[skill]++;
		if( (skill != "chanting") && userp(this_object()))
		{
			if(!max_skill_level)
				count_max_skill_level();
			if(max_skill_level < skills[skill])
				max_skill_level = skills[skill];
		}
		learned[skill] = 0;
		tell_object(this_object(), HIC "��ġ�" + to_chinese(skill) + "�������ˣ�\n" NOR);
		SKILL_D(skill)->skill_improved(this_object());
        }
}

// ������
int query_sd(string skill)
{
	if(!mapp(skills))
		skills = ([]);
	if(!mapp(learned))
		learned = ([]);

	if( !stringp(skill)
	|| undefinedp(skills[skill])
	|| undefinedp(learned[skill]) )
		return 0;

	return learned[skill];
}

void add_shimen_gongji(int n)
{
	int gj, mgj;

	if( (n <= 0)
	|| !mapp(query("family"))
	|| !mapp(skills)
	|| !sizeof(skills) )
		return;

	if(!max_skill_level)
		count_max_skill_level();

	gj = query("family/gongji");
	mgj = (max_skill_level+10)*(max_skill_level+10);

	if(gj > mgj)
	{
		set("family/gongji", mgj);
		return;
	}

	if( gj < mgj )
		set("family/gongji", (gj+n)>mgj?mgj:(gj+n));
}
