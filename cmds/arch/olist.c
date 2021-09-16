// olist.c
// by 发现号(find) . 

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
			return notify_fail("物件 "+arg+" 不存在。\n");
	}

	else ob = children(USER_OB);
	/*
	if(sizeof(ob) <= 1)
		return notify_fail("物件 "+arg+" 没有复制品。\n");
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
指令格式: olist
 
列出所有的人(包括断线)的名称、状态和所处位置。
 
HELP
);
        return 1;
}