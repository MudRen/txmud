// ride_seller.c
// by Find.

#include <ansi.h>
inherit NPC;

class goods {
	string name;
	string id;
	string file;
	string unit;
	int amount;
	int value;
}

private class goods *all_goods = ({});

private void init_goods();
int add_one_good(string file,int sum);
private int ride_value(object ride);

void setup()
{
	all_goods = ({});
	init_goods();
	set_skill("riding",100);
	::setup();
}

void init_goods()
{
	mapping items = this_object()->query("vendor_goods");
	string name;
	int sum;

	if(!items || !mapp(items) || !sizeof(items))
		return;

	foreach(name,sum in items)
		add_one_good(name,sum);
}

int add_one_good(string file,int sum)
{
	object ob;
	class goods item;
	int i,n;

	if(!stringp(file) || !intp(sum))
		return 0;

	ob = new(file);
	if(!ob)
		return 0;

	if(n = sizeof(all_goods))
		for(i=0;i<n;i++)
			if(all_goods[i]->file == file)
			{
				all_goods[i]->amount++;
				destruct(ob);
				return 1;
			}

	item = new(class goods);

	item->name = ob->query("name");
	item->id = ob->query("id");
	item->file = file;
	item->unit = ob->query("unit");
	item->amount = sum<1?1:sum;
	item->value = to_int( ride_value(ob)*price_ratio(environment())/100 );

	all_goods += ({ item });
	destruct(ob);
	return 1;
}

void init()
{
	add_action("do_buy", ({ "mai","buy" }) );
	add_action("do_list", "list");
	add_action("do_sell", "sell");
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

	if( stringp(str) && (str != "") && !id(str) )
		return 0;

	if (!sizeof(all_goods))
	{
		write(sprintf("%s˵���������������ã�û�м���Ͱѷ����������ˣ������´�����˵�ɡ���\n",query("name")));
		return 1;
	}

	//output = sprintf("�������%s����������Ʒ��\n", query("name"));
	output = sprintf(" %-26s%-10s%-10s\n","    ��  ��","  ����","   ��  ��");
	output += "----------------------------------------------\n";

	foreach(item in all_goods)
	{
		if(!(item->amount))
			continue;
		++flag;
		output += sprintf(" %-26s%-10s%s\n",
			sprintf("%s(%s)",item->name,item->id),
			item->amount >= 1?
			sprintf("%-3d%s",item->amount,item->unit):"��Դ����",
			chinese_value(item->value));
	}

	if(!flag)
	{
		write(sprintf("%s˵���������������ã�û�м���Ͱѷ����������ˣ������´�����˵�ɡ���\n",query("name")));
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
	int sum,i,n, rtn;

	if( (me = this_player())->is_busy() )
	{
		write(BUSY_MESSAGE);
		return 1;
	}

	if(query("no_sell_day"))
		return 0;

        if(!arg || arg == "")
	{
                write("������ʲô��\n");
		return 1;
	}

	// ����ͬ������һ������ dealer �������
	if(sscanf(arg,"%s from %s",arg,who) == 2)
	{
		if(!id(who))
			return 0;
	}

	// һ������ͬһ��Ʒ��
	if(sscanf(arg,"%d %s",sum,arg) == 2)
	{
		if(sum < 1)
		{
			write("����ÿ��������������һ����λ��\n");
			return 1;
		}
	}
	else
		sum = 1;

	if(query_temp("busy"))
	{
		write("�����һ�£���������Ͼ�æ���ˡ�����������\n");
		return 1;
	}

	n = sizeof(all_goods);
	if(!n)
	{
		write(sprintf("%s˵���������������ã�û�м���Ͱѷ����������ˣ������´�����˵�ɡ���\n",query("name")));
		return 1;
	}

	for(i=0;i<n;i++)
	{
		if( (all_goods[i]->file)->id(arg) )
		{
			if(!(all_goods[i]->amount))
			{
				command(sprintf("say �Բ�����η�����%s�������ˣ����´���һ����Ū��%s��",
					all_goods[i]->name,all_goods[i]->unit));
				return 1;
			}

			if( (all_goods[i]->amount > 0) && (sum > all_goods[i]->amount) )
				sum = all_goods[i]->amount;
			break;
		}
	}

	if(i >= n)
	{
		write("�������������\n");
		return 1;
	}

	switch( rtn = player_pay(me, (sum * all_goods[i]->value)) )
	{
        case 0:
		write(sprintf("�����ϵ�Ǯ������%s%s%s�ġ�\n",chinese_number(sum),
			all_goods[i]->unit,all_goods[i]->name));
                return 1;
        case 2:
		destruct(ob);
                write("������Ǯ�����ˣ���Ʊ��û���ҵÿ���\n");
		return 1;
        default:
                set_temp("busy", 1);

		for(n=0;n<sum;n++)
		{
			ob = new(all_goods[i]->file);
			if(rtn == 3)
				ob->set_credit_point_flag();
			ob->move(environment());
		}
		write(sprintf("%s�߽���ǣ�������ǣ����%s%s%s��\n", 
		name(),chinese_number(sum),
                all_goods[i]->unit,all_goods[i]->name));
		message_vision(sprintf("$N��$n˵���������������%s�������ϰɡ���\n",
			all_goods[i]->name),this_object(),me);
        }

	all_goods[i]->amount -= sum;
	remove_call_out("enough_rest");
	call_out("enough_rest", 1);
	return 1;
}

void enough_rest()
{
        delete_temp("busy");
}

int do_sell(string str)
{
	object ob,who,me = this_player();
	int value;

	if(!stringp(str) || str == "")
		return notify_fail("��Ҫ��ʲô���\n");
	ob = present(str,environment());
	if(!ob)
		return notify_fail("��Ҫ��ʲô���\n");

	if(!ob->query("ride"))
		return notify_fail(sprintf("%s˵�������۾��Ƿ���ģ��������Ĳ�����Ȥ����\n",name()));

	if(objectp(who = ob->query_temp("have_been_rided")) && (who != me) )
		return notify_fail(sprintf("%s��%s���������ô�����ء�",ob->name(),who->name()));

	value = to_int( ride_value(ob)*price_ratio(environment())/125 );
	if(value < 100)
		value = 100;
	else
		value = to_int(value/100)*100;

	add_one_good(base_name(ob),1);

	write(sprintf("���%s����������%s��\n",ob->name(),chinese_value(value)));
	pay_player(me, value, ob->query_credit_point_flag()?1:0);

	if(who)
		message_vision(sprintf("$N�߹���һ�Ѱ�$n��%s������������\n",ob->name()),this_object(),who);
	message_vision("$N��$nǣ���ˡ�\n",this_object(),ob);
	destruct(ob);
	return 1;
}

nomask int accept_object(object who, object ob)
{
	int value,n;

	if(!is_money(ob) || !who || !userp(who))
		return 0;

	value = ob->value();
	n = who->query(sprintf("pay_riding/%s",replace_string(base_name(this_object()),"/","_")));
	n += value;
	who->set(sprintf("pay_riding/%s",replace_string(base_name(this_object()),"/","_")),n);
	return 1;
}

nomask int prevent_learn(object me, string skill)
{
	int paid,value;

	if(skill != "riding")
		return 0;

	paid = me->query(sprintf("pay_riding/%s",replace_string(base_name(this_object()),"/","_")));

	value = me->query_skill("riding",1);

	if(!value)
		value = 1;

	value++;
	if(paid < value*100)
		return notify_fail(sprintf(CYN"%s˵������Ҫѧϰ��������Ҫ������%s�����ӡ���\n"NOR,
			name(),chinese_number(value)));

	paid -= value*100;
	me->set(sprintf("pay_riding/%s",replace_string(base_name(this_object()),"/","_")),paid);
	return 1;
}

int recognize_apprentice(object ob)
{
	if(objectp(ob) && userp(ob))
		return 1;
	else
		return 0;
}

/* ȡ����ļ�ֵ */
private int ride_value(object ride)
{
	int value,level;
	int *price = ({5000,5500,6000,8000,10000,12000,18000,22000,40000,50000});

	if(!objectp(ride) || !ride->is_character() || !ride->query("ride"))
		return 0;

	if(!undefinedp(ride->query("value")))
		value = ride->query("value");
	else
	{
		level = ride->query("ride_level");
		if(level > 10)
			level = 10;
		if(level < 1)
			level = 1;
		value = price[level-1];
	}
	return value;
}
