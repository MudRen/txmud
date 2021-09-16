// wild.c

#include <ansi.h>

inherit NPC;

private object master;
private string id,*fail_msg = ({
"$N���ͷ��ĵ��˵����ӡ�\n",
"$N��ͷŤ����һ�ߣ�ƨ�ɶ���$n��\n",
"$N�ſ��쳯$n����������\n",
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
		tell_object(me,sprintf("%s%s�Ѿ�����ѱ���ˡ�\n",this_object()->name(),NOR));
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

	if(random(110) < n) // �ɹ�
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
			message_vision(HIC"$N���ȵ��ߵ�$n������칰�˹�$n�Ķ��ӡ�\n"NOR,this_object(),me,me);
			if(!flag)
			{
				this_object()->add("long","���������Ѿ�����ѱ���ˡ�\n");
				flag = 1;
			}
			this_object()->remove_killer(me);
			me->remove_killer(this_object());
			master = me;
		}

		else
			tell_object(me,sprintf("%s���۾����˿��㣬̬�Ⱥ���ͻ���һЩ��\n",this_object()->name()));
		return;
	}

	if( random(100) < 15 )
	{
		message_vision("$N��໡���һɤ�ӳ���$n���˹�ȥ��\n",this_object(),me);
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
