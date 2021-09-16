// vote unchblk
// Modified by Find.

#include <vote.h> 
#include <ansi.h>
inherit F_CLEAN_UP;

//int clear_vote(object victim);
int vote(object me, object victim)
{
	int reason; // vote for what?
	int vv;     // valid voter numbers
	int vc;     // vote count;
	int df,n;
	string *juror, my_id;

	if(!previous_object() || geteuid(previous_object()) != ROOT_UID)
		return 0;

	if((reason = (int)victim->query("vote/reason"))>0 && (reason!=V_UNCHBLK))
		return notify_fail("要把当前的表决完成以后才可以提新的动议。\n");

	if(!victim->query("chblk_on"))
		return notify_fail(victim->name()+"的频道已经是打开的了。\n");

	vv = (int)("/cmds/std/vote")->valid_voters(me);

	if(vv < 5)
		return notify_fail("由于合格投票人数少于法定最小人数五人，此动议无效。\n");

	if( (vv /= 5) < 5 )
		vv = 5;

	victim->set("vote/reason", (int)V_UNCHBLK); 
	my_id = me->query("id");

	// dont allow me to vote twice for the same issue
	juror = victim->query("vote/juror");

	if( !pointerp(juror) )
	{
		victim->set("vote/juror", ({ my_id }) );
		victim->set("vote/time",time());
	}
	else if( member_array(my_id, juror) == -1 )
	{
		for(int i=0;i<n;i++)
		{
			object who = find_player(juror[i]);

			if(!who)
				juror[i] = 0;
			else if(query_ip_number(who) == query_ip_number(me))
				return notify_fail("你的 IP 地址已经有人投过票了。\n");
		}
		juror -= ({ 0 });
		juror += ({ my_id });
		victim->set("vote/juror",juror );
	}

	else
	{
		me->add("abuse", 10);
		return notify_fail("一人一票！滥用表决权是要受惩罚的！\n");
	}

	vc = sizeof(victim->query("vote/juror"));
	df = vv - vc;

	if (df>1)
	{
		shout( sprintf(HIG"【表决】%s 投票打开 %s 的交谈频道，共需 %d 票，还差 %d 票。\n" NOR,
			me->name(),victim->name(),vv,df));
		write( sprintf(HIG"【表决】你投票打开 %s 的交谈频道，还差 %d 票。\n" NOR,
			victim->name(),df));
	}

	else 
	{
		shout(sprintf(HIG "【表决】%s 投票打开 %s 的交谈频道。%s 的交谈频道被打开了！\n" NOR,
			me->name(),victim->name(),victim->name()));
		write( sprintf(HIG "【表决】你投票打开 %s 的交谈频道。%s 的交谈频道被打开了！\n" NOR,
			victim->name(),victim->name()));

		victim->delete("chblk_on");
		victim->delete("vote");
	} 

	return 1;
}
