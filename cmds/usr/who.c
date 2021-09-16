// who.c
// by Find.

#define WIZ	1
#define LONG	2
#define FAMILY	4

#include <ansi.h>
#include <net/dns.h>
#include <net/daemons.h>
#include <net/macros.h>

inherit F_CLEAN_UP;
int all;
mixed main(object me, string arg, int remote)
{
	string *str=({}), *option,mud_name,out,bps_string;
	object *list;
	int flag,n,i,l,bk,s_all;
	mapping mud_list;
	float *bps;

	if(arg)
	{
		option = explode(arg, " ");
		i = sizeof(option);
		while( i-- )
			switch(option[i])
			{
				case "-l":
					flag |= LONG;
					break;
				case "-f":
/*
					if(!me->query("family"))
						return notify_fail("��Ŀǰû�м����κ���֯��\n");
					else
*/
						flag |= FAMILY;
					break;
				case "-w":
					flag |= WIZ;
					break;
				default:
                                        if( option[i][0]=='@' )
					{
						if(!find_object(DNS_MASTER))
							return notify_fail("��·���鲢û�б����롣\n");
						mud_list = (mapping)DNS_MASTER->query_muds();
						if(!mud_list)
							return notify_fail( "����ϷĿǰ��û�и���·��������Ϸȡ����ϵ��\n");

						mud_name = option[i][1..];
						mud_name = htonn(mud_name);

						if(mud_name == mud_nname())
							return notify_fail("�鿴����Ϸ�����������ʹ�� who [-l|-f|-w] ��ʽ��\n");
						if(!mapp(mud_list[mud_name]))
							return notify_fail("δ�����Ϸȡ����ϵ��\n");

						RWHO_Q->send_rwho_q(mud_name, me, flag&LONG?1:0);
						write("��·ѶϢ���ͳ������Ժ�\n");
						return 1;
					}
					return notify_fail("ָ���ʽ��who [-l|-f|-w]\n");
			}
	}

	bps = query_bandwide();
	bps_string = sprintf("�˿ڽ�������������%.2f K/�룬�ͳ�������%.2f K/��",bps[0]*8/1000, bps[1]*8/1000);
	s_all = LOGIN_D->all_online_players();

	out = sprintf("�� ������Ϸ��%s\n",MUD_NAME);
	out += "��������������������������������������������������������������������������\n";
	all = 0;
	list = filter_array(children(USER_OB),"filter_users",this_object(),me,flag);
	if(!(n=sizeof(list)))
	{
		out += "û�з�������ѯ��������ҡ�\n";
		out += "��������������������������������������������������������������������������\n";
		out += sprintf("[����ʱ�䣺%s]\n",cctime(time()));
		out += sprintf("[Ŀǰ���� %d λʹ����������%s]\n[%s]\n\n",s_all+all,
			all?sprintf("����վ���� %d ��",all):"",bps_string);
		if( remote )
			return out;
		else
			write(out);
		return 1;
	}

	list = sort_array(list, "sort_user", this_object());

	if(flag&LONG)
	{
		for(i=0;i<n;i++)
			out += sprintf("%12s %s%s%s\n",
				RANK_D->query_rank(list[i]),
				list[i]->short(2),
				list[i]->query_temp("netdead")?HIR+"<������>"+NOR:"",
				list[i]->query("env/invisibility")?"[����]":"");
		out += "��������������������������������������������������������������������������\n";
		out += sprintf("[����ʱ�䣺%s]\n",cctime(time()));
		out += sprintf("[Ŀǰ���� %d λʹ����������%s]\n[%s]\n\n",s_all+all,
			all?sprintf("����վ���� %d ��",all):"",bps_string);
		if( remote )
			return out;
		else
			me->start_more(out);
		return 1;
	}

	for(i=0;i<n;i++)
	{
		string item;
		item = sprintf("%s(%s)",list[i]->name(1),capitalize(list[i]->query("id")));
		if(strlen(item) > l)
			l = strlen(item);
		str += ({ item });
	}

	bk = to_int(85/(l+2));
	for(i=0;i<n;i++)
		out += sprintf("%-"+(string)l+"s  %s",str[i],(i%bk==(bk-1))||i==n-1?"\n":"");

	out += "��������������������������������������������������������������������������\n";
	out += sprintf("[����ʱ�䣺%s]\n",cctime(time()));
	out += sprintf("[Ŀǰ���� %d λʹ����������%s]\n[%s]\n\n",s_all+all,
		all?sprintf("����վ���� %d ��",all):"",bps_string);
	if( remote )
		return out;
	else
		me->start_more(out);
	return 1;
}

int filter_users(object user,object me,int flag)
{
	if(!clonep(user) || !environment(user))
		return 0;
	all++;
	if(me && !me->visible(user))
		return 0;
	/* Զ����Ϸ���ܲ�֪����������ʦ */
	if( !me && wizardp(user) && user->query("env/invisibility"))
		return 0;

	if( (flag&WIZ) && !wizardp(user))
		return 0;

	if( (flag&FAMILY)
	&& (user->query("family/family_name") != me->query("family/family_name")) )
		return 0;
	return 1;
}

int sort_user(object ob1, object ob2)
{
	if( wizardp(ob1) && !wizardp(ob2) ) return 1;
	
	if( wizardp(ob2) && !wizardp(ob1) ) return -1;

	if( wizardp(ob1) && wizardp(ob2) )
		return  wiz_level(ob1) - wiz_level(ob2);
	
	return 1;
}

int help(object me)
{
write(@HELP
ָ���ʽ : who [-l|-f|-w]

���ָ������г����������ϵ���Ҽ���ȼ���

-l ѡ���г��ϳ���ѶϢ��
-f �г����ߵ�ͬ�����ѶϢ��
-w ֻ�г��������е���ʦ��

�� who @ ����Զ�˵���Ϸ�������г��뱾��Ϸ
ȡ����ϵ��Զ����Ϸ����������б�Զ����Ϸ
������ mudlist �����֪��

���ָ� finger	mudlist
HELP
    );
    return 1;
}
