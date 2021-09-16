// ride.c
// by Find

#include <ansi.h>
inherit F_CLEAN_UP;

int do_ride(object me, object ob);

int main(object me, string arg)
{
	object ob;

	if( !arg ) return notify_fail("��Ҫ��ʲô��\n");
	if( !objectp(ob = present(arg, environment(me))) )
		return notify_fail("��Ҫ��ʲô��\n");
	if( me->query_temp("on_rided") )
		return notify_fail("���Ѿ�����"+(me->query_temp("on_rided"))->name()+"���ˡ�\n");
	if( !ob->query("ride") )
		return notify_fail("�ǲ�������㲻���\n");
	if(me->is_fighting())
		return notify_fail("������ս����û��ʱ�������\n");
	if(ob->is_fighting())
		return notify_fail(ob->name()+"����ս���У�������û��������\n");
	if( !living(ob) )
		return notify_fail(ob->name()+"�Ѿ��ε��ڵأ����ڲ���������\n");

	return do_ride(me, ob);
}

int do_ride(object me, object ob)
{
	string str;
	int ride_level,skill,ride_dodge;

	if(ob->query_temp("have_been_rided"))
		return notify_fail(ob->name()+"������"+
		(string)((ob->query_temp("have_been_rided"))->name())+"��\n");

	if(ob->is_wild() && (ob->query_master() != me))
		return notify_fail(sprintf("%sŤ��Ť���ӣ�����˦��������\n",ob->name()));

#ifdef WIZARD_FLAG
	if(ob->query_wiz_flag() && !wizardp(me))
		return notify_fail("������ʦ�ǵ������㲻���\n");
#endif

	ride_level = ob->query("ride_level");	// ����ĵȼ�
	skill = me->query_skill("riding",1);	// �����ȼ�

	if(ride_level > 10)
		ride_level = 10;
	if(ride_level < 1)
		ride_level = 1;

	me->start_busy(1);

	if(ride_level > 2 && ride_level <= 5 )	// 3 ������
	{
		if(skill < 20)	// ��Ҫ20�����ϵ�����
		{
			message_vision("$N����������$n�ı��ϡ�\n$nһ˦�����ְ�$N����������\n",me,ob);
			return notify_fail("�������������������������\n");
		}
	}

	if(ride_level > 5 && ride_level <= 8 )	// 2 ������
	{
		if(skill < 100)	// ��Ҫ100�����ϵ�����
		{
			message_vision("$N����Ծ��$n��\n$nһ��������һ˦�����ְ�$N����������\n",me,ob);
			return notify_fail("�������������������������\n");
		}
	}

	if(ride_level > 8 )	// 1 ������
	{
		if(skill < 150)	// ��Ҫ150�����ϵ�����
		{
			message_vision("$N����Ծ��$n��\n$nһ˦�����ְ�$N����������\n",me,ob);
			return notify_fail("�������������������������\n");
		}
	}

	me->set_temp("on_rided", ob);

	ob->set_leader(me);
	ob->set_temp("have_been_rided",me);

	if( !stringp(str = ob->query("ride_msg")) )
		str = "$N����һԾ������$n��\n";
	else if(strsrch(str,"\n") == -1)
		str += "\n";
	message_vision(str, me, ob);

	// �˴�Ϊ��������������������ֵ�ļ��㹫ʽ.
	ride_dodge = ride_level*skill/40;

	if(ride_dodge < 1 )
		ride_dodge = 1;

	me->add_temp("apply/dodge", ride_dodge);
	me->set_temp("add/dodge",ride_dodge);
	me->set_temp("ride_time",time());
	return 1;
}

int help(object me)
{
        write(@HELP
ָ���ʽ��ride <Ҫ���ϵ���������>
 
���ָ�������������ĳͷ������, �������������ͬһ�����С�
 
HELP
    );
    return 1;
}