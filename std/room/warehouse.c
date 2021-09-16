// warehouse.c
// by Find.

#define IN_OUT_RATE     80/100
#define BUSI_SAVE_DIR	"/data/business/"
#define MAX_TRADE	2000000	// ÿ������ó�׶�Ϊ 1 ����������
#undef IN_TEST

#include <ansi.h>

inherit F_SAVE;
inherit ROOM;
#include <price.h>

class ware
{
	string name;	/* �������� */
	string id;	/* id */
	int value;	/* ��ǰ����(��λ������) */
	int o_value;	/* ��ʼ�۸� */
	int amount;	/* ��ǰ�������� */
	int o_amount;	/* ��ʼ���� */
	string unit;	/* ��λ */
}

nomask protected int valid_check();
nomask protected void init_wares();
nomask protected void get_shougou_amount(string arg,object me,class ware w);
nomask protected void get_paochu_amount(string arg,object me,class ware w);
nomask protected void output_list(string number,object who);
nomask protected string list_one_kind(string kind);
string query_save_file()
{ return sprintf("%s%s_bsave",BUSI_SAVE_DIR,domain_file(file_name(this_object())));}

mapping all_wares = ([]);
static int no_trade = 0;

int system_change = 0;	// ��ϵͳ�����á�change �ĵ�λΪ�ƽ�.

protected static int price_rate = 100;

// �ָ�����
// {
protected static int change_max = 10000; /* silver */
protected static string *changed_class = ({});
// }

nomask int query_price_rate()
{
	return price_rate;
}

nomask varargs protected void do_count(string name,int silver)
{
	int i,n,change;
	int origin;
	int rate;
	int cha;
	string domain,*kinds = keys(all_wares);

	n = sizeof(kinds);
	for(i=0;i<n;i++)
	{
		foreach(class ware oneitem in all_wares[kinds[i]])
		{
			origin += oneitem->o_value * oneitem->o_amount; /* silver�� */
			cha += (oneitem->o_amount -  oneitem->amount)*oneitem->o_value;
		}
	}

	rate = (cha+(system_change*100))/(origin/100);

	if(rate < -50)
		rate = -50;
	else if(rate > 50)
		rate = 50;

	if(stringp(name) && silver && (abs(silver) >= origin/100))
	{
		domain = to_chinese(domain_file(file_name(this_object())));
		change = abs((100+rate) - price_rate);

		if(change >= 5)
		{
			if(silver > 0)
				CHANNEL_D->do_channel( this_object(), "business",
					sprintf("��˵����������%s�����չ�%s��ʹ������۷��ǡ�\n",domain,name));
			else
				CHANNEL_D->do_channel( this_object(), "business",
					sprintf("��˵����������%s��������%s��ʹ������۷����»���\n",domain,name));
		}
		else if(change >= 1)
		{
			if(silver > 0)
				CHANNEL_D->do_channel( this_object(), "business",
					sprintf("��˵����������%s�����չ�%s��ʹ��������������\n",domain,name));
			else
				CHANNEL_D->do_channel( this_object(), "business",
					sprintf("��˵����������%s��������%s��ʹ���������½���\n",domain,name));
		}
	}

	price_rate = 100 + rate;
}

// �����Ӧ�ܵ����ϸ�ļ�顣
nomask protected int valid_check()
{

	string fname,domain;
	int idx;

	if(clonep())
		return 0;
	if(!sscanf((fname = file_name(this_object())),"/d/%*s"))
		error("��ջ����������������Ŀ¼�¡�\n");
	idx = strsrch(fname, "/", -1);
	if(fname[idx+1..] != "business")
		error("��ջ������ļ���������'business'��\n");

	sscanf(fname,"/d/%s/business",domain);

	if(member_array(domain,BUSINESS_D->query_valid_domains()) == -1)
		error("������ĿǰΪ��ó����������ͨ�����������롣\n");

	return 1;
}

nomask void setup()
{
	if(!valid_check())
		return;

	if(!restore())
		init_wares();
	else
		do_count();
	set("channel_id", "�̻�");
	set("no_clean_up",1);
	::setup();
}

nomask protected void init_wares()
{
	mapping wares = query("all_wares");
	mapping kinds = query("kind_rate");
	string *items,kind;
	int i,n;

	items =  filter_array(explode(PRICES, "\n") - ({ "" }), (: $1[0] != '#' :));

	if(!items || !(n=sizeof(items)))
		return;

	for(i=0;i<n;i++)
	{
		class ware item;
		string name,id,unit;
		int value;

		if(sscanf(items[i],"%s %s %s %d",name,id,unit,value) == 4)
		{
			item = new(class ware);
			item->name = name;
			item->id = id;
			item->unit = unit;
			item->o_value = value*(!undefinedp(kinds[id])?kinds[id]:100)/100;
			item->value = item->o_value;
			if(!undefinedp(wares[id]))
				item->o_amount = wares[id];
			else
				item->o_amount = 0;
			item->amount = item->o_amount;

			all_wares[kind] += ({ item });
		}

		else
		{
			kind = items[i];
			all_wares[kind] = ({});
		}
	}
}

nomask void init()
{
	if(clonep())
		return;
	add_action("do_shougou",({ "shou","shougou" }));
	add_action("do_chakan",({ "chakan","list" }));
	add_action("do_paochu",({ "pao","paochu" }));
	add_action("do_check",({ "check" }));
	add_action("do_fasong","fasong");
}

nomask int do_fasong()
{
	this_player()->fasong_ware();
	return 1;
}

nomask int do_check()
{
	int i,n;
	int cha;
	int origin;
	string *kinds = keys(all_wares);

	if(!wizardp(this_player()))
		return 0;

	n = sizeof(kinds);
	for(i=0;i<n;i++)
	{
		foreach(class ware oneitem in all_wares[kinds[i]])
		{
			origin += oneitem->o_value * oneitem->o_amount; /* silver�� */
			cha += (oneitem->o_amount -  oneitem->amount)*oneitem->o_value;
		}
	}

	printf("�˵س�ʼ�ܼ�ֵ��Ϊ��%d ������\n��ǰ��ֵ�%d ������\n��ǰ�����ָ��Ϊ���ٷ�֮ %d\nϵͳ����ֵ��%d\n",
		origin, cha, price_rate,system_change );
	return 1;
}

nomask int do_chakan(string arg)
{
	string *kinds = keys(all_wares);
	int i,n;

	if(!n = sizeof(all_wares))
		return notify_fail("Ŀǰû�п�ó�׵Ļ��\n");

	if(stringp(arg))
	{
		n = sizeof(kinds);
		for(i=0;i<n;i++)
			if(kinds[i] == arg)
			{
				output_list(sprintf("%d",(i+1)),this_player());
				return 1;
			}
		return notify_fail("��Ҫ�鿴�������ļ۸�\n");
	}
	else
	{
		int l,bk;
		string out;
		kinds += ({ "�������" });
		n = sizeof(kinds);
		for(i=0;i<n;i++)
			if(strlen(kinds[i]) > l)
				l = strlen(kinds[i]);
		out = "��ѡ����Ҫ�鿴�Ļ������\n";
		bk = to_int(50/(l+5));
		l++;
		for(i=0;i<n;i++)
			out += sprintf("%-3d%-"+(string)l+"s  %s",(i+1),kinds[i],(i%bk==(bk-1))||i==n-1?"\n":"" );
		write(out);
		input_to((: output_list :),this_player());
		return 1;
	}
}

nomask protected void output_list(string number,object who)
{
	int i,n;
	string output,*kinds = keys(all_wares);

	if(!objectp(who) || (number[0] == 'q'))
		return;

	if(!sscanf(number,"%d",n))
	{
		write("��ѡ����Ҫ�鿴�Ļ������\n");
		input_to((: output_list :),who);
		return;
	}

	n--;
	if( (n < 0 ) || (n > sizeof(kinds)) )
	{
		write("��ѡ����Ҫ�鿴�Ļ������\n");
		input_to((: output_list :),who);
		return;
	}

	if(n < sizeof(kinds))
	{
		output = sprintf("����ջĿǰ����ó�׵�%s����\n",kinds[n]);
		output += sprintf("%-8s%-20s %|8s%|6s%12s/%s\n","����","��������","����","��λ","������","�����(��λ������)");
		output += "-------------------------------------------------------------------------\n";
		output += list_one_kind(kinds[n]);
		write(output);
		return;
	}

	else
	{
		output = "����ջĿǰ���п���ó�׵Ļ��\n";
		output += sprintf("%-8s%-20s %|8s%|6s%12s/%s\n","����","��������","����","��λ","������","�����(��λ������)");
		output += "-------------------------------------------------------------------------\n";
		for(i=0;i<n;i++)
			output += list_one_kind(kinds[i]);
		who->start_more(output);
		return;
	}
}

nomask protected string list_one_kind(string kind)
{
	int i,n;
	string output = "";
	class ware *items;

	if(!stringp(kind) || undefinedp(all_wares[kind]))
		return "";

	items = all_wares[kind];

	n = sizeof(items);
	for(i=0;i<n;i++)
	{
		int sell;

		if(items[i]->amount <1)
			output += sprintf("%-8s%-20s%|14s    %8d/%-8d\n",
				i==0?kind:"",
				sprintf("%s(%s)",items[i]->name,items[i]->id),
				"[��  ��]",
				(sell = to_int(items[i]->value*price_rate/100)),
				sell*IN_OUT_RATE);
		else
			output += sprintf("%-8s%-20s%8d%|6s    %8d/%-8d\n",
				i==0?kind:"",
				sprintf("%s(%s)",items[i]->name,items[i]->id),
				items[i]->amount,items[i]->unit,
				(sell = to_int(items[i]->value*price_rate/100)),
				sell*IN_OUT_RATE);
	}
	return output;
}

nomask protected int do_shougou(string arg)
{
	class ware item;
	int n,i,num;
	string *kinds = keys(all_wares);

	if(no_trade)
		return notify_fail("���������̿⣬���һ��������\n");

#ifdef IN_TEST
	if(!wizardp(this_player()))
		return notify_fail("�����ڼ䲻������Ҳ���ó�ס�\n");
#else
	if(wizardp(this_player()))
		return notify_fail("��ʽ�����ڼ䲻������ʦ����ó�ס�\n");
#endif

	if( !stringp(arg) || (arg == "") )
		return notify_fail("��Ҫ�չ�ʲô���\n");

	if(sscanf(arg,"%d %s",num,arg) == 2)
		if(num < 1)
			return notify_fail("�չ���������Ϊ 1��");

	n = sizeof(kinds);
	for(i=0;i<n;i++)
	{
		foreach(class ware oneitem in all_wares[kinds[i]])
			if(oneitem->id == arg)
			{
				item = oneitem;
				break;
			}
	}

	if(!item)
		return notify_fail("��Ҫ�չ�ʲô���\n");

	if(item->amount < 1)
		return notify_fail(sprintf("�������%s�Ѿ��ϻ��ˣ�����һ��ʱ�����������ɡ�\n",
			item->name));

	if(num > 0)
	{
		get_shougou_amount(sprintf("%d",num),this_player(),item);
		return 1;
	}

	write(sprintf("��Ҫ�չ�����%s%s��",item->unit,item->name));
	input_to((: get_shougou_amount :),this_player(),item);
	return 1;
}

nomask protected void get_shougou_amount(string arg,object me,class ware w)
{
	int n,value,one;
	string domain;
	//object ob;

	if(!objectp(me) || (arg[0] == 'q'))
		return;

	if(!sscanf(arg,"%d",n))
	{
		write(sprintf("��Ҫ�չ�����%s%s��",w->unit,w->name));
		input_to((: get_shougou_amount :),me,w);
		return;
	}

	if(n < 1)
	{
		write("�չ���������Ϊ 1��");
		return;
	}

	if( n > w->amount )
	{
		write(sprintf("�Բ��𣬱���Ŀǰֻ�� %d %s%s������һ��ʱ�����������ɡ�\n",
			w->amount,w->unit,w->name));
		return;
	}

	one = w->value*price_rate/100;
	if(n > (MAX_TRADE/one))
	{
		write(sprintf("�Բ��𣬱����̻�涨ÿ��ó�׶�ܳ���%s��������\n",
			chinese_number(MAX_TRADE)));
		return;
	}

	value = n*one;

#ifndef IN_TEST
	if(!pay_from_bank(me,value*100))
	{
		write(sprintf("�չ� %d %s%s �����ʽ� %d �����ӣ�������д�����\n",
			n,w->unit,w->name,value));
		return;
	}
#endif

	if(!me->buy_in(w->name,w->id,w->unit,n,one))
	{
		write("����չ���Ϊû�гɹ�����Ǯ��ʧ����������������ʦͨ����\n");
		log_file("warehouse",sprintf("%s(%s) �չ�%s %d %sʧ�ܣ���ʧ���� %d ��������%s\n",
			me->name(),me->query("id"),w->name,n,w->unit,value,ctime(time()) ));
		return;
	}

	domain = domain_file(base_name(this_object()));

	write(sprintf("\n���%s��ջ�չ��� %d %s%s��\n��ջ���˷�������һ�������ϼ���������\n\n",
		to_chinese(domain),n,w->unit,w->name));

	w->amount -= n;

	do_count(w->name,value);
	save();

#ifndef IN_TEST
	log_file("warehouse",sprintf("%s(%s)��%s�Ե���%d�������չ�%s%d%s��%s\n",
		me->name(),me->query("id"),to_chinese(domain),one,w->name,n,w->unit,ctime(time()) ));
#endif

	return;
}

nomask protected int do_paochu(string arg)
{
	class ware item;
	int n,i,num;
	string *kinds = keys(all_wares);

	if(no_trade)
		return notify_fail("���������̿⣬���һ��������\n");

#ifdef IN_TEST
	if(!wizardp(this_player()))
		return notify_fail("�����ڼ䲻������Ҳ���ó�ס�\n");
#else
	if(wizardp(this_player()))
		return notify_fail("��ʽ�����ڼ䲻������ʦ����ó�ס�\n");
#endif

	if( !stringp(arg) || (arg == "") )
		return notify_fail("��Ҫ�׳�ʲô���\n");

	if(sscanf(arg,"%d %s",num,arg) == 2)
		if(num < 1)
			return notify_fail("������������Ϊ 1��");

	n = sizeof(kinds);
	for(i=0;i<n;i++)
	{
		foreach(class ware oneitem in all_wares[kinds[i]])
			if(oneitem->id == arg)
			{
				item = oneitem;
				break;
			}
	}

	if(!item)
		return notify_fail("��Ҫ�׳�ʲô���\n");

	if(num > 0)
	{
		get_paochu_amount(sprintf("%d",num),this_player(),item);
		return 1;
	}

	write(sprintf("��Ҫ�׳�����%s%s��",item->unit,item->name));
	input_to((: get_paochu_amount :),this_player(),item);
	return 1;
}

nomask protected void get_paochu_amount(string arg,object me,class ware w)
{
	int n,value,r,one;
	string domain;

	if(!objectp(me) || (arg[0] == 'q'))
		return;

	if(!sscanf(arg,"%d",n))
	{
		write(sprintf("��Ҫ�׳�����%s%s��",w->unit,w->name));
		input_to((: get_paochu_amount :),me,w);
		return;
	}


	if(n < 1)
	{
		write("������������Ϊ 1��");
		return;
	}

	one = w->value*price_rate/100*IN_OUT_RATE;

	if(n > (MAX_TRADE/one))
	{
		write(sprintf("�Բ��𣬱����̻�涨ÿ��ó�׶�ܳ���%s��������\n",
			chinese_number(MAX_TRADE)));
		return;
	}

	if(!(r = me->sell_out(w->id,n,one)))
	{
		write(sprintf("���ڱ���û��%s��\n",w->name));
		return;
	}

	if(r == -1)
	{
		write(sprintf("���ڱ���û����ô��������%s��\n",w->name));
		return;
	}

	domain = domain_file(base_name(this_object()));
	value = n*one;

#ifndef IN_TEST
	if( !save_to_bank(me,value*100) )
	{
		tell_object(me,"��Ļ���ȫ����ʧ�ˣ�������ʦ���档\n");
		log_file("warehouse",sprintf("%s(%s)�������д���������Ʒʱ��ʧ�� %d �����ӡ�%s\n",
			me->name(),me->query("id"),value,ctime(time()) ));
		return 0;
	}
#endif

	write(sprintf("���ڱ��������� %d %s%s��\nӦ�û��� %d �������Ѵ������������˻���\n",
		n,w->unit,w->name,value));

	w->amount += n;
	do_count(w->name,-value);
	save();

#ifndef IN_TEST
	log_file("warehouse",sprintf("%s(%s)��%s�Ե���%d�������׳�%s%d%s��%s\n",
		me->name(),me->query("id"),to_chinese(domain),one,w->name,n,w->unit,ctime(time()) ));
#endif
}

// ϵͳ���Ƶ�����䶯
nomask void random_change(int sum)
{

	if(!previous_object()
	|| (geteuid(previous_object()) != ROOT_UID))
		return;

	if(!sum)
		return;

	no_trade = 1;	// �䶯�ڼ��ֹó��

	system_change += sum;
	do_count("��Ʒ",sum*100);
	save();

	no_trade = 0;
}

// ϵͳ���ƵĻָ�
nomask void random_recover()
{
	string *cs, current_cs;
	int max,i,n,flag;
	class ware *items;

	if(!previous_object()
	|| (geteuid(previous_object()) != ROOT_UID))
		return;

	no_trade = 1;	// �䶯�ڼ��ֹó��

	if(sizeof(changed_class) >= sizeof(cs = keys(all_wares)))
		changed_class = ({});

	for(i=0;i<sizeof(cs);i++)
		if(member_array(cs[i],changed_class) == -1)
		{ current_cs = cs[i]; break; }

	changed_class += ({ current_cs });

	items = all_wares[current_cs];
	n = sizeof(items);

	max = change_max;

	foreach(class ware oneitem in all_wares[current_cs])
	{
		int diff,ch;

		if(max < 50)
			break;
		if(max < oneitem->o_value)
			continue;

		if(!diff = oneitem->o_amount - oneitem->amount)
			continue;
		ch = to_int(max/oneitem->o_value);
		if(abs(diff) < ch)
                        ch = abs(diff);
		max -= ch * oneitem->o_value;
		if(diff < 0)
		{
			oneitem->amount -= ch;
			flag = 1;
		}
		else
			oneitem->amount += ch;
		log_file("business",sprintf("%s: �ָ����� %s %s %d %s. %s\n",
			domain_file(base_name(this_object())),
			oneitem->id,
			flag?"����":"����",
			ch,
			oneitem->unit,
			ctime(time()),
			));
	}

	do_count();
	save();

	no_trade = 0;
}
