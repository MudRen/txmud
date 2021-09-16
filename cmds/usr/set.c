// set.c
// Modified by Find.

#define MAX_ENV_VARS	20
 
inherit F_CLEAN_UP;
 
int help();
 
int main(object me, string arg)
{
	int i;
	string term, *terms, *w_set,*p_set;
	mixed data;
	mapping env;

	w_set = ({"msg_home","msg_min","msg_mout","msg_clone","msg_dest","invisibility", "immortal"});
	p_set = ({ "brief","wimpy","no_teach","no_accept","no_tell","no_emote","mute" });

	if( me != this_player(1) ) return 0;
 
	env = me->query("env");
 
	if( !arg || arg=="" )
	{
		if( !mapp(env) || !sizeof(env) )
			write("��Ŀǰû���趨�κλ���������\n");
		else
		{
			write("��Ŀǰ�趨�Ļ��������У�\n");
			terms = keys(env);
			for(i=0; i<sizeof(terms); i++)
				printf("%-20s  %O\n", terms[i], env[terms[i]]);
		}
		return 1;
	}

	if( sscanf(arg, "%s %s", term, data)!=2 )
	{
		term = arg;
		data = "YES";
	}

	if(term[<1] == '/')
		term = term[0..<2];
 
	if( term && term!="" )
	{
		if( mapp(env) && undefinedp(env[term]) && sizeof(env) >= MAX_ENV_VARS )
			return notify_fail("����Ļ�������̫���ˣ������� unset ɾ�������ɡ�\n");
		if( member_array(term, w_set) == -1 && member_array(term, p_set) == -1)
			return notify_fail("Ŀǰû�ж��� "+term+" �������������\n����� help settings"+
			((wiz_level(me))?" & wiz_settings ":" ")+"�������趨��\n");
		sscanf(data, "%d", data);
		if(!wizardp(me) && (member_array(term, w_set) != -1))
			return notify_fail("ֻ����ʦ���趨�������������\n");
		me->set("env/" + term, data);
		printf("�趨����������%s = %O\n", term, data);
		return 1;
	}
	return help();
}
 
int help()
{
	write(@TEXT
ָ���ʽ��set <������> [<����ֵ>]
 
���ָ�������趨һЩ�������������Ӳ���ʱ����ʾ��Ŀǰ�趨�Ļ�����������ָ��
����ֵ�����ڶ�ֵΪ "YES"��
 
ȡ�������趨���� unset ָ�
 
�������Щ�������������趨����� help settings��
TEXT
	);
	return 1;
}
