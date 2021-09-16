//	/adm/daemons/autosave.c

#define TIME	1800

#include <ansi.h>

protected void do_start_save();

protected void create()
{
	seteuid(getuid());
	do_start_save();
}

protected void do_start_save()
{   
	message("channel:sys", HIC "�����̾��顿:"  + HIG + "�Զ����̹���������\n" NOR,users());
	call_out("do_save",TIME);
	call_out("do_count",180);
}

protected void do_save()
{
	object *ob;
	int i;

	remove_call_out("do_save");
	ob=users();

	for(i=0;i<sizeof(ob);i++)
	{
		if(!wizardp(ob[i]) && environment(ob[i]) && !ob[i]->query_temp("netdead"))
		{
			tell_object(ob[i],GRN"�����̾��顿�����ķܶ��ɹ��Ѿ���������ˡ�\n"NOR);
			ob[i]->save();
		}
	}

	call_out("do_save",TIME);
}

protected void do_count()
{
	int n;

	remove_call_out("do_count");
	call_out("do_count",600);

	n = sizeof( filter_array( children(USER_OB), (: clonep :)) );

	n += LOGIN_D->all_online_players();

	log_file("table",sprintf("%s %"+to_int(1+n/3)+"d\n",ctime(time())[11..15],n ));
	write_file("/count/count.dat",sprintf("%d",n),1);
}
