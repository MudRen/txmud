// kill.c
// Modified by Find.

#include <ansi.h>
inherit F_CLEAN_UP;

int main(object me, string arg)
{
	object obj;
	string callname;
	object *guards,ride;
	int i,num;
	mapping ey;

	if(environment(me)->query(SAFE_ENV))
		return notify_fail("这里不准战斗。\n");
	if( !arg )
		return notify_fail("你想杀谁？\n");
	if(!objectp(obj = present(arg, environment(me))))
		return notify_fail("这里没有这个人。\n");
	if( !obj->is_character() || obj->is_corpse() )
		return notify_fail("看清楚一点，那并不是活物。\n");

	if(obj==me)
		return notify_fail("用 suicide 指令会比较快 :P。\n");

	if( userp(obj) )
	{
		if(userp(me) && (me->query("age") <= PROTECT_AGE))
			return notify_fail("这么小的岁数就想杀人？还是算了吧。\n");
		if( obj->query("age") <= PROTECT_AGE )
			return notify_fail("这么小的孩子你也杀呀？还是放他一条生路吧。\n");
	}

	if(mapp(ey = me->query("enyi_class"))
	&& sizeof(ey)
	&& (geteuid(obj) != ey["id"]) )
		return notify_fail("你正肩负着仁义庄的重托，没时间做别的事情呢。\n");

	if(me->is_busy())
		return notify_fail(BUSY_MESSAGE);

        if(obj->query_temp("netdead"))
                return notify_fail("这小子断线啦，等他回来再说吧。\n");

	if(obj->query_temp("boss_behind"))
		return notify_fail(gender_pronoun(obj->query("gender"))+"的老板在"+
		gender_pronoun(obj->query("gender"))+"身边呢，等一会儿再和"+
		gender_pronoun(obj->query("gender"))+"拼命吧。\n"); // by Find.

	if(in_edit(obj) || in_input(obj) || obj->query_temp("netdead"))
		return notify_fail ("等他醒过来再砍吧.\n");

	if(obj->query(NO_KILL) || obj->is_master())
		return notify_fail("这家伙你不能动就是不能动。\n");

	if( ride = obj->query_temp("have_been_rided"))
	{
		if(ride == me)
			return notify_fail("连自己的坐骑都要杀？不是穷的吃不上饭了吧？\n");
	}

	if( !userp(obj) && !obj->accept_kill(me))
		return 0;

	callname = RANK_D->query_rude(obj);
	message_vision("\n$N对著$n喝道：「" + callname + "！今日不是你死就是我活！」\n\n", me, obj);

	me->kill_ob(obj);

/*
	if(userp(me)	// 对npc下 kill 命令会被追着杀.
	&& !userp(obj)
	&& obj->query("race") == "人类"
	&& !obj->is_master())
		obj->set_leader(me);
*/

	if(objectp(ride) && !userp(ride))
	{			
		message_vision("$N朝$n大喊：“敢动我的坐骑，不想活啦！！”\n",ride,me);
		ride->kill_ob(me);
                me->fight_ob(ride);
		ride->accept_first_kill(me);
	}

        if( arrayp(obj->query_temp("guarded")) )
        {
                num = sizeof(guards);
                if(num > 4)
                        num = 4;

                for(i=0;i<num;i++)
                {
                        if( guards[i]
                        && living(guards[i])
                        && (environment(guards[i]) == environment(obj)) )
                        {
                        if(guards[i]->query("gender") == "男性")
                                message_vision( "$N对$n喊道："+( (obj->query("can_speak")) ?
                                                "敢欺负人！太不把老子放在眼里了！\n\n" :
                                                "打狗还要看主人，老子的东西也敢动！\n\n")
                                                ,guards[i],me);
                        else
                                message_vision( "$N对$n喊道："+( (obj->query("can_speak")) ?
                                                "敢欺负人！太不把老娘放在眼里了！\n\n" :
                                                "打狗还要看主人，老娘的东西也敢动！\n\n")
                                                ,guards[i],me);
                        me->kill_ob(guards[i]);
                        guards[i]->kill_ob(me);
			me->accept_first_kill(guards[i]);
                        }
                }
        }

	if(me->in_team())
	{
		object *all = me->query_team_member();

		all -= ({me});

		foreach(object ttt in all)
		{
			ttt->kill_ob(obj);
			obj->kill_ob(ttt);
		}
	}

	obj->kill_ob(me);
	if(userp(me) && userp(obj))
		obj->accept_first_kill(me);
	return 1;
}

int help(object me)
{
  write(@HELP
指令格式 : kill <人物>
 
这个指令让你主动开始攻击一个人物，并且□试杀死对方，kill 和 fight 最大的
不同在於双方将会真刀实枪地打斗，也就是说，会真的受伤。由於 kill 只需单方
面一厢情愿就可以成立，因此你对任何人使用 kill 指令都会开始战斗，通常如果
对方是 NPC 的话，他们也会同样对你使用 kill。

当有人对你使用 kill 指令时会出现红色的字样警告你，对於一个玩家而言，如果
你没有对一名敌人使用过 kill 指令，就不会将对方真的打伤或杀死( 使用法术除
外)。

其他相关指令: fight

有关 fight 跟 kill 的区分请看 'help combat'.
HELP
    );
    return 1;
}
