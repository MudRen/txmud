// /cmds/usr/kancha.c
// ����˵صĿɽ��������
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
		return notify_fail("����������ѽ��\n");

	if(!sscanf(file_name(env), "/d/%*s"))
		return notify_fail("����ʵ���Ժ��ٿ���ɣ���\n");

	if(!outdoors = env->query("outdoors"))
		return notify_fail("���ڱ��˵ķ����ｨ�ң�������ⲻ��\n");

	if(env->query("cannot_build_home") || virtualp(env))
		return notify_fail("��������ܽ�������ͱ�Ѿ��ˡ�\n");

	if(env->query("GATE_ROOM"))
		return notify_fail("�����Ŷ��ｨ�����ͱ�Ѿ��ˡ�\n");

	if(env->query("virtual_room"))
		return notify_fail("���ﲻ�ܽ�����\n");

	if( (outdoors = domain_file(file_name(env))) == "phome")
		return notify_fail("��ѷ��ӽ��ڱ��˼��\n");

	if(!mapp(domain_cost = PLAYERHOME_D->query_this_domain_cost(outdoors)))
		return notify_fail("��������ܽ������ͱ�Ѿ��ˡ�\n");

	exits = env->query("exits");
	if(!mapp(exits))
		return notify_fail("���ﲻ�ܽ�����\n");

	if(sizeof(exits) >= 4)
		return notify_fail("�����Ѿ�û�еط������ˡ�\n");

	if(!undefinedp(exits["north"])
	&& !undefinedp(exits["south"])
	&& !undefinedp(exits["west"])
	&& !undefinedp(exits["east"]))
		return notify_fail("�����Ѿ�û�������ڽ����ĳ����ˡ�\n");

	output = sprintf("�����ｨ����ռ�ط���%s���ƽ�\n",
		chinese_number(domain_cost["cost"]/10000));
	if(domain_cost["origin_max"] > domain_cost["max"])
	{
		up = to_int((domain_cost["origin_max"]-domain_cost["max"])*100/domain_cost["origin_max"]*
			domain_cost["cost"]/10000/100)*10000;
		output += sprintf("����Ŀǰ����ָ����٣�ռ�ط�������Ϊ%s���ƽ�\n",
			chinese_number((domain_cost["cost"]+up)/10000));
	}

	if( !undefinedp(domain_cost["min_level"])
	&& (domain_cost["min_level"] > 1) )
	{
		if(domain_cost["min_level"] == 2)
			output += "�����ｨ������ҲҪ��һ���߷���\n";
		else if(domain_cost["min_level"] == 3)
			output += "�����ｨ������ҲҪ��һ��լԺ��\n";
		else if(domain_cost["min_level"] == 4)
			output += "����ֻ�ܽ��������լԺ��\n";
	}

	if( !undefinedp(domain_cost["max_level"])
	&& (domain_cost["max_level"] < 4) )
	{
		if(domain_cost["max_level"] == 1)
			output += "�����ｨ��ֻ�ܽ���é�ݷ���\n";
		else if(domain_cost["max_level"] == 2)
			output += "�����ｨ������ֻ�ܽ���һ���߷���\n";
		else if(domain_cost["max_level"] == 3)
			output += "�����ｨ������ֻ�ܽ���һ��լԺ��\n";
	}

	if(domain_cost["max"] == 0)
		output += "������������Ѿ�û�н���ָ���ˡ�\n";

	else if(domain_cost["max"] == -1)
		output += "Ŀǰ��͢��û����������Ľ���������\n";
	else
	{
		if(domain_cost["origin_max"] == domain_cost["max"])
			output += sprintf("�������Ŀǰ����%s������ָ�ꡣ\n",
				chinese_number(domain_cost["max"]));
		else
			output += sprintf("�������ԭ��%s������ָ�꣬Ŀǰ��ʣ��%s����\n",
				chinese_number(domain_cost["origin_max"]),
				chinese_number(domain_cost["max"]) );
	}

	if( file_size(sprintf("%s%s/%s_home.c",PHOME_DIR,outdoors,me->query("id"))) > 0 )
		output += sprintf("����%s�ѽ����Լ���סլ����������������ٽ����ˡ�\n",
			to_chinese(outdoors));
	write(output);
	return 1;
}

int help(object me)
{
  write(@HELP
���������԰����㿱�������ڵص��
���ڽ��췿�ݷ���������
HELP
    );
    return 1;
}