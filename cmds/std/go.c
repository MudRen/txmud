// go.c
// Modified by Find.

#pragma optimize

#include <ansi.h>

inherit F_CLEAN_UP;

mapping default_dirs = ([
        "north":        "��",
        "south":        "��",
        "east":         "��",
        "west":         "��",
        "northup":      "����",
        "southup":      "�ϱ�",
        "eastup":       "����",
        "westup":       "����",
        "northdown":    "����",
        "southdown":    "�ϱ�",
        "eastdown":     "����",
        "westdown":     "����",
        "northeast":    "����",
        "northwest":    "����",
        "southeast":    "����",
        "southwest":    "����",
        "up":           "��",
        "down":         "��",
        "out":          "��",
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
		message_vision(sprintf(YEL"$Nת����%s��ȥ��\n"NOR,to_chinese(arg)), me);
		message_vision(RED "$N��Ӱһ�Σ���ס��$n��ȥ·��\n" NOR, ob[random(sizeof(ob))], me);
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

	if(!arg) return notify_fail("��Ҫ���ĸ������ߣ�\n");

	if(me->over_encumbranced())
		return notify_fail("��ĸ��ɹ��أ��������á�\n");

	if(me->is_busy())
		return notify_fail("������æ�úܣ������ƶ���\n");

	env = environment(me);
	if(!env) return notify_fail("������Ҳȥ���ˡ�\n");
        if(me->query_temp("no_go")) return notify_fail("�����ڲ����뿪��\n");

        hide_go = 0;
	if(!mapp(exit = env->query("exits")) || undefinedp(exit[arg])) 
	{
		if(mapp(exit = env->query("hide_exits")))
			hide_go = 1;
		if(!mapp(exit) || undefinedp(exit[arg]))
		{
			if(query_verb() == "go")
				return notify_fail("�������û�г�·��\n");
			else
				return 0;
		}
	}

	if(mapp(block = env->query("blocks")) && blk = block[arg]) 
	{
		if(objectp(blocker = present(blk, env)) &&  living(blocker))   
			return notify_fail("��������·��"+ blocker->name() + "��ס�ˡ�\n");
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
			return notify_fail("�޷��ƶ���\n");
	}

#ifdef WIZARD_FLAG
	if(obj->query_wiz_flag() && (userp(me) && !wizardp(me)))
		return notify_fail(HIB"ͻȻһ����ɫ�ľ����������ǰ˵�������˷���ͨ����縣�أ����˲������ڡ���\n"NOR);
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
				return notify_fail("�����"+ride->name()+"�Ѿ��۵��߲����ˡ�\n");
			if( ((int)me->query("kee") <= min_value)
			|| ((int)me->query("sen") <= min_value) )
				return notify_fail("���Ѿ��۵��߲����ˡ�\n");
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
		mout = "����" + (me->query_temp("on_rided"))->name()+ "��" + dir + "�뿪��\n";
		min = "����" + (me->query_temp("on_rided"))->name()+ "���˹�����\n";
	}
	// end.

	if(me->is_fighting())
	{
		if(me->is_busy())
			return notify_fail("\n�㱻���ֵ�ס�����Σ��޷��ƶ���\n");
		if(check_flee(me, dir) == 0) 
			return notify_fail("�㱻���˻�����\n");
		if(me->query_temp("on_rided")
		&& environment(me->query_temp("on_rided")) == environment(me))
		{
			mout = "����" + (me->query_temp("on_rided"))->name()+ "��" + dir + "��Ķ����ˡ�\n";
			min = "����" + (me->query_temp("on_rided"))->name() + "����ײײ�����˹�����ģ����Щ�Ǳ���\n";
		}
		else
		{
			mout = "��" + dir + "��Ķ����ˡ�\n";
			min = "����ײײ�����˹�����ģ����Щ�Ǳ���\n";
		}
	}

	else if(hide_go)
	{
		mout = "ͻȻ������һ�����㲻���ˡ�\n";
		min = "ͻȻ����������ǰ��\n";
	}

	else
	{
                // Let's add this messages here to make go and 
                // come more interesting...
		if(mout = me->query("leave_msg"))
			mout = "��" + dir + mout +" ��\n";
		else
			mout = "��" + dir + "�뿪��\n";

		if(min = me->query("arrive_msg"))
			min = min + " ��\n";
		else
			min = "���˹�����\n";
	}

	// added by find.
	if( me->query_temp("on_rided") && obj->query("NORIDE") )
	{
		if(obj->query("NORIDE") == 1)
			return notify_fail(obj->query("short")+"�ɲ�����������ȥѽ��\n");
		else
			return notify_fail(obj->query("NORIDE")+"\n");
	}
	// end.

	// modified by find.
	if( !me->query("ride") || !me->query_temp("have_been_rided") )
	{
		message("vision", ((environment(me)->query_dark_level() > 0)?"һ����Ӱ":me->name()) + mout,
		environment(me),(!wizardp(me)|| !me->query("env/invisibility"))?({me})
		:filter_array( all_inventory(environment(me)), "filter_invisible", this_object(),me ) );
	}

        if(me->move(obj)) 
        {
		object lead;

                me->remove_all_enemy();

		if( !me->query("ride") || !me->query_temp("have_been_rided") ) //added by find.
		{
		message("vision", ((environment(me)->query_dark_level() > 0)?"һ����Ӱ":me->name()) + min,
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
							message_vision("$N��$n��һ���������ҵȵ����ˣ�\n",fuji[i],me);
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
			// ����������·����50�����䣬ÿ2���ӿ������һЩ������
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
                        tell_object(me,"���������������ÿ����һ����Ҫ�ó�ȫ���������\n");
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
        tell_object(me, "�������һ���������...\n");
        main(me, directions[random(sizeof(directions))]);
}

int help(object me)
{
        write(@HELP
ָ���ʽ : go <����>
 
������ָ���ķ����ߡ�
 
HELP
    );
    return 1;
}
