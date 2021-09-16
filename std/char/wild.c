// wild.c

#include <ansi.h>

inherit NPC;

private object master;
private string id,*fail_msg = ({
"$N不耐烦的蹬了蹬蹄子。\n",
"$N把头扭到了一边，屁股对着$n。\n",
"$N张开嘴朝$n呲了呲牙。\n",
});
private int flag = 0,count;

nomask int is_wild() { return 1; }
nomask object query_master() { return master; }

nomask void been_xunhua(object me,int skill)
{
	if(!objectp(me))
		return;

	if(objectp(master) && me == master)
	{
		tell_object(me,sprintf("%s%s已经被你驯化了。\n",this_object()->name(),NOR));
		me->stop_busy();
		return;
	}

	call_out("do_result",1,me,skill);
}

private void do_result(object me,int skill)
{
	int n,level;

	if(!me || !living(this_object()))
		return;

	level = this_object()->query("ride_level");

	if(!level)
		level = 2;

	if(skill < 90)
		n = 25;
	else if(skill < 130)
		n = 30;
	else if(skill < 160)
		n = 35;
	else if(skill < 190)
		n = 40;
	else
		n = 45;

	if(level >= 9)
		n -= 25;
	else if(level >= 6)
		n -= 15;
	else if(level >= 3)
		n -= 5;

	if(n < 5)
		n = 5;

	if(random(110) < n) // 成功
	{
		if(id == me->query("id"))
			count++;
		else
		{
			id = me->query("id");
			count = 1;
		}

		if(count >= 3)
		{
			message_vision(HIC"$N亲热的走到$n身边拿嘴拱了拱$n的肚子。\n"NOR,this_object(),me,me);
			if(!flag)
			{
				this_object()->add("long","但是现在已经被人驯服了。\n");
				flag = 1;
			}
			this_object()->remove_killer(me);
			me->remove_killer(this_object());
			master = me;
		}

		else
			tell_object(me,sprintf("%s拿眼睛看了看你，态度好像和缓了一些。\n",this_object()->name()));
		return;
	}

	if( random(100) < 15 )
	{
		message_vision("$N“嗷”的一嗓子朝着$n冲了过去。\n",this_object(),me);
		this_object()->kill_ob(me);
		me->fight_ob(this_object());
		return;
	}

	else
		message_vision(fail_msg[random(sizeof(fail_msg))],this_object(),me);
}

nomask int random_move()
{
	if(objectp(this_object()->query_temp("have_been_rided")))
		return 0;
	else
		return npc::random_move();
}
