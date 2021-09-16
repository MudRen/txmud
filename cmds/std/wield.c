// wield.c
// Modified by Find.

#include <weapon.h>

inherit F_CLEAN_UP;

protected int do_wield(object me, object ob,int flag);

int main(object me, string arg)
{
        object ob;
        int flag = 0, left,right;

        if( !arg ) return notify_fail("你要装备什么武器？\n");

	if(sscanf(arg,"-l %s",arg))
		flag = 1;

        if( !objectp(ob = present(arg, me)) )
                return notify_fail("你身上没有这样东西。\n");

	if(flag) /* 将兵器指定装备与左手的预判断。*/
	{
		if(!(ob->query("flag") & SECONDARY))
			return notify_fail(ob->name()+"不能装备在左手。\n");
		if(me->query_temp("secondary_weapon"))
			return notify_fail("你的左手已经装备了其它兵器。\n");
	}

        if( ob->query("equipped") )
                return notify_fail("你已经装备"+ob->name()+"了。\n");

	if( (left = me->query_limb_wound("左手"))
	&& (right = me->query_limb_wound("右手")) )
		return notify_fail("你的双手都受了重伤，没法拿兵器了。\n");
	if(flag && left)
		return notify_fail("你的左手受了重伤，现在没法拿兵器了。\n");
	if( !flag && me->query_limb_wound("右手") )
		return notify_fail("你的右手受了重伤，现在没法拿兵器了。\n");
	if((ob->query("flag") & TWO_HANDED) && me->query_limb_wound("左手"))
		return notify_fail("你的左手受了重伤，现在没法拿兵器了。\n");

	if(do_wield(me, ob, flag))
	{
		if(me->is_fighting())
			me->start_busy(1);
		return 1;
	}
	else
		return 0;
}

protected int do_wield(object me, object ob, int flag)
{
        string str;
        string *item;
        mapping add_ability;
        int i;

#ifdef WIZARD_FLAG
	if(ob->query_wiz_flag() && userp(me) && !wizardp(me))
		return notify_fail(ob->name()+"是巫师物品，你不能装备。\n");
#endif

        if(mapp(add_ability = ob->query("wield_skill")))
        {
        item = keys(add_ability);
        for(i = 0; i<sizeof(item);i++)
                {
                if(!me->query_skill(item[i],1)
                   || me->query_skill(item[i],1) < (int)add_ability[item[i]])
			return notify_fail("你的"+to_chinese(item[i])+"还没学好，不能驾驭"+ob->name()+"。\n");
                }
        }

        if(mapp(add_ability = ob->query("wield_ability")))
        {
		item = keys(add_ability);
		for(i = 0; i<sizeof(item);i++)
                {
			if(!me->query(item[i])
			|| me->query(item[i]) < (int)add_ability[item[i]] )
				return notify_fail("你目前的能力不足以驾驭"+ob->name()+"。\n");
		}
	}

        if( ob->wield(flag) ) /* If flag == 1,直接将兵器装备于左手. */
	{
                if( !stringp(str = ob->query("wield_msg")) )
                        str = "$N装备$n作武器。\n";
                message_vision(str, me, ob);
                return 1;
        }

	else
                return 0;
}

int help(object me)
{
        write(@HELP
指令格式：wield <装备名称>
          wield -l <装备名称>

这个指令让你装备某件物品作武器, 你必需要拥有这样物品.
比较厉害的武器一般还需要你具备了某些能力才能装备。
如果使用了 '-l' 参数，将指定的兵器装备于左手，前提是
你左手是空的，并且兵器是双手都可使用的兵器。

HELP
    );
    return 1;
}
