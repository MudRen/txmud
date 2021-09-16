// wear.c
// Modified by Find.

#include <ansi.h>

inherit F_CLEAN_UP;

int do_wear(object me, object ob);

int main(object me, string arg)
{
	object ob, *inv;
	int i, count;

	if( !arg ) return notify_fail("你要穿戴什么？\n");

	if(arg=="all") {
		inv = all_inventory(me);
		for(count=0, i=0; i<sizeof(inv); i++) {
			if( inv[i]->query("equipped") ) continue;
			if(do_wear(me, inv[i]) ) count ++;
		}
		if(!count)
			return notify_fail("你没有什么可以穿戴的东西。\n");
		if(me->is_fighting())
			me->start_busy(1);
		write("Ok.\n");
		return 1;
	}

	if( !objectp(ob = present(arg, me)) )
		return notify_fail("你身上没有这样东西。\n");

	if( ob->query("equipped") )
		return notify_fail("你已经装备着了。\n");

	if(do_wear(me, ob))
	{
		if(me->is_fighting())
			me->start_busy(1);
		return 1;
	}
	else
		return 0;
}

int do_wear(object me, object ob)
{
	string str;
	string *item;
	mapping add_ability;
	int i;

#ifdef WIZARD_FLAG
	if(ob->query_wiz_flag() && userp(me) && !wizardp(me))
		return notify_fail(ob->name()+"是巫师物品，你不能装备。\n");
#endif

	if( ob->query("female_only")
	&& (string)me->query("gender") != "女性" )
		return notify_fail("这是女人穿用的东西，你一个大男人穿上恐怕不合适吧？\n");

        if(mapp(add_ability = ob->query("wear_skill")))
        {
        item = keys(add_ability);
        for(i = 0; i<sizeof(item);i++)
                {
                if(!me->query_skill(item[i],1)
                   || me->query_skill(item[i],1) < (int)add_ability[item[i]])
			return notify_fail("你的"+to_chinese(item[i])+"还没学好，无法装备"+ob->name()+"。\n");
                }
        }

        if(mapp(add_ability = ob->query("wear_ability")))
        {
		item = keys(add_ability);
		for(i = 0; i<sizeof(item);i++)
                {
			if(!me->query(item[i])
			|| me->query(item[i]) < (int)add_ability[item[i]] )
				return notify_fail("你目前的能力不足无法装备"+ob->name()+"。\n");
		}
	}

	if( ob->wear() )
	{
		if( !stringp(str = ob->query("wear_msg")) )
			switch( ob->query("armor_type") ) {
				case "cloth":
				case "armor":
				case "boots":
					str = YEL "$N穿上一" + ob->query("unit") + "$n。\n" NOR;
					break;
				case "head":
				case "neck":
				case "wrists":
				case "finger":
				case "hands":
					str = YEL "$N戴上一" + ob->query("unit") + "$n。\n" NOR;
					break;
				case "waist":
					str = YEL "$N将一" + ob->query("unit") + "$n绑在腰间。\n" NOR;
					break;
				default:
					str = YEL "$N装备$n。\n" NOR;
			}
		message_vision(str, me, ob);
		return 1;
	} else
		return 0;
}

int help(object me)
{
	write(@HELP
指令格式：wear <装备名称>
 
这个指令让你装备某件防具。
 
HELP
    );
    return 1;
}
