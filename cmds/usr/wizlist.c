/*************************
 * wizlist.c             *
 *                       *
 * �Ӿ�Ч���ο���������  *
 *                       *
 * by Find.              *
 *************************/

#include <ansi.h>
inherit F_CLEAN_UP;

mapping c_wizlevel = ([
"(admin)" : "����Ա",
"(arch)" : "����Ա",
"(sage)" : "����Ա",
"(wizard)" : "����Ա",
"(apprentice)" : "��ʱ����Ա",
"(adviser)" : "�����༭",
]);

string time_string(int time);

int main(object me, string arg)
{
	string *list,msg,cwiz;
	int time,i,n,online;
	object login,user;

	seteuid(ROOT_UID);

	if( (arg == "-l") && !wizardp(me) )
		arg = 0;

	msg = sprintf("%-11s%-12s%-12s%-6s%s\n","�ɣ�","����","�ȼ�","״̬","  ʱ��");
	msg += "����������������������������������������������������������������������\n";
	list = sort_array(SECURITY_D->query_wizlist(), 1);

	n = sizeof(list);
	if(!n)
		return notify_fail(sprintf("%sĿǰû�й���Ա��\n",MUD_NAME));

	for(i=0;i<n;i++)
	{
		login = new(LOGIN_OB);
		login->set("id", list[i]);
		if(!login->restore())
			continue;
		cwiz = c_wizlevel[wizhood(list[i])];
		if(!cwiz)
			cwiz = "����Ա";

		if(objectp(user = find_player(list[i]))
		&& (!user->query("env/invisibility")
		|| (arg == "-l") ) )
			online = 1;
		else
			online = 0;

		if(online)
		{
			if(user->query_temp("netdead"))
				time = time() - (int)user->query_temp("netdead");
			else
				time = time() - (int)login->query("last_on");
		}
		else
			time = time() - (!login->query("last_out")?
						login->query("last_on"):
						login->query("last_out"));

		msg += sprintf( "%-11s%-12s%-12s%-6s%s\n",
			list[i],login->query("name"),cwiz,online?(user->query_temp("netdead")?
			HIR+"���ߣ�"+NOR:HIG+"���ߣ�"+NOR):"���ߣ�",time_string(time));

		destruct(login);
	}

	msg += "����������������������������������������������������������������������\n";
	msg += sprintf("%sĿǰ����%sλ����Ա��\n",MUD_NAME,chinese_number(n));
	write(msg);
	return 1;
}

string time_string(int time)
{
	int day,hour,min,sec;
	string retn = "";

	if(!intp(time) || !time)
		return retn;

	sec = time%60;
	time /= 60;
	min = time%60;
	time /= 60;
	hour = time%24;
	time /= 24;
	day = time;

	if(day)
		retn += sprintf("%s��",chinese_number(day));
	if(hour)
	{
		retn += sprintf("%sСʱ",chinese_number(hour));
		if(day)
			return retn;
	}
	if(min)
	{
		retn += sprintf("%s��",chinese_number(min));
		if(hour || day)
			return retn;
	}
	if(sec)
		retn += sprintf("%s��",chinese_number(sec));

	return retn;
}

int help(object me)
{
write(@HELP
ָ���ʽ : wizlist

��; : ����ĸ˳���г�Ŀǰ���е���ʦ������
HELP
     );
     return 1;
}
