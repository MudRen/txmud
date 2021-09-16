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
			return notify_fail("没有这个物件. \n");
	};
	list=(mapping)ob->query_entire_dbase();
	temp_list=(mapping)ob->query_entire_temp_dbase();
	if( (!list || !mapp(list)) && (!temp_list || !mapp(temp_list)))
		return notify_fail("Data: 此物件并没有任何的资料。\n"); 
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
		return notify_fail("Data: 此物件并没有储存任何资料。\n");
	for(loop=0; loop<sizeof(klist); loop++)
	{
		if(strlen(klist[loop]) > 7)
			text = text + klist[loop] + "\t: ";
		else
			text = text + klist[loop] + "\t\t: ";
		text = text + sprintf("%O \n",list[ klist[loop] ]);
	};
	text = text + "\n总共有 " + sizeof(klist) + " 个储存的资料。\n\n";
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
		text = text + "\n总共有 " + sizeof(ktemp_list) + " 个暂存的资料。\n\n";
	};
	me->start_more( text );
	return 1;
}

int help(object me)
{
write(@HELP
指令格式 : data <id>
	   data here

读取物件的变量的当前值，data here 为读取你
所在环境物件的变量当前值。不加任何参数的默
认物件为自己。
HELP
    );
    return 1;
}