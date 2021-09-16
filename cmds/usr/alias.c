// alias.c
// bye Find.

inherit F_CLEAN_UP;

private string show_global_alias();

int main(object me, string arg)
{
	int i;
	mapping alias;
	string verb, replace, *vrbs,out;

	seteuid(getuid());

	if( !arg )
	{
		out = "\n        ��Ŀǰ��ʹ�õ��滻��д���£�\n\nϵͳ���ṩ�� alias��\n";
		out += show_global_alias();

		alias = me->query_all_alias();
		if( !sizeof(alias) )
		{
			out += "��Ŀǰû���Լ��趨 alias��\n";
			me->start_more(out);
			return 1;
		}

		else
		{
			out += "\n��Ŀǰ�Լ��趨�� alias �У�\n";
			vrbs = keys(alias);
			for(i=0; i<sizeof(vrbs); i++)
				out += sprintf("%-15s = %s\n", vrbs[i], alias[vrbs[i]]);
			me->start_more(out);
			return 1;
		}
	}

	if( sscanf(arg, "%s %s", verb, replace)!=2 )
		me->set_alias(arg, 0);
	else if( verb[0..4] == "alias" )
		return notify_fail("�㲻�ܽ� \"alias\" ָ���趨������;��\n");
	else if( verb=="" )
		return notify_fail("��Ҫ��ʲô alias��\n");
	else
		return me->set_alias(verb, replace);

	write("Ok.\n");
	return 1;
}

private string show_global_alias()
{
	mapping g_alias;
	string *key,out = "";
	int i,n;

	if( !mapp(g_alias = ALIAS_D->query_global_alias()) )
		return "";

	if(!(n = sizeof(key = sort_array(keys(g_alias),1))))
		return "";

	for(i=0;i<n;i++)
		out += sprintf("%-9s = %-14s%s",
			key[i],
			g_alias[key[i]],
			!((i+1)%3)?"\n":""
			);
	return out[<1]=='\n'?out:(out+"\n");
}

int help (object me)
{
	write(@HELP
ָ���ʽ : alias <���趨ָ֮��> <ϵͳ�ṩָ֮��>
 
��ʱϵͳ���ṩָ֮����Ҫ����ܳ����ִ�, ��ʹ��
ʱ(�����Ǿ����õ���)�����о�������, ��ʱ�㼴
���ô�һָ���趨�����ԭ��ָ֮�
 
����:
  'alias sc score' ���� sc ȡ�� score ָ�

  'alias sc' ������ sc ������ָ�
             (���������Ļ�)

  'alias' ���治�Ӳ������г������ʹ�õ����е�
          ���ָ���ʽΪ�Ⱥ����Ϊ��д���Ҳ�
          Ϊϵͳ���

 
���п����� $1, $2, $3 .... ��ȡ����һ���ڶ���
���������������� $* ȡ�����еĲ�����

���磺
	'alias pb put $1 in $2'

��ÿ�����
	pb bandage bag

�ͻ�ȡ���ɣ�
	put bandage in bag
	
HELP
);
        return 1;
}
