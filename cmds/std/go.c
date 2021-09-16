// go.c
// Modified by Find.

#pragma optimize

#include <ansi.h>

inherit F_CLEAN_UP;

mapping default_dirs = ([
        "north":        "北",
        "south":        "南",
        "east":         "东",
        "west":         "西",
        "northup":      "北边",
        "southup":      "南边",
        "eastup":       "东边",
        "westup":       "西边",
        "northdown":    "北边",
        "southdown":    "南边",
        "eastdown":     "东边",
        "westdown":     "西边",
        "northeast":    "东北",
        "northwest":    "西北",
        "southeast":    "东南",
        "southwest":    "西南",
        "up":           "上",
        "down":         "下",
        "out":          "外",
]);

int check_flee(object me, string arg) 
{
	object *ob;
	int i, mydp, urdp=1, exp,npc=0;

	if(me->query("ride"))
		return 1;

	me->start_busy(1);

	exp = me->query("combat_exp");

	if((random(exp) < 300) && userp(me)) return 1;
	ob = me->query_enemy();

	for(i=0; i<sizeof(ob); i++) 
	{
		if(objectp(ob[i])&&(environment(ob[i]) == environment(me))
		&& living(ob[i])
		&& !ob[i]->is_busy())
		{
			if(npc<2)
				urdp+= COMBAT_D->skill_power(ob[i], "dodge", 3);
			else urdp+=random(COMBAT_D->skill_power(ob[i], "dodge", 3)/2);
			npc++;
		}
	}

	mydp = COMBAT_D->skill_power(me, "dodge", 3);
	if(mydp < 1) mydp = 1;

	if( (random((urdp + mydp)) > mydp) && (random(100) < 30) )
	{
		message_vision(sprintf(YEL"$N转身向%s逃去！\n"NOR,to_chinese(arg)), me);
		message_vision(RED "$N身影一晃，挡住了$n的去路！\n" NOR, ob[random(sizeof(ob))], me);
		return 0;
	}

        return 1;
}

int main(object me, string arg)
{
	int hide_go;
	mapping block, exit;
	object env, obj, blocker,ride;
	string mout, min, dir, blk;
	int altitude;	// added by Find for difference zone.
	int time,ride_level;
	mixed dest;

	// added by Find. for fuji.
	int i;
	object *fuji;
	// end.

	if(!arg) return notify_fail("你要往哪个方向走？\n");

	if(me->over_encumbranced())
		return notify_fail("你的负荷过重，动弹不得。\n");

	if(me->is_busy())
		return notify_fail("你现在忙得很，不能移动。\n");

	env = environment(me);
	if(!env) return notify_fail("你哪里也去不了。\n");
        if(me->query_temp("no_go")) return notify_fail("你现在不能离开。\n");

        hide_go = 0;
	if(!mapp(exit = env->query("exits")) || undefinedp(exit[arg])) 
	{
		if(mapp(exit = env->query("hide_exits")))
			hide_go = 1;
		if(!mapp(exit) || undefinedp(exit[arg]))
		{
			if(query_verb() == "go")
				return notify_fail("这个方向没有出路。\n");
			else
				return 0;
		}
	}

	if(mapp(block = env->query("blocks")) && blk = block[arg]) 
	{
		if(objectp(blocker = present(blk, env)) &&  living(blocker))   
			return notify_fail("这个方向的路被"+ blocker->name() + "挡住了。\n");
	}

	if(functionp(exit[arg]))
		dest = evaluate(exit[arg],me);
	else
		dest = exit[arg];

	if(objectp(dest))
		obj = dest;
	else
	{
		if(!(obj = find_object(dest)))
			call_other(dest, "???");
		if(!(obj = find_object(dest)))
			return notify_fail("无法移动。\n");
	}

#ifdef WIZARD_FLAG
	if(obj->query_wiz_flag() && (userp(me) && !wizardp(me)))
		return notify_fail(HIB"突然一个蓝色的精灵出现在眼前说道：“此方向通往天界福地，凡人不得入内。”\n"NOR);
#endif

	if(!userp(me) && obj->query("NONPC"))
		return 0;

	if(!env->valid_leave(me, arg)) return 0;

	if(!undefinedp(default_dirs[arg]))
		dir = default_dirs[arg];
	else
		dir = arg;

	// added by Find for difference zone.
	if( altitude = (int)env->query("altitude") )
	{
		int min_value,damage = 0;

		if( altitude < 100 )
			altitude = 100;
		if( altitude > 5000 )
			altitude = 5000;

		if(altitude <= 500) {
			damage = 1;min_value = 5;}
		else if( altitude <= 1000 ) {
			damage = 2;min_value = 10;}
		else if( altitude <= 2000 ) {
			damage = 3;min_value = 10;}
		else if( altitude <= 3000 ) {
			damage = 4;min_value = 12;}
		else if( altitude <= 4000 ){
			damage = 5;min_value = 20;}
		else if( altitude <= 5000 ){
			damage = 6;min_value = 20;}
		else {
			damage = 8;min_value = 20;}

		if( damage )
		{
			ride = me->query_temp("on_rided");

			if( (ride && (int)ride->query("kee") <= min_value )
			|| ( ride && (int)ride->query("sen") <= min_value) )
				return notify_fail("你骑的"+ride->name()+"已经累的走不动了。\n");
			if( ((int)me->query("kee") <= min_value)
			|| ((int)me->query("sen") <= min_value) )
				return notify_fail("你已经累的走不动了。\n");
			me->receive_damage("kee",((ride)? damage/2 : damage),"tire");
			me->receive_damage("sen",((ride)? damage/2 : damage),"tire");
			if(ride)
				ride->receive_damage("kee",damage);
		}
	}
	// end.

	// added by find.
	if(me->query_temp("on_rided")
	&& environment(me->query_temp("on_rided")) == environment(me)
	&& !me->is_fighting())
	{
		mout = "骑着" + (me->query_temp("on_rided"))->name()+ "往" + dir + "离开。\n";
		min = "骑着" + (me->query_temp("on_rided"))->name()+ "走了过来。\n";
	}
	// end.

	if(me->is_fighting())
	{
		if(me->is_busy())
			return notify_fail("\n你被对手挡住了身形，无法移动。\n");
		if(check_flee(me, dir) == 0) 
			return notify_fail("你被挡了回来。\n");
		if(me->query_temp("on_rided")
		&& environment(me->query_temp("on_rided")) == environment(me))
		{
			mout = "骑着" + (me->query_temp("on_rided"))->name()+ "往" + dir + "落荒而逃了。\n";
			min = "骑着" + (me->query_temp("on_rided"))->name() + "跌跌撞撞地跑了过来，模样有些狼狈。\n";
		}
		else
		{
			mout = "往" + dir + "落荒而逃了。\n";
			min = "跌跌撞撞地跑了过来，模样有些狼狈。\n";
		}
	}

	else if(hide_go)
	{
		mout = "突然往边上一闪，便不见了。\n";
		min = "突然出现在你面前。\n";
	}

	else
	{
                // Let's add this messages here to make go and 
                // come more interesting...
		if(mout = me->query("leave_msg"))
			mout = "往" + dir + mout +" 。\n";
		else
			mout = "往" + dir + "离开。\n";

		if(min = me->query("arrive_msg"))
			min = min + " 。\n";
		else
			min = "走了过来。\n";
	}

	// added by find.
	if( me->query_temp("on_rided") && obj->query("NORIDE") )
	{
		if(obj->query("NORIDE") == 1)
			return notify_fail(obj->query("short")+"可不能骑着坐骑去呀。\n");
		else
			return notify_fail(obj->query("NORIDE")+"\n");
	}
	// end.

	// modified by find.
	if( !me->query("ride") || !me->query_temp("have_been_rided") )
	{
		message("vision", ((environment(me)->query_dark_level() > 0)?"一条人影":me->name()) + mout,
		environment(me),(!wizardp(me)|| !me->query("env/invisibility"))?({me})
		:filter_array( all_inventory(environment(me)), "filter_invisible", this_object(),me ) );
	}

        if(me->move(obj)) 
        {
		object lead;

                me->remove_all_enemy();

		if( !me->query("ride") || !me->query_temp("have_been_rided") ) //added by find.
		{
		message("vision", ((environment(me)->query_dark_level() > 0)?"一条人影":me->name()) + min,
 		environment(me),(!wizardp(me)|| !me->query("env/invisibility"))?({me})
		:filter_array( all_inventory(environment(me)), "filter_invisible", this_object(),me ) );
		}
	// end.

		me->set_temp("pending", 0);
		all_inventory(env)->follow_me(me, arg);

		me->test_array();
		me->check_team();

		if(userp(me)
		&& objectp(lead = me->query_leader())
		&& (environment(lead) != environment(me)) )
			me->set_leader(0);

		if(!userp(me))
			me->set_temp("last_go_direction",arg);

		// added by Find. for fuji.
		if(userp(me))
		{
			if((fuji = environment(me)->query("fuji/"+
			me->query("id"))) && arrayp(fuji))
			{
				if(arrayp(fuji))
				{
					for(i=0;i<sizeof(fuji);i++)
					{
						if(fuji[i]
						&& environment(fuji[i]) == environment(me)
						&& fuji[i]->query_temp("fuji_player") == me->query("id"))
						{
							"/cmds/usr/unfuji"->main(fuji[i]);
							message_vision("$N冲$n大喊一声：可让我等到你了！\n",fuji[i],me);
							me->start_busy(1);
							fuji[i]->kill_ob(me);
							me->kill_ob(fuji[i]);
							me->accept_first_kill(fuji[i]);
						}
					}
				}
			}
		}
		// end.

		if(objectp(ride = me->query_temp("on_rided")) && userp(me))
		{
			time = (int)me->query_temp("ride_time");
			me->add_temp("ride_pass",1);
			// 骑着坐骑走路超过50个房间，每2分钟可以提高一些骑术。
			if((time() - time >= 120) && (me->query_temp("ride_pass") >= 50))
			{
				ride_level = ride->query("ride_level");
				if(ride_level > 10)
					ride_level = 10;
				if(ride_level < 1)
					ride_level = 1;
				me->set_temp("ride_time",time());
				me->set_temp("ride_pass",0);
				me->improve_skill("riding",ride_level);
			}
		}
                if( me->query_xuruo() )
                {
                        tell_object(me,"你虚弱的身体好像每迈出一步都要用出全身的力气。\n");
                        me->start_busy(1);
                }

		return 1;
	}
	return 0;
}

// by Find.
int filter_invisible(object ob,object user)
{
	if(ob == user)
		return 1;
	if( !userp(ob) )
		return 1;
	if( !ob->visible(user) )
		return 1;
	return 0;
}

void do_flee(object me)
{
        mapping exits;
        string *directions;

        if(!environment(me) || !living(me)) return;
        exits = environment(me)->query("exits");
        if(!mapp(exits) || !sizeof(exits)) return;
        directions = keys(exits);
        tell_object(me, "看来该找机会逃跑了...\n");
        main(me, directions[random(sizeof(directions))]);
}

int help(object me)
{
        write(@HELP
指令格式 : go <方向>
 
让你往指定的方向走。
 
HELP
    );
    return 1;
}
