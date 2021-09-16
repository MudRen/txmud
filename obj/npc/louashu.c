// louashu.c
// by 发现号(Find).
// 建房物件。

#define SHELL	"/d/phome/origin_objs/shell"

#include <ansi.h>
inherit NPC;

/* 四级房屋的价格 1. 300 gold 2. 600 gold 3. 900 gold 4.1300 gold*/
string *home_level_name = ({ "一间茅草屋","一间瓦房","一所宅院","豪华大宅院"});

void dest_objects();
void get_add_item(string arg,object me);
void add_domain(string arg,object me);
void add_level(string arg,object me);
private void get_month(string arg,object me,object *homes,int pay);
private void confirm_pay(string arg,object me,string *domains);

string want_build_home(object me);

void create()
{
	// ***** This object's name must be "banned". *****
	// I think the environment of this object may be set "no_fight".
	set_name("搂阿叔", ({ "lou ashu", "lou", "ashu" }));
	set("title", "工部老吏");

	set("str", 20);
	set("gender", "男性");
	set("age", 55);
	set("long",
"只见他长的尖嘴猴腮、蟑头鼠目，两只小眼睛
放着贼光，一看就不是一个好对付的人。由于
常年在工部为官，上拍下吹，人缘很好，竞得
到了房屋管理这个肥差。\n");

	set("combat_exp", 150);
	set("attitude", "friendly");
	set("inquiry", ([
	"建房" : (: want_build_home :),
	"买房" : (: want_build_home :),
]));

	setup();
	carry_object(ARMOR_DIR"cloth")->wear();
}
 
void init()
{
	object ob;

	::init();
	if (interactive(ob = this_player()) && !is_fighting())
	{
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
	add_action("do_mai",({"mai","buy"}));
	add_action("do_add",({"bujiao","add"}));
	add_action("do_pay","pay");
}

int do_mai(string arg)
{
	object ob,me = this_player();

	if(!is_day())
		return notify_fail(CYN"搂阿叔说道：现在已经歇衙了，请早八点到晚九点前来办理。\n"NOR);

	ob = new(SHELL);

        switch(player_pay(me, 5000/* 50 两银子一张*/))
	{
		case 0:
			return notify_fail("穷光蛋，一边呆着去！\n");
		case 2:
			return notify_fail("您的零钱不够了，银票又没人找得开。\n");
		default:
                message_vision("$N从$n那里买下了一张建房申请表。\n", me, this_object());
                ob->move(me);
        }
        return 1;
}

int accept_object(object who, object ob)
{
	int domain,home,level;

	if(!is_day())
	{
		command("say 现在已经歇衙了，请早八点到晚九点前来办理。\n");
		return 0;
	}

/*
	if(wizardp(who))
	{
		command("say 巫师给我东西作什么？要给就给点权限。\n");
		return 0;
	}
*/

	if(!ob->is_build_home_shell())
	{
		if(ob->query("money_id"))
		{
			if(to_int(ob->value()) >= 1000)
			{
				command("say 又能去醉仙楼喝一顿了，多谢，多谢。\n");
				dest_objects();
				return 1;
			}
			command("say 要贿赂朝廷命官！！你不想活了！\n");
			return 0;
		}
		if(who->query("gender") == "女性")
		{
			if(who->query("age") <= 30)
			{
				command("xixi");
				command("say 这位姑娘送我东西，是不是对我有意思了，哪我就收下了。\n");
				dest_objects();
				return 1;
			}
			command("say 这么大岁数的女人，给我什么也没用。\n");
			return 0;
		}
		command("say 什么乱七八糟的东西也往本官这塞，给我出去！\n");
		return 0;
	}

	if(!ob->query("player_id"))
	{
		command("say 给我一张空表作什么。\n");
		return 0;
	}

	if(ob->query("player_id") != who->query("id"))
	{
		command("say 建房申请表只能本人来交。\n");
		return 0;
	}

	if(who->query("age") < 18)
	{
		command("say 你还没成年呢，还不能建自己的房。\n");
		dest_objects();
		return 1;
	}
	
	domain = ob->query("domain_cost");
	level  = ob->query("home_level");
	home   = PLAYERHOME_D->home_value(level);

	if(!pay_from_bank(who,domain+home))
	{
		command("say 你银行存款不够，建房的事情以后再说吧。\n");
		return 1;
	}

	who->set("can_build_home/level",level);
	who->set("can_build_home/cost_home",home);
	who->set("can_build_home/cost_domain",domain);
	who->set("can_build_home/time",time());
	who->save();

	command("nod");
	command("say 各项费用都通过银行划拨了，快去建房吧，建房指标可是有限的，晚了就没了。\n");
	command("say 注意：建房时间不要超过一个月。\n");
	dest_objects();
	return 1;
}

void greeting(object ob)
{
	if(!ob || environment(ob) != environment())
		return;

	if(!is_day())
		return;

	switch(random(2))
	{
		case 0 :
			command("say 这位"+RANK_D->query_respect(ob)+"来见本官有何事情？\n");
			break;
		case 1 :
			command("say 这里只办理建房事宜，其他事情就请回吧。\n");
			break;
	}
}

string want_build_home(object me)
{
	if(!is_day())
		return "现在已经歇衙了，请早八点到晚九点前来办理。\n";

	if(PLAYERHOME_D->user_have_home(me->query("id")))
	{
		command("shake");
		return "由于地皮紧张，每人只能建一套住宅。\n";
	}

	if(wizardp(me))
		return "巫师跑这来捣什么乱，给我靠边站！\n";

	if(me->query("age") < 18)
		return "请十八岁成年以后再来吧\n";

	return "要建房吗?看好地点了吗?买(mai)一张建房申请表(shell)填(tianxie)好了交给我。\n";
}

void dest_objects()
{
	int i;
	object *inv;

	inv = all_inventory(this_object());
	for(i=0;i<sizeof(inv);i++)
	{
		if(inv[i]->query("id") == "cloth")
			continue;
		destruct(inv[i]);
	}
}

int do_add(string arg)
{
	object me = this_player();

	if(!mapp(me->query("can_build_home")))
		return notify_fail("你没有办理过建房手续，补交什么款，给我出去！\n");
	write("补交款项目：	1.地皮费		2.房价。\n");
	write("请选择要补交的费用类型：\n");
	input_to((: get_add_item :),me);
	return 1;
}

void get_add_item(string arg,object me)
{
	int level;

	switch (atoi(arg))
	{
		case(1):
			write("你要补交多少两黄金的地皮费？\n");
			input_to((: add_domain :),me);
			break;
		case(2):
			level = (int)me->query("can_build_home/level");
			if(level == 4)
			{
				write("你交的房款足够修建最高级的住宅，不用再补交房价了。\n");
				return;
				break;
			}

			write(sprintf("你已交的房价可以修建%s。\n",home_level_name[level-1]));
	write(sprintf("  1. 一间茅草屋(%s)          2. 一间瓦房(%s)\n",
			"不用补交",
		(level>=2)?"不用补交":"需补交"+to_int(( PLAYERHOME_D->home_value(2)-PLAYERHOME_D->home_value(level))/gold_bvalue())+"两黄金" ));
	write(sprintf("  3. 一所宅院(%s)            4. 豪华大宅院(%s)\n",
		(level>=3)?"不用补交":"需补交"+to_int(( PLAYERHOME_D->home_value(3)-PLAYERHOME_D->home_value(level))/gold_bvalue())+"两黄金",
		(level>=4)?"不用补交":"需补交"+to_int((PLAYERHOME_D->home_value(4)-PLAYERHOME_D->home_value(level))/gold_bvalue())+"两黄金", ));

			write("请选择你要建造的房屋类型：\n");
			input_to((: add_level :),me);
			break;
		default:
			write("补交款项目：	1.地皮费		2.房价。\n");
			write("请选择要补交的费用类型：\n");
			input_to((: get_add_item :),me);
			return;
	}
}

void add_domain(string arg,object me)
{
	int fee;
	if(!atoi(arg))
	{
		write("你要补交多少两黄金的地皮费？\n");
		input_to((: add_domain :),me);
		return;
	}

	else
	{
		fee = to_int(atoi(arg)*gold_bvalue());
		if(!pay_from_bank(me,fee))
		{
			write("你银行存款不够，以后再说吧。\n");
			return;
		}

		me->add("can_build_home/cost_domain",fee);
		write("ok.\n");
		return;
	}
}

void add_level(string arg,object me)
{
	int level,fee;

	level = (int)me->query("can_build_home/level");

	if(!atoi(arg) || atoi(arg) <= level)
	{
		write(sprintf("你已交的房价可以修建%s。\n",home_level_name[level-1]));
		write(sprintf("  1. 一间茅草屋(%s)          2. 一间瓦房(%s)\n",
			"不用补交",
		(level>=2)?"不用补交":"需补交"+to_int((PLAYERHOME_D->home_value(2)-PLAYERHOME_D->home_value(level))/gold_bvalue())+"两黄金", ));
		write(sprintf("  3. 一所宅院(%s)            4. 豪华大宅院(%s)\n",
		(level>=3)?"不用补交":"需补交"+to_int((PLAYERHOME_D->home_value(3)-PLAYERHOME_D->home_value(level))/gold_bvalue())+"两黄金",
		(level>=4)?"不用补交":"需补交"+to_int((PLAYERHOME_D->home_value(4)-PLAYERHOME_D->home_value(level))/gold_bvalue())+"两黄金", ));

		write("请选择你要建造的房屋类型：\n");
		input_to((: add_level :),me);
		return;
	}

	else
	{
		fee = PLAYERHOME_D->home_value(atoi(arg)) - PLAYERHOME_D->home_value(level);
		if(!pay_from_bank(me,fee))
		{
			write("你银行存款不够，以后再说吧。\n");
			return;
		}

		else
		{
			me->set("can_build_home/level",atoi(arg));
			write("ok.\n");
			return;
		}
	}
}

int do_pay(string arg)
{
	object me = this_player();
	int n,i,l,bk;
	string *rooms,*domains=({});

	if(! rooms = PLAYERHOME_D->user_have_home(me->query("id")))
		return notify_fail("你没有自己的房屋。做善事去寺庙，本部不接受捐赠。\n");


	n = sizeof(rooms);
	for(i=0;i<n;i++)
	{
		string domain;
		if(sscanf(rooms[i],PHOME_DIR+"%s/%*s",domain))
			domains += ({ domain });
	}

	if((n=sizeof(domains)) == 1)
		confirm_pay("1",me,domains);

	else
	{
		string out = "";

		for(i=0;i<n;i++)
			if(strlen(domains[i]) > l)
				l = strlen(domains[i]);
		bk = to_int(60/(l+4));
		l++;
		for(i=0;i<n;i++)
			out += sprintf("%-2d.%-"+(string)l+"s%s",(i+1),domains[i],(i%bk==(bk-1))?"\n":"" );
		write("你在以下"+chinese_number(n)+"处地区都建有自己的住宅，请你选择一处：\n"+out+"\n");
		input_to( (: confirm_pay :),me, domains );
	}

	return 1;
}

private void confirm_pay(string arg,object me,string *domains)
{
	object *homes,home;
	int pay,n;
	string file;

	if(arg[0] == 'q')
		return;

	n = atoi(arg);
	n--;
	if( (n<0) || (n>=sizeof(domains)) || !me)
		return;

	file = sprintf("%s%s/%s_home",PHOME_DIR,domains[n],me->query("id"));

	home = find_object(file);
	if(!home)
		home = load_object(file);
	if(!home)
	{
		write("你的住宅有问题，请向巫师申报处理。\n");
		return;
	}

	homes = PLAYERHOME_D->player_homes(me,home);
	if( !homes || !arrayp(homes) || !sizeof(homes) )
	{
		write(sprintf("你在%s的住房出现问题，请立刻向巫师报告。\n",
			to_chinese(domains[n])));
		return;
	}

	pay = PLAYERHOME_D->home_value(homes[0]->home_level())/100; /* 每个月的修缮费为房价的 1%. */

	write(sprintf("您的住房每个月的修缮费为：%s\n",chinese_value(pay)));
	write("你要交多少个月的房屋修缮费？\n");
	input_to ((: get_month :),me,homes,pay);
	return;
}

private void get_month(string arg,object me,object *homes,int pay)
{
	int m,i;

	if(!me)
		return;

	if(arg[0] == 'q')
		return;

	if(!arg || !m = atoi(arg))
	{
		write("你要交多少个月的房屋修缮费？\n");
		input_to ((: get_month :),me,homes,pay);
		return;
	}

	write(sprintf("%s个月的修缮费一共%s。\n",chinese_number(m),chinese_value(pay*m)));
	if(!i = player_pay(me,pay*m) || i == -2)
	{
		write("你身上的现款不够，银票这找不开。\n");
		return;
	}

	for(i=0;i<sizeof(homes);i++)
	{
		homes[i]->add("built_time",m*43200 /* 43200 为 MUD 中的一个月.*/);
		homes[i]->save();
	}

	command("say "+me->name()+"交来"+chinese_number(m)+"个月房屋修缮费收讫。\n");
	return;
}