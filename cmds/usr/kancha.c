// /cmds/usr/kancha.c
// 勘察此地的可建房情况。
// by Find.

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	object env;
	string outdoors,output;
	mapping domain_cost,exits;
	int up;

	env = environment(me);
	if(!env)
		return notify_fail("你现在在哪呀。\n");

	if(!sscanf(file_name(env), "/d/%*s"))
		return notify_fail("脚落实地以后再勘察吧！！\n");

	if(!outdoors = env->query("outdoors"))
		return notify_fail("想在别人的房子里建家？这个主意不错。\n");

	if(env->query("cannot_build_home") || virtualp(env))
		return notify_fail("这根本不能建房，你就别费劲了。\n");

	if(env->query("GATE_ROOM"))
		return notify_fail("想在门洞里建房？就别费劲了。\n");

	if(env->query("virtual_room"))
		return notify_fail("这里不能建房。\n");

	if( (outdoors = domain_file(file_name(env))) == "phome")
		return notify_fail("想把房子建在别人家里？\n");

	if(!mapp(domain_cost = PLAYERHOME_D->query_this_domain_cost(outdoors)))
		return notify_fail("这根本不能建房，就别费劲了。\n");

	exits = env->query("exits");
	if(!mapp(exits))
		return notify_fail("这里不能建房。\n");

	if(sizeof(exits) >= 4)
		return notify_fail("这里已经没有地方建房了。\n");

	if(!undefinedp(exits["north"])
	&& !undefinedp(exits["south"])
	&& !undefinedp(exits["west"])
	&& !undefinedp(exits["east"]))
		return notify_fail("这里已经没有能用于建房的出口了。\n");

	output = sprintf("在这里建房的占地费是%s两黄金。\n",
		chinese_number(domain_cost["cost"]/10000));
	if(domain_cost["origin_max"] > domain_cost["max"])
	{
		up = to_int((domain_cost["origin_max"]-domain_cost["max"])*100/domain_cost["origin_max"]*
			domain_cost["cost"]/10000/100)*10000;
		output += sprintf("由于目前建房指标减少，占地费已上涨为%s两黄金。\n",
			chinese_number((domain_cost["cost"]+up)/10000));
	}

	if( !undefinedp(domain_cost["min_level"])
	&& (domain_cost["min_level"] > 1) )
	{
		if(domain_cost["min_level"] == 2)
			output += "在这里建房至少也要是一间瓦房。\n";
		else if(domain_cost["min_level"] == 3)
			output += "在这里建房至少也要是一所宅院。\n";
		else if(domain_cost["min_level"] == 4)
			output += "这里只能建造豪华大宅院。\n";
	}

	if( !undefinedp(domain_cost["max_level"])
	&& (domain_cost["max_level"] < 4) )
	{
		if(domain_cost["max_level"] == 1)
			output += "在这里建房只能建造茅草房。\n";
		else if(domain_cost["max_level"] == 2)
			output += "在这里建房顶多只能建造一间瓦房。\n";
		else if(domain_cost["max_level"] == 3)
			output += "在这里建房顶多只能建造一所宅院。\n";
	}

	if(domain_cost["max"] == 0)
		output += "但是这个地区已经没有建房指标了。\n";

	else if(domain_cost["max"] == -1)
		output += "目前朝廷还没有限制这里的建房数量。\n";
	else
	{
		if(domain_cost["origin_max"] == domain_cost["max"])
			output += sprintf("这个地区目前共有%s个建房指标。\n",
				chinese_number(domain_cost["max"]));
		else
			output += sprintf("这个地区原有%s个建房指标，目前还剩下%s个。\n",
				chinese_number(domain_cost["origin_max"]),
				chinese_number(domain_cost["max"]) );
	}

	if( file_size(sprintf("%s%s/%s_home.c",PHOME_DIR,outdoors,me->query("id"))) > 0 )
		output += sprintf("你在%s已建有自己的住宅，不能在这个地区再建造了。\n",
			to_chinese(outdoors));
	write(output);
	return 1;
}

int help(object me)
{
  write(@HELP
这个命令可以帮助你勘察你所在地点的
关于建造房屋方面的情况。
HELP
    );
    return 1;
}