// give.c
// Modified by Find.

inherit F_CLEAN_UP;

int do_give(object me, object obj, object who);

int main(object me, string arg)
{
	string target, item;
	object obj, who, *inv, obj2;
	int i, amount;

	if(!arg) return notify_fail("你要给谁什么东西？\n");

	if( sscanf(arg, "%s to %s", item, target)==2
	|| sscanf(arg, "%s %s", target, item)==2 );
	else return notify_fail("你要给谁什么东西？\n");

	if(!objectp(who = present(target, environment(me))) || !living(who))
		return notify_fail("这里没有这个人。\n");
        if( who->query("env/no_accept") && userp(me) )
                return notify_fail(who->name()+"现在不想接受任何人的东西。\n");

        if(item=="all")
	{
		int flag;
                inv = all_inventory(me);
                for(i=0; i<sizeof(inv); i++)
		{
			if(do_give(me, inv[i], who))
				flag++;
                }
		if(!flag)
			return notify_fail("你身上没有什么可以给人的东西。\n");
		if(me->is_fighting())
			me->start_busy(flag>1?2:1);
                write("Ok.\n");
                return 1;
        }


	if(sscanf(item, "%d %s", amount, item)==2) {
		if( !objectp(obj = present(item, me)) )	
			return notify_fail("你身上没有这样东西。\n");
		if( obj->query("no_drop") && (!wizardp(me)) )
			return notify_fail("这样东西不能随便给人。\n");
		if( !obj->query_amount() )	
			return notify_fail( obj->name() + "不能被分开给人。\n");
		if( amount < 1 )
			return notify_fail("东西的数量至少是一个。\n");
		if( amount > obj->query_amount() ) 
			return notify_fail("你没有那么多的" + obj->name() + "。\n");
#ifdef WIZARD_FLAG
		if(obj->query_wiz_flag() && userp(who) && !wizardp(who))
			return notify_fail("巫师物品不能交与玩家使用。\n");
#endif
		else if( amount == (int)obj->query_amount() )
			return do_give(me, obj, who);
		else {
			obj2 = new(base_name(obj));
			obj2->set_amount(amount);
#ifdef WIZARD_FLAG
			if(obj->query_wiz_flag())
				obj2->set_flag(1);
#endif
                        if(do_give(me, obj2, who))
			{
                                obj->set_amount( (int)obj->query_amount() - amount );
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

	if(!objectp(obj = present(item, me)))
		return notify_fail("你身上没有这样东西。\n");
	if(do_give(me, obj, who))
	{
		if(me->is_fighting())
			me->start_busy(1);
		return 1;
	}
	else
		return 0;
}

int do_give(object me, object obj, object who)
{
        mixed no_give;
	object *obs;

        if(who == me)   return notify_fail("这就是你自己的东西不用给了。\n");

        if( no_give = obj->query("no_give") )
                return notify_fail( stringp(no_give) ? no_give : "这样东西不能随便给人。\n");

        else if( obj->query("no_drop") )
                return notify_fail("这样东西不能随便给人。\n");

	if(obj->is_container())
	{
		obs = filter_array(deep_inventory(obj),(: $1->query("no_give") || $1->query("no_drop") :));
		if(sizeof(obs))
			return notify_fail("这样东西不能随便给人。\n");
	}

#ifdef WIZARD_FLAG
	if(obj->query_wiz_flag() && userp(who) && !wizardp(who))
		return notify_fail("巫师物品不能交与玩家使用。\n");
#endif

	notify_fail(sprintf("看起来对方并不想接受你给%s的%s。\n",
		who->query("gender")=="女性"?"她":"他",obj->name())); // by Find.
	if( !userp(who) && !who->accept_object(me, obj) )
		return 0;

	if( !userp(who) && obj->value() ) {
		message_vision("$N拿出" + obj->short() + "给$n。\n", me, who);
		destruct(obj);
		return 1;
	} else if( obj->move(who) ) {
		printf("你给%s一%s%s。\n", who->name(), obj->query("unit"),
			obj->name());
		message("vision", sprintf("%s给你一%s%s。\n", me->name(),
			obj->query("unit"), obj->name()), who );
		message("vision", sprintf("%s给%s一%s%s。\n", me->name(), who->name(),
			obj->query("unit"), obj->name()), environment(me), ({me, who}) );
		me->save();
		return 1;
	}
	else return 0;
}
int help(object me)
{
write(@HELP
指令格式 : give <物品名称> to <某人>
      或 : give <某人> <物品名称>
 
这个指令可以让你将某样物品给别人, 当然, 首先你要拥有这样物品.
 
HELP
    );
    return 1;
}
