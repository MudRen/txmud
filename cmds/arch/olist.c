// olist.c
// by ���ֺ�(find) . 

inherit F_CLEAN_UP;

int main(object me,string arg)
{
	int i;
	object *ob;

	if(stringp(arg))
	{
		if(arg == "here" && environment(me))
			arg = base_name(environment(me));
		ob = children(arg);
		if(!ob)
			return notify_fail("��� "+arg+" �����ڡ�\n");
	}

	else ob = children(USER_OB);
	/*
	if(sizeof(ob) <= 1)
		return notify_fail("��� "+arg+" û�и���Ʒ��\n");
	*/
	for(i=0;i<sizeof(ob);i++)
	{
		if(!clonep(ob[i])) continue;
		write(sprintf("%s at (%s)\n",(stringp(arg) && arg == LOGIN_OB)?
			ob[i]->query("id"):ob[i]->short(),
			environment(ob[i])? file_name(environment(ob[i])): 
				"no environment !" ));
	}
	return 1;
}

int help (object me)
{
        write(@HELP
ָ���ʽ: olist
 
�г����е���(��������)�����ơ�״̬������λ�á�
 
HELP
);
        return 1;
}