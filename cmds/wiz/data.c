//edit by hao @1998.4.13

#include <dbase.h>
inherit F_DBASE;
int main(object me, string arg)
{
	mapping list, temp_list;
	mixed *klist, *ktemp_list;
	object ob;
	string text="";
	int loop;

	if(!arg || arg == "")
		ob=me;
	else 
	{
		arg=lower_case(arg); 
		if(arg == "here")
			ob = environment(me);
		else if(!ob=present(arg,environment(me)))
			ob = present(arg,me);
		if(!ob)
			return notify_fail("û��������. \n");
	};
	list=(mapping)ob->query_entire_dbase();
	temp_list=(mapping)ob->query_entire_temp_dbase();
	if( (!list || !mapp(list)) && (!temp_list || !mapp(temp_list)))
		return notify_fail("Data: �������û���κε����ϡ�\n"); 
	if (sizeof(list))
	{
		klist = keys(list);
		klist = sort_array(klist, "sort_keys", this_object());
	};
	if (sizeof(temp_list))
	{
		ktemp_list=keys(temp_list);
		ktemp_list=sort_array(ktemp_list, "sort_keys", this_object());
	};
	if(!klist || !sizeof(klist))
		return notify_fail("Data: �������û�д����κ����ϡ�\n");
	for(loop=0; loop<sizeof(klist); loop++)
	{
		if(strlen(klist[loop]) > 7)
			text = text + klist[loop] + "\t: ";
		else
			text = text + klist[loop] + "\t\t: ";
		text = text + sprintf("%O \n",list[ klist[loop] ]);
	};
	text = text + "\n�ܹ��� " + sizeof(klist) + " ����������ϡ�\n\n";
	if(ktemp_list)
	{
		text = text + "TEMP DATA :\n\n";
		for(loop=0; loop<sizeof(ktemp_list); loop++)
		{
			if(strlen(ktemp_list[loop]) > 7)
				text = text + ktemp_list[loop] + "\t: ";
			else
				text = text + ktemp_list[loop] + "\t\t: ";
			text = text + sprintf("%O \n",temp_list[ ktemp_list[loop] ]); 
		};
		text = text + "\n�ܹ��� " + sizeof(ktemp_list) + " ���ݴ�����ϡ�\n\n";
	};
	me->start_more( text );
	return 1;
}

int help(object me)
{
write(@HELP
ָ���ʽ : data <id>
	   data here

��ȡ����ı����ĵ�ǰֵ��data here Ϊ��ȡ��
���ڻ�������ı�����ǰֵ�������κβ�����Ĭ
�����Ϊ�Լ���
HELP
    );
    return 1;
}