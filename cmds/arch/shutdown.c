// shutdown.c
// by Find.

#include <ansi.h>
#include <net/daemons.h>

inherit F_CLEAN_UP;

int help(object);
protected int time, exit_code;
protected void do_shutdown();

int main(object me, string arg)
{
	int count;

	if( me != this_player(1) ) return 0;
	
	if(wiz_level(me) < wiz_level("(arch)"))
		return notify_fail("ֻ�� (arch) ���ϵ���ʦ������������" + MUD_NAME + "\n");

	if(!arg)
		return help(me);

	seteuid(getuid());

	if((sizeof(arg) > 2) && (arg[0..1] == "-n"))
		if(sscanf(arg, "-n%d %s", exit_code, arg) != 2)
			return help(me);

	if(arg == "stop")
	{
		if(!time)
			return notify_fail("��Ϸû�н�����������������̡�\n");
		time = 0;
		if(find_call_out("continue_shut"))
			remove_call_out("continue_shut");
		LOGIN_D->set_no_login(0);
		message( "system",HIR"\n�����������̱���ֹ��\n\n"NOR,users() );
		sys_log("shutdown",sprintf("(%s) stop shutdown process at %s\n",geteuid(me),ctime(time())) );
		write("ok.\n");
		return 1;
	}

	sys_log("shutdown",sprintf("(%s) shutdown mud at %s\n",geteuid(me),ctime(time())) );

	if(arg == "now")
	{
		write("ok.\n");
		do_shutdown();
		return 1;
	}

	if(!(count = atoi(arg)) || count < 0)
		return notify_fail("��ָ�� shutdown ʱ�䡣\n");

	LOGIN_D->set_no_login(1);

	time = count * 60;

	message( "system", sprintf(HIR"\n������Ϸ������������ %s ���ӣ����λ��ұ�����Լ��������˳���Ϸ��\n\n"NOR,
		chinese_number(count)),users() );

	call_out("continue_shut",count<2?10:60,count<2?1:0);
	return 1;
}

protected void continue_shut(int flag)
{
	if(!flag)
		time -= 60;
	else
		time -= 10;

	if(time <= 0)
	{
		do_shutdown();
		return;
	}

	call_out("continue_shut",time>60?60:10,time>60?0:1);

	message( "system", sprintf(HIR"\n������Ϸ������������ %s %s�����λ��ұ�����Լ��������˳���Ϸ��\n\n"NOR,
		chinese_number(time<60?time:time/60),time<60?"��":"����"),users() );
}

protected void do_shutdown()
{
	object *user,link_ob;
	int i,n;

	message( "system", "��Ϸ�������������Ժ�һ���������߽��롣\n", users() );

	user = users();
	n = sizeof(user);

	for(i=0; i<n; i++)
	{
		if( !environment(user[i]) ) continue;
		user[i]->save();
		link_ob = user[i]->query_temp("link_ob");
		if( objectp(link_ob) ) link_ob->save();
	}

	if( find_object(DNS_MASTER) ) DNS_MASTER->send_shutdown();

	shutdown(exit_code);
}

int clean_up()
{
	if(time)
		return 1;
	return ::clean_up();
}

int help (object me)
{
        write(@HELP
ָ���ʽ: shutdown
          ��������Ϸ��

	shutdown now	������������
	shutdown <n>	n �����Ժ���������
	shutdown stop	ֹͣ������������

HELP
);
        return 1;
}
