/*************************
 * wizlist.c             *
 *                       *
 * 视觉效果参考自三国。  *
 *                       *
 * by Find.              *
 *************************/

#include <ansi.h>
inherit F_CLEAN_UP;

mapping c_wizlevel = ([
"(admin)" : "管理员",
"(arch)" : "管理员",
"(sage)" : "管理员",
"(wizard)" : "管理员",
"(apprentice)" : "临时管理员",
"(adviser)" : "客座编辑",
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

	msg = sprintf("%-11s%-12s%-12s%-6s%s\n","ＩＤ","姓名","等级","状态","  时间");
	msg += "———————————————————————————————————\n";
	list = sort_array(SECURITY_D->query_wizlist(), 1);

	n = sizeof(list);
	if(!n)
		return notify_fail(sprintf("%s目前没有管理员。\n",MUD_NAME));

	for(i=0;i<n;i++)
	{
		login = new(LOGIN_OB);
		login->set("id", list[i]);
		if(!login->restore())
			continue;
		cwiz = c_wizlevel[wizhood(list[i])];
		if(!cwiz)
			cwiz = "管理员";

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
			HIR+"断线："+NOR:HIG+"连线："+NOR):"离线：",time_string(time));

		destruct(login);
	}

	msg += "———————————————————————————————————\n";
	msg += sprintf("%s目前共有%s位管理员。\n",MUD_NAME,chinese_number(n));
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
		retn += sprintf("%s天",chinese_number(day));
	if(hour)
	{
		retn += sprintf("%s小时",chinese_number(hour));
		if(day)
			return retn;
	}
	if(min)
	{
		retn += sprintf("%s分",chinese_number(min));
		if(hour || day)
			return retn;
	}
	if(sec)
		retn += sprintf("%s秒",chinese_number(sec));

	return retn;
}

int help(object me)
{
write(@HELP
指令格式 : wizlist

用途 : 按字母顺序列出目前所有的巫师名单。
HELP
     );
     return 1;
}
