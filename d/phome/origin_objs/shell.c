// shell.c
// ��ҵ���������������˴�Ӧ���Զ����ġ�

inherit ITEM;

private void get_domain(string arg,object me);
private void confirm_cost(string arg,object me,int cost);
private void get_level(string arg,object me);
int is_build_home_shell() {return 1;}

void create()
{
        set_name("���������", ({"shell"}));
        set("long",
                "����һ��û����д(tianxie)�Ŀհ׽��������\n");
        set("unit", "��");
        set("weight", 10);
        set("value", 0);
}

void init()
{
	add_action("do_fill",({"tianxie","fill"}));
}

int do_fill(string arg)
{
	object me = this_player();

	if(arg != "shell")
		return 0;

	if(query("player_id"))
		return notify_fail("���ű���Ѿ���д���ˣ�Ҫ������ȥ��һ�ſհ׵İɡ�\n");

	write("��׼�������ٵ�Ƥʹ�÷ѣ�(��λ����/�ƽ�)\n");
	input_to ((: get_domain :),me);
	return 1;
}

private void get_domain(string arg,object me)
{
	int cost;

	if(arg[0] == 'q')
		return;

	cost = atoi(arg);
	if(!cost || !intp(cost))
	{
		write("��׼�������ٵ�Ƥʹ�÷ѣ�(��λ����/�ƽ�)\n");
		input_to ((: get_domain :),me);
		return;
	}

	write("��׼����"+chinese_number(cost)+"���ƽ�ĵ�Ƥʹ�÷���(y/n)\n");
	input_to((: confirm_cost :),me,cost);
}

private void confirm_cost(string arg,object me,int cost)
{
	if(arg[0] == 'q')
		return;

	if(arg == "" || (arg[0]!='y' && arg[0]!='Y'))
	{
		write("��׼�������ٵ�Ƥʹ�÷ѣ�(��λ����/�ƽ�)\n");
		input_to ((: get_domain :),me);
		return;
	}

	set("domain_cost",cost*10000);
	write("���޽��ķ��ݵȼ����£�\n");
	write(sprintf("  1. һ��é����(��Լ%d���ƽ�)          2. һ���߷�(��Լ%d���ƽ�)\n",
		to_int(PLAYERHOME_D->home_value(1)/gold_bvalue()),
		to_int(PLAYERHOME_D->home_value(2)/gold_bvalue()) ));
	write(sprintf("  3. һ��լԺ(��Լ%d���ƽ�)            4. ������լԺ(��Լ%d���ƽ�)\n",
		to_int(PLAYERHOME_D->home_value(3)/gold_bvalue()),
		to_int(PLAYERHOME_D->home_value(4)/gold_bvalue()) ));
	write("��ѡ����Ҫ�޽��ķ��ݵȼ�(1-4)��\n");
	input_to((: get_level :),me);
}

private void get_level(string arg,object me)
{
	int level;

	if(arg[0] == 'q')
		return;

	level = atoi(arg);
	if((level != 1)&&(level != 2)&&(level != 3)&&(level != 4) )
	{
	write("���޽��ķ��ݵȼ����£�\n");
	write(sprintf("  1. һ��é����(��Լ%d���ƽ�)          2. һ���߷�(��Լ%d���ƽ�)\n",
		to_int(PLAYERHOME_D->home_value(1)/gold_bvalue()),
		to_int(PLAYERHOME_D->home_value(2)/gold_bvalue()) ));
	write(sprintf("  3. һ��լԺ(��Լ%d���ƽ�)            4. ������լԺ(��Լ%d���ƽ�)\n",
		to_int(PLAYERHOME_D->home_value(3)/gold_bvalue()),
		to_int(PLAYERHOME_D->home_value(4)/gold_bvalue()) ));
	write("��ѡ����Ҫ�޽��ķ��ݵȼ�(1-4)��\n");
	input_to((: get_level :),me);
	}

	set("player_id",me->query("id"));
	set("home_level",level);
	set("long","����һ����д�õĽ��������̧ͷд�ţ������� "
		+me->query("name")+"��\n");
	tell_object(me,"ok.\n");
}
