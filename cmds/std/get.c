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

        if( !arg ) return notify_fail("��Ҫ����ʲô������\n");
        if( me->is_busy() )
                return notify_fail("����һ��������û����ɣ�\n");

	if( sscanf(arg, "%s from %s", arg, from)==2 )
	{
		env = present(from, me);
		if(!env) env = present(from, environment(me));
		if(!env) return notify_fail("���Ҳ��� " + from + " ����������\n");
		if(userp(env) && living(env) && (wiz_level(me) <= wiz_level(env)))
			return notify_fail("�����ʦ�ȼ�����ȶԷ��ߣ���������\n");
	}
	else
		env = environment(me);

	if(!wizardp(me) && (env->query("no_get_from")
	|| (env->is_character() && living(env))))
		return notify_fail("���컯�յ������ٰ���\n");

	if(sscanf(arg, "%d %s", amount, item)==2)
	{
		if( !objectp(obj = present(item, env)) )
			return notify_fail("����û������������\n");
		if( !obj->query_amount() )
			return notify_fail( obj->name() + "���ܱ��ֿ����ߡ�\n");
		if( amount < 1 )
			return notify_fail("�����ĸ���������һ����\n");
		if( amount > obj->query_amount() )
			return notify_fail("����û����ô���" + obj->name() + "��\n");

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
				return notify_fail(guards[i]->name()+"��������"+obj->name()+
					"�����κ������ߡ�\n");
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
			return notify_fail("�㻹��ս���У�ֻ��һ����һ����\n");
		if( !env->query_max_encumbrance() )
			return notify_fail("�ǲ���������\n");

		inv = all_inventory(env);
		if( !n=sizeof(inv) )
			return notify_fail("������û���κζ�����\n");

		for(i=0; i<n; i++)
		{
			if( inv[i]->is_character() || inv[i]->query("no_get") )
				continue;
			if(do_get(me, inv[i]))
				flag++;
		}
		if(!flag)
			return notify_fail("����û��ʲô�ܼ�Ķ�����\n");
		if(me->is_fighting())
			me->start_busy(flag>1?2:1);
		write("Ok��\n");
		return 1;
	}

	if( !objectp(obj = present(arg, env)) || living(obj) )
		return notify_fail("�㸽��û������������\n");

	if( obj->query("no_get") && (!wizardp(me)))
		return notify_fail("��������ò�������\n");

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
		return notify_fail("���ﲻ�ܹ�����������ҡ�\n");

#ifdef WIZARD_FLAG
	if(obj->query_wiz_flag() && !wizardp(me))
		return notify_fail("������ʦ��Ʒ���㲻���á�\n");
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
				return notify_fail(guards[i]->name()+"��������"+obj->name()+
					"�����κ������ߡ�\n");
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
			message_vision( "$N��$n�����������ڱ��ϡ�\n", me, obj );
		else
		{
			if(old_env==environment(me))
				pppp =  "����";
			else if(old_env->is_character())
				pppp =  "��" + old_env->name() + "����" + (equipped? "����" : "�ѳ�");
			else switch( old_env->query("position") ) 
			{
				case "on":
					pppp = "��" + old_env->name() + "������";
					break;
				case "under":
					pppp = "��" + old_env->name() + "���ó�";
					break;
				case "behind":
					pppp = "��" + old_env->name() + "���ó�";
					break;
				case "inside":
					pppp = "��" + old_env->name() + "���ó�";
					break;
				default:
					pppp = "��" + old_env->name() + "���ó�";
					break;
			}
			message_vision( sprintf("$N%s%sһ%s$n��\n",	/* Modified by Find. */
				((guard_flag)?"���˲�ע��":""), pppp,
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
ָ���ʽ : get <��Ʒ����> [from <������>]
 
���ָ��������������ϻ������ڵ�ĳ����Ʒ.
 
HELP
    );
    return 1;
}
