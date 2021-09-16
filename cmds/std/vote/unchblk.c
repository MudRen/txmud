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
		return notify_fail("Ҫ�ѵ�ǰ�ı������Ժ�ſ������µĶ��顣\n");

	if(!victim->query("chblk_on"))
		return notify_fail(victim->name()+"��Ƶ���Ѿ��Ǵ򿪵��ˡ�\n");

	vv = (int)("/cmds/std/vote")->valid_voters(me);

	if(vv < 5)
		return notify_fail("���ںϸ�ͶƱ�������ڷ�����С�������ˣ��˶�����Ч��\n");

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
				return notify_fail("��� IP ��ַ�Ѿ�����Ͷ��Ʊ�ˡ�\n");
		}
		juror -= ({ 0 });
		juror += ({ my_id });
		victim->set("vote/juror",juror );
	}

	else
	{
		me->add("abuse", 10);
		return notify_fail("һ��һƱ�����ñ��Ȩ��Ҫ�ܳͷ��ģ�\n");
	}

	vc = sizeof(victim->query("vote/juror"));
	df = vv - vc;

	if (df>1)
	{
		shout( sprintf(HIG"�������%s ͶƱ�� %s �Ľ�̸Ƶ�������� %d Ʊ������ %d Ʊ��\n" NOR,
			me->name(),victim->name(),vv,df));
		write( sprintf(HIG"���������ͶƱ�� %s �Ľ�̸Ƶ�������� %d Ʊ��\n" NOR,
			victim->name(),df));
	}

	else 
	{
		shout(sprintf(HIG "�������%s ͶƱ�� %s �Ľ�̸Ƶ����%s �Ľ�̸Ƶ�������ˣ�\n" NOR,
			me->name(),victim->name(),victim->name()));
		write( sprintf(HIG "���������ͶƱ�� %s �Ľ�̸Ƶ����%s �Ľ�̸Ƶ�������ˣ�\n" NOR,
			victim->name(),victim->name()));

		victim->delete("chblk_on");
		victim->delete("vote");
	} 

	return 1;
}
