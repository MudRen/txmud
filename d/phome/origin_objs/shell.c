// shell.c
// 玩家的中文名如改名，此处应能自动更改。

inherit ITEM;

private void get_domain(string arg,object me);
private void confirm_cost(string arg,object me,int cost);
private void get_level(string arg,object me);
int is_build_home_shell() {return 1;}

void create()
{
        set_name("建房申请表", ({"shell"}));
        set("long",
                "这是一张没有填写(tianxie)的空白建房申请表。\n");
        set("unit", "张");
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
		return notify_fail("这张表格已经填写过了，要重填再去买一张空白的吧。\n");

	write("你准备交多少地皮使用费？(单位：两/黄金)\n");
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
		write("你准备交多少地皮使用费？(单位：两/黄金)\n");
		input_to ((: get_domain :),me);
		return;
	}

	write("你准备交"+chinese_number(cost)+"两黄金的地皮使用费吗？(y/n)\n");
	input_to((: confirm_cost :),me,cost);
}

private void confirm_cost(string arg,object me,int cost)
{
	if(arg[0] == 'q')
		return;

	if(arg == "" || (arg[0]!='y' && arg[0]!='Y'))
	{
		write("你准备交多少地皮使用费？(单位：两/黄金)\n");
		input_to ((: get_domain :),me);
		return;
	}

	set("domain_cost",cost*10000);
	write("可修建的房屋等级如下：\n");
	write(sprintf("  1. 一间茅草屋(大约%d两黄金)          2. 一间瓦房(大约%d两黄金)\n",
		to_int(PLAYERHOME_D->home_value(1)/gold_bvalue()),
		to_int(PLAYERHOME_D->home_value(2)/gold_bvalue()) ));
	write(sprintf("  3. 一所宅院(大约%d两黄金)            4. 豪华大宅院(大约%d两黄金)\n",
		to_int(PLAYERHOME_D->home_value(3)/gold_bvalue()),
		to_int(PLAYERHOME_D->home_value(4)/gold_bvalue()) ));
	write("请选择你要修建的房屋等级(1-4)：\n");
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
	write("可修建的房屋等级如下：\n");
	write(sprintf("  1. 一间茅草屋(大约%d两黄金)          2. 一间瓦房(大约%d两黄金)\n",
		to_int(PLAYERHOME_D->home_value(1)/gold_bvalue()),
		to_int(PLAYERHOME_D->home_value(2)/gold_bvalue()) ));
	write(sprintf("  3. 一所宅院(大约%d两黄金)            4. 豪华大宅院(大约%d两黄金)\n",
		to_int(PLAYERHOME_D->home_value(3)/gold_bvalue()),
		to_int(PLAYERHOME_D->home_value(4)/gold_bvalue()) ));
	write("请选择你要修建的房屋等级(1-4)：\n");
	input_to((: get_level :),me);
	}

	set("player_id",me->query("id"));
	set("home_level",level);
	set("long","这是一张填写好的建房申请表，抬头写着：申请人 "
		+me->query("name")+"。\n");
	tell_object(me,"ok.\n");
}
