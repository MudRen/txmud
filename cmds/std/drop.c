// drop.c
// Modified by Find.

#include <ansi.h>
inherit F_CLEAN_UP;

int do_drop(object me, object obj);

int main(object me, string arg)
{
	object obj, *inv, obj2;
	int i, amount;
	string item;

	if(!arg)
		return notify_fail("��Ҫ����ʲô������\n");

	if(sscanf(arg, "%d %s", amount, item)==2)
	{
		if( !objectp(obj = present(item, me)) )
			return notify_fail("������û������������\n");
		if( stringp(obj->query("no_drop")) )
			return notify_fail( (string)obj->query("no_drop") );
		if( !obj->query_amount() )
			return notify_fail( obj->name() + "���ܱ��ֿ�������\n");
		if( amount < 1 )
			return notify_fail("����������������һ����\n");
		if( amount > obj->query_amount() )
			return notify_fail("��û����ô���" + obj->name() + "��\n");
		else if( amount == (int)obj->query_amount() )
			return do_drop(me, obj);
		else
		{
			obj2 = new(base_name(obj));
			obj2->set_amount(amount);
#ifdef WIZARD_FLAG
			if(obj->query_wiz_flag())
				obj2->set_flag(1);
#endif
			if(!do_drop(me,obj2))
			{
				destruct(obj2);
				return 0;
			}
			else
			{
				obj->set_amount( (int)obj->query_amount() - amount );
				if(me->is_fighting())
					me->start_busy(1);
				return 1;
			}
		}
	}

	if(arg=="all")
	{
		int flag = 0;
		inv = all_inventory(me);
		for(i=0; i<sizeof(inv); i++)
		{
			if(do_drop(me, inv[i]))
				flag++;
		}
		if(!flag)
			return notify_fail("������û�п����ӵ��Ķ�����\n");
		if(me->is_fighting())
			me->start_busy(flag>1?2:1);
		write("Ok.\n");
		return 1;
	}

	if(!objectp(obj = present(arg, me)))
		return notify_fail("������û������������\n");
	if(do_drop(me, obj))
	{
		if(me->is_fighting())
			me->start_busy(1);
		return 1;
	}
	else
		return 0;
}

int do_drop(object me, object obj)
{
	mixed no_drop;

	if( no_drop = obj->query("no_drop") )
		return notify_fail( stringp(no_drop) ? no_drop : "���������������ⶪ����\n");

	if (obj->move(environment(me)))
	{
		if( obj->is_character() )
			message_vision("$N��$n�ӱ��Ϸ������������ڵ��ϡ�\n", me, obj);
		else if( (obj->query("material") == "glass")/* ���� */
			|| (obj->query("material") == "porcelain") /* �� */)
		{
			message_vision(sprintf("$N����һ%s$n��$n���ڵ���ˤ���ˡ�\n",obj->query("unit")),me,obj);
			destruct(obj);
		}

		else if( obj->query("disappear"))/* ��������ʧ by dicky */
		{
			message_vision(sprintf(HIB"$N����һ%s$n��$n" HIB "���ڵ���ͻȻ��ʧ�����ˡ�\n"NOR,obj->query("unit")),me,obj);
			destruct(obj);
		}

		else {
			message_vision( sprintf("$N����һ%s$n��\n",	obj->query("unit")),
				me, obj );
			me->save();
			if( !obj->query("value") && !obj->value() ) {
				write("��Ϊ������������ֵǮ���������ǲ�����ע�⵽���Ĵ��ڡ�\n");
				destruct(obj);
			}
		}
		return 1;
	}
	return 0;
}

int help(object me)
{
	write(@HELP
ָ���ʽ : drop <��Ʒ����>
 
���ָ��������㶪������Я������Ʒ.
 
HELP
    );
    return 1;
}