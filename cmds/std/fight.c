// fight.c

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	object obj, old_target,ride;

	seteuid(getuid());

	if( !wizardp(me) && environment(me)->query(SAFE_ENV) )
		return notify_fail("这里禁止战斗。\n");

	if(!arg || !objectp(obj = present(arg, environment(me))))
		return notify_fail("你想攻击谁？\n");

	if( !obj->is_character() )
		return notify_fail("看清楚一点，那并不是生物。\n");

	if(obj->query(NO_KILL) || obj->is_master())
		return notify_fail("对方不接受你的挑战。\n");

        if(obj->query_temp("netdead"))
                return notify_fail("这小子断线啦，等他回来再说吧。\n");

	if(obj->query_temp("boss_behind"))
		return notify_fail(gender_pronoun(obj->query("gender"))+"的老板在"+
		gender_pronoun(obj->query("gender"))+"身边呢，等一会儿再和"+
		gender_pronoun(obj->query("gender"))+"较量吧。\n"); // by Find.

	if (in_edit(obj) || in_input(obj) || obj->query_temp("netdead"))
		return notify_fail ("等他醒过来再较量吧.\n");

	if( obj->is_fighting(me) )
		return notify_fail("加油！加油！加油！\n");

	if( !living(obj) )
		return notify_fail(obj->name() + "已经无法战斗了。\n"); 

	if(obj==me)	return notify_fail("你不能攻击自己。\n");

	if(me->query("kee") < me->query("max_kee")/3)
		return notify_fail("你现在体力不支，还是别动武的好。\n");

	// added by Find.
	if( ride = obj->query_temp("have_been_rided"))
	{
		if(ride == me)
			return notify_fail(sprintf("你正骑在%s上面怎么较量呀。\n",obj->name()));
		else
		return notify_fail(sprintf("%s扭了扭身子，把头转向了其他的地方。\n",obj->name()));
	}
	// end.

	if( userp(obj) && (object)obj->query_temp("pending/fight")!=me )
	{
		message_vision("\n$N对着$n说道：" 
			+ RANK_D->query_self(me) 
			+ me->name() + "，领教"
			+ RANK_D->query_respect(obj) + "的高招！\n\n", me, obj);
		if( objectp(old_target = me->query_temp("pending/fight")) )
			tell_object(old_target, YEL + me->name() + "取消了和你比试的念头。\n" NOR);
		me->set_temp("pending/fight", obj);
		tell_object(obj, YEL "如果你愿意和对方进行比试，请你也对" + me->name() + "("+(string)me->query("id")+")"+ "下一次 fight 指令。\n" NOR);
		write(YEL "由于对方是由玩家控制的人物，你必须等对方同意才能进行比试。\n" NOR);
		return 1;
	}

	if( obj->query("can_speak") )
	{
		message_vision("\n$N对着$n说道：" 
			+ RANK_D->query_self(me) 
			+ me->name() + "，领教"
			+ RANK_D->query_respect(obj) + "的高招！\n\n", me, obj);

		notify_fail("看起来" + obj->name() + "并不想跟你较量。\n");
		if( !userp(obj) && !obj->accept_fight(me) ) return 0;

		me->fight_ob(obj);
		obj->fight_ob(me);
	}

	else
	{
		message_vision("\n$N大喝一声，开始对$n发动攻击！\n\n", me, obj);
		me->fight_ob(obj);
		obj->kill_ob(me);
	}

	if(objectp(ride) && !userp(ride))
	{			
		message_vision("$N朝$n大喊：“敢打我坐骑的主意，不想活啦！！”\n",ride,me);
		ride->kill_ob(me);
		me->fight(ride);
	}

	return 1;
}
int help(object me)
{
  write(@HELP
指令格式 : fight <人物>
 
这个指令让你向一个人物「讨教」或者是「切磋武艺」，这种形式的战斗纯粹是
点到为止，因此只会消耗体力，不会真的受伤，但是并不是所有的  NPC 都喜欢
打架，因此有需多状况你的比武要求会被拒绝。
 
其他相关指令: kill

PS. 如果对方不愿意接受你的挑战，你仍然可以迳行用 kill 指令开始战斗，有
    关 fight 跟 kill 的区分请看 'help combat'.
HELP
    );
    return 1;
}
