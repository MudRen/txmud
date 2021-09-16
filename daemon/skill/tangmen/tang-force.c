// tang-force.c
// by Find.
// 唐门内功

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
	return CLASS_D("tangmen") + "/tang-force/" + func;
}

int valid_enable(string usage) 
{ 
	return	usage=="force";
}

int valid_learn(object me)
{
	return 1;
}

// 内功是否有穿透护甲的能力，如借物传力、隔山打牛之类
int query_through_armor(object me,int factor)
{
	return 0;
/*
	int level,ret;

	if(!me || factor < 10)
		return 0;

	level = me->query_skill("tang-force",1);
	if(level < 50)
		return 0;

	ret = (level + factor)/5;
	return ret;
*/
}

/* 此武功是否能通过练习增长，返回零意为不能 */
int practice_skill(object me)
{
        if(me->query_skill("tang-force",1) >= 250)
                return 1;
        else
                return notify_fail("以你目前唐门内功的修为，只能通过学习来提高。\n");
}

int effective_level() { return 10; }

/* 此函数返回值越小越难练，越大越好练，0 为正常难度。*/
/* 由于此武功不能通过练习增长，所以此地此函数没用处。 */
int practice_bonus()
{
	return 0;
}


/* 此函数返回值越小越难学，越大越好学，0 为正常难度。*/
int learn_bonus()
{
	return 0;
}

/* 当这项武功小于 75 级时，此函数返回值越小学的越快。
 * 当这项武功大于 75 级时，此函数返回值越大学的越快。
 * 当这项武功等于 75 级时，此函数返回值没有意义。
 * 也就是说此函数返回值小，利于初期学习，但越学越难
 * 函数返回值大，初期学习很难，但越学越快
 * 函数返回值为零正常，前后阶段难度没有变化
 */
int black_white_ness()
{
	return 0;
}
