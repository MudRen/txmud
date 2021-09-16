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
		return notify_fail("你要丢弃什么东西？\n");

	if(sscanf(arg, "%d %s", amount, item)==2)
	{
		if( !objectp(obj = present(item, me)) )
			return notify_fail("你身上没有这样东西。\n");
		if( stringp(obj->query("no_drop")) )
			return notify_fail( (string)obj->query("no_drop") );
		if( !obj->query_amount() )
			return notify_fail( obj->name() + "不能被分开丢弃。\n");
		if( amount < 1 )
			return notify_fail("东西的数量至少是一个。\n");
		if( amount > obj->query_amount() )
			return notify_fail("你没有那么多的" + obj->name() + "。\n");
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
			return notify_fail("你身上没有可以扔掉的东西。\n");
		if(me->is_fighting())
			me->start_busy(flag>1?2:1);
		write("Ok.\n");
		return 1;
	}

	if(!objectp(obj = present(arg, me)))
		return notify_fail("你身上没有这样东西。\n");
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
		return notify_fail( stringp(no_drop) ? no_drop : "这样东西不能随意丢弃。\n");

	if (obj->move(environment(me)))
	{
		if( obj->is_character() )
			message_vision("$N将$n从背上放了下来，躺在地上。\n", me, obj);
		else if( (obj->query("material") == "glass")/* 玻璃 */
			|| (obj->query("material") == "porcelain") /* 瓷 */)
		{
			message_vision(sprintf("$N丢下一%s$n，$n掉在地上摔碎了。\n",obj->query("unit")),me,obj);
			destruct(obj);
		}

		else if( obj->query("disappear"))/* 丢掉就消失 by dicky */
		{
			message_vision(sprintf(HIB"$N丢下一%s$n，$n" HIB "掉在地上突然消失不见了。\n"NOR,obj->query("unit")),me,obj);
			destruct(obj);
		}

		else {
			message_vision( sprintf("$N丢下一%s$n。\n",	obj->query("unit")),
				me, obj );
			me->save();
			if( !obj->query("value") && !obj->value() ) {
				write("因为这样东西并不值钱，所以人们并不会注意到它的存在。\n");
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
指令格式 : drop <物品名称>
 
这个指令可以让你丢下你所携带的物品.
 
HELP
    );
    return 1;
}