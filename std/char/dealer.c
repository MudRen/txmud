// dealer.c
// by Find.

inherit NPC;

class goods {
	string name;
	string short_name;
	string file;
	string unit;
	int amount;
	int value;
}

protected class goods *all_goods = ({});
protected int uptime;

protected void init_goods();
protected int add_one_good(string file,int sum);

void setup()
{
	init_goods();
	::setup();
	if(!uptime)
		uptime = time();
}

protected void init_goods()
{
	mapping items = this_object()->query("vendor_goods");
	string name;
	int sum;

	if(!items || !mapp(items) || !sizeof(items))
		return;

	all_goods = ({});
	foreach(name,sum in items)
		add_one_good(name,sum);
}

protected int add_one_good(string file,int sum)
{
	object ob;
	class goods item;
	int n;

	if(!stringp(file) || !intp(sum))
		return 0;

	ob = new(file);
	if(!ob)
		return 0;

	item = new(class goods);

	item->name = ob->query("name");
	item->short_name = ob->query("base_cname")?
		sprintf("%s(%s)",clr_ansi(ob->query("base_cname")),capitalize(ob->query("id"))):
			clr_ansi(ob->short());
	item->file = file;
	item->unit = ob->query_amount()?ob->query("base_unit"):ob->query("unit");
	item->amount = sum;
	item->value = to_int( ((n = ob->query("value"))?
			n: (n = ob->value()) )*price_ratio(environment())/100);

	all_goods += ({ item });
	destruct(ob);
	return 1;
}

void init()
{
	add_action("do_buy", ({ "mai","buy" }) );
	add_action("do_list", "list");
}

varargs int do_list(string str)
{
        string output;
        int flag;
	class goods item;

	if(this_player()->is_busy())
	{
		write(BUSY_MESSAGE);
		return 1;
	}

	// 处理同房间有一个以上 dealer 的情况。
	if( stringp(str) && (str != "") && !id(str) )
		return 0;

	if(!is_day())
	{
		if(query("no_sell_night"))
			return 0;
		if(!query("sell_all_day"))
		{
			command("say 客官请白天再来吧。\n");
			return 1;
		}
	}

	if(query("no_sell_day"))
		return 0;

	if (!sizeof(all_goods))
	{
		write(sprintf("目前%s没有可以卖的东西。\n",query("name")));
		return 1;
	}

	output = sprintf("你可以向%s购买下列物品：\n", query("name"));
	output += sprintf(" %-26s%-10s%-10s\n","    商  品","  数量","   单  价");
	output += "----------------------------------------------\n";

	foreach(item in all_goods)
	{
		if(!(item->amount))
			continue;
		++flag;
		output += sprintf(" %-26s%-10s%s\n",item->short_name,item->amount >= 1?
			sprintf("%-3d%s",item->amount,item->unit):"货源充足",
			chinese_value(item->value));
	}

	if(!flag)
	{
		write(sprintf("目前%s没有可以卖的东西。\n",query("name")));
		return 1;
	}

	else
		write(output+"\n");
        return 1;
}

varargs int do_buy(string arg)
{
        string who;
        object ob,me;
	int sum,i,flag,n, rtn;

	if( (me = this_player())->is_busy() )
	{
		write(BUSY_MESSAGE);
		return 1;
	}

	if(!is_day())
	{
		if(query("no_sell_night"))
			return 0;
		if(!query("sell_all_day"))
		{
			command("say 客官请白天再来吧。\n");
			return 1;
		}
	}

	if(query("no_sell_day"))
		return 0;

        if(!arg || arg == "")
	{
                write("你想买什么？\n");
		return 1;
	}

	// 处理同房间有一个以上 dealer 的情况。
	if(sscanf(arg,"%s from %s",arg,who) == 2)
	{
		if(!id(who))
			return 0;
	}

	// 一次买多个同一商品。
	if(sscanf(arg,"%d %s",sum,arg) == 2)
	{
		if(sum < 1)
		{
			write("买东西每次数量不能少于一个单位。\n");
			return 1;
		}
	}
	else
		sum = 1;

	if(query_temp("busy"))
	{
		write("您请等一下，我这儿马上就忙完了。。。。。。\n");
		return 1;
	}

	n = sizeof(all_goods);
	if(!n)
	{
		write(sprintf("目前%s没有可以卖的东西。\n",query("name")));
		return 1;
	}

	for(i=0;i<n;i++)
	{
		if( (all_goods[i]->file)->id(arg) )
		{
			if(!(all_goods[i]->amount))
			{
				command(sprintf("say 对不起，目前这%s缺货，您过一段时间再来吧",
					all_goods[i]->name));
				return 1;
			}

			if( (all_goods[i]->amount > 0) && (sum > all_goods[i]->amount) )
				sum = all_goods[i]->amount;
			break;
		}
	}

	if(i >= n)
	{
		write("你想买什么？\n");
		return 1;
	}

	switch( rtn = player_pay(me, (sum * all_goods[i]->value)) )
	{
        case 0:
		write(sprintf("你身上的钱不够买%s%s%s的。\n",chinese_number(sum),
			all_goods[i]->unit,all_goods[i]->name));
                return 1;
        case 2:
		destruct(ob);
                write("您的零钱不够了，银票又没人找得开。\n");
		return 1;
        default:
                set_temp("busy", 1);

		for(n=0;n<sum;n++)
		{
			ob = new(all_goods[i]->file);
			if(rtn == 3)
				ob->set_credit_point_flag();
			if(!ob->move(me))
			{
				if(ob->move(environment(me)))
					flag = 1;
				else
				{
					if((all_goods[i]->amount) > 0)
						all_goods[i]->amount -= n;
					destruct(ob);
					write("你身上再也拿不了更多的东西了，周围也没地方放。\n");
					call_out("enough_rest", 1);
					return 1;
				}
			}
		}
                message_vision(sprintf("$N从$n那里买下了%s%s%s。\n", chinese_number(sum),
                all_goods[i]->unit,all_goods[i]->name), me, this_object());
		if(flag)
			write("你身上再也拿不了更多的东西，其他的东西只能给您放地上了。\n");
        }

	all_goods[i]->amount -= sum;
	remove_call_out("enough_rest");
	call_out("enough_rest", 1);
	return 1;
}

protected void enough_rest()
{
        delete_temp("busy");
}

void reset()
{
	int t = time();

	if(!uptime)
		uptime = t;

	if(t - uptime >= 18000)
	{
		uptime = t;
		init_goods();
	}
}
