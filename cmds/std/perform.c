// perform.c
// Modified by Find.

inherit F_CLEAN_UP;

protected int try_action(object me,string skill,string martial,string ack,int flag);

int main(object me, string arg)
{
	object weapon;
	string martial, skill;
        
	if( me->is_busy() )
		return notify_fail(BUSY_MESSAGE);

	if( !stringp(arg) || (arg == "") )
		return notify_fail("你要施展什么特殊招式？\n");

	notify_fail("你请先用 enable 指令选择你要使用的外功。\n");

	sscanf(arg, "%s.%s", martial, arg);

	if(weapon = me->query_temp("weapon"))
	{
		if(!martial)
			martial = weapon->query("skill_type");
		if(martial == weapon->query("skill_type"))
		{
			if(stringp(skill = me->query_skill_mapped(martial)) || (martial == "throwing"))
				return try_action(me,skill,martial,arg,0);
			return 0;
		}
	}

	if( weapon = me->query_temp("secondary_weapon") )
	{
		if(!martial)
			martial = weapon->query("skill_type");
		if(martial == weapon->query("skill_type"))
		{
			if(stringp(skill = me->query_skill_mapped(martial)) || (martial == "throwing"))
				return try_action(me,skill,martial,arg,1);
			return 0;
		}
	}

	if((martial != "unarmed") && (martial != "dodge"))
		return 0;
	if(stringp(skill = me->query_skill_mapped(martial)))
		return try_action(me,skill,martial,arg,0);
	return 0;
}

protected int try_action(object me,string skill,string martial,string ack,int flag)
{
	notify_fail("你所使用的外功中没有这种功能。\n");

	if( skill && SKILL_D(skill)->perform_action(me, ack, flag) )
	{
		if( (random(120) < (int)me->query_skill(skill,1)) )
			me->improve_skill(skill, 1, 1);
		return 1;
	}

	else if( SKILL_D(martial)->perform_action(me, ack, flag) )
	{
		if( (skill != "throwing") && (random(120) < (int)me->query_skill(martial, 1)) )
			me->improve_skill(martial, 1, 1);
		return 1;
	}
	return 0;
}

int help (object me)
{
        write(@HELP
指令格式：perfrom [<武功种类>.]<招式名称> [<施用对象>]

如果你所学的外功(拳脚、剑法、刀法....)有一些特殊的攻击方式或招式，可以
用这个指令来使用，你必须先用 enable 指令指定你使用的武功，不指定武功种
类时，空手的外功是指你的拳脚功夫，使用武器时则是兵刃的武功。

若是你的外功中有种类不同，但是招式名称相同的，或者不属於拳脚跟武器技能
的武功(如轻功)，可以用 <武功>.<招式>  的方式指定，如：

perform sword.powerfocus 
perform move.reflexion

换句话说，只要是 enable 中的武功有特殊招式的，都可以用这个指令使用。
HELP
        );
        return 1;
}
