// get.c
// Modified by Find.

#include <ansi.h>

inherit F_CLEAN_UP;

varargs int do_get(object me, object ob,object env);

int main(object me, string arg)
{
        string from, item;
        object obj, *inv, env, obj2;
        int i, amount;
	object *guards;

        if( !arg ) return notify_fail("你要捡起什么东西？\n");
        if( me->is_busy() )
                return notify_fail("你上一个动作还没有完成！\n");

	if( sscanf(arg, "%s from %s", arg, from)==2 )
	{
		env = present(from, me);
		if(!env) env = present(from, environment(me));
		if(!env) return notify_fail("你找不到 " + from + " 这样东西。\n");
		if(userp(env) && living(env) && (wiz_level(me) <= wiz_level(env)))
			return notify_fail("你的巫师等级必须比对方高，才能搜身。\n");
	}
	else
		env = environment(me);

	if(!wizardp(me) && (env->query("no_get_from")
	|| (env->is_character() && living(env))))
		return notify_fail("光天化日的想抢劫啊？\n");

	if(sscanf(arg, "%d %s", amount, item)==2)
	{
		if( !objectp(obj = present(item, env)) )
			return notify_fail("这里没有这样东西。\n");
		if( !obj->query_amount() )
			return notify_fail( obj->name() + "不能被分开拿走。\n");
		if( amount < 1 )
			return notify_fail("东西的个数至少是一个。\n");
		if( amount > obj->query_amount() )
			return notify_fail("这里没有那么多的" + obj->name() + "。\n");

		guards = obj->query_temp("guarded");
		if(arrayp(guards))
		{
			for(i=0;i<sizeof(guards);i++)
			{
				if(guards[i] == me) continue;
				if( guards[i] && environment(guards[i]) == environment(obj))
				{
				if( ( random(guards[i]->query_skill("unarmed"))
					+guards[i]->query_skill("unarmed") )/2
					> me->query_skill("unarmed") )
					{
				if(!guards[i]->is_busy())
				return notify_fail(guards[i]->name()+"正看守着"+obj->name()+
					"不让任何人拿走。\n");
					}
				}
			}
		}

		if( amount == (int)obj->query_amount() )
		{
			if(do_get(me, obj))
			{
				if(me->is_fighting())
					me->start_busy(1);
				return 1;
			}
			return 0;
		}

		else
		{
			int sum = obj->query_amount();
			obj2 = new(base_name(obj));
			obj2->set_amount(amount);
#ifdef WIZARD_FLAG
			if(obj->query_wiz_flag())
				obj2->set_flag(1);
#endif
			if(do_get(me, obj2,env))
			{
				obj->set_amount( sum - amount );
				if(me->is_fighting())
					me->start_busy(1);
				return 1;
			}
			else
			{
				destruct(obj2);
				return 0;
			}
		}
	}

	if(arg=="all")
	{
		int n,flag;
		if( me->is_fighting() )
			return notify_fail("你还在战斗中！只能一次拿一样。\n");
		if( !env->query_max_encumbrance() )
			return notify_fail("那不是容器。\n");

		inv = all_inventory(env);
		if( !n=sizeof(inv) )
			return notify_fail("那里面没有任何东西。\n");

		for(i=0; i<n; i++)
		{
			if( inv[i]->is_character() || inv[i]->query("no_get") )
				continue;
			if(do_get(me, inv[i]))
				flag++;
		}
		if(!flag)
			return notify_fail("这里没有什么能捡的东西。\n");
		if(me->is_fighting())
			me->start_busy(flag>1?2:1);
		write("Ok。\n");
		return 1;
	}

	if( !objectp(obj = present(arg, env)) || living(obj) )
		return notify_fail("你附近没有这样东西。\n");

	if( obj->query("no_get") && (!wizardp(me)))
		return notify_fail("这个东西拿不起来。\n");

	if(do_get(me, obj))
	{
		if(me->is_fighting())
			me->start_busy(1);
		return 1;
	}
	else
		return 0;
}

varargs int do_get(object me, object obj,object env)
{
        object old_env;
        int equipped;
	string pppp,unit;
	object *guards;
	int i,guard_flag=0,sum;

	if( !obj )
		return 0;

	if(function_exists("valid_get", obj) && !obj->valid_get(me))
		return 1;

	if( userp(obj) &&  environment(obj)->query("user_compare") )
		return notify_fail("这里不能够背负其他玩家。\n");

#ifdef WIZARD_FLAG
	if(obj->query_wiz_flag() && !wizardp(me))
		return notify_fail("那是巫师物品，你不能拿。\n");
#endif

	old_env = environment(obj);
	if(!old_env)
		old_env = env;
	if(!old_env)
		return 0;

	if( obj->is_character() )
	{
                if( living(obj) ) return 0;
	}
	else
	{
		if( obj->query("no_get")&&(!wizardp(me)))
			return 0;

		guards = obj->query_temp("guarded");
		if(arrayp(guards))
		{
			for(i=0;i<sizeof(guards);i++)
			{
				if(guards[i] == me) continue;
                                if( guards[i] && environment(guards[i]) == old_env)
				{
				guard_flag = 1;
				if( ( random(guards[i]->query_skill("unarmed"))
					+guards[i]->query_skill("unarmed") )/2
					> me->query_skill("unarmed") )
					{
				if(!guards[i]->is_busy())
				return notify_fail(guards[i]->name()+"正看守着"+obj->name()+
					"不让任何人拿走。\n");
					}
				}
			}
		}
        }

	if( obj->query("equipped") ) equipped = 1;
	unit = (sum=obj->query_amount())&&(sum==1)?obj->query("base_unit"):obj->query("unit");
	if( obj->move(me) )
	{
		if( obj->is_character() )
			message_vision( "$N将$n扶了起来背在背上。\n", me, obj );
		else
		{
			if(old_env==environment(me))
				pppp =  "捡起";
			else if(old_env->is_character())
				pppp =  "从" + old_env->name() + "身上" + (equipped? "除下" : "搜出");
			else switch( old_env->query("position") ) 
			{
				case "on":
					pppp = "从" + old_env->name() + "上拿起";
					break;
				case "under":
					pppp = "从" + old_env->name() + "下拿出";
					break;
				case "behind":
					pppp = "从" + old_env->name() + "后拿出";
					break;
				case "inside":
					pppp = "从" + old_env->name() + "中拿出";
					break;
				default:
					pppp = "从" + old_env->name() + "中拿出";
					break;
			}
			message_vision( sprintf("$N%s%s一%s$n。\n",	/* Modified by Find. */
				((guard_flag)?"趁人不注意":""), pppp,
				unit), me, obj );
			obj->delete_temp("guarded");
		}
                return 1;
	}
        else
		return 0;
}

int help(object me)
{
        write(@HELP
指令格式 : get <物品名称> [from <容器名>]
 
这个指令可以让你捡起地上或容器内的某样物品.
 
HELP
    );
    return 1;
}
