// /feature/business.c
// buy Find.

class business
{
	string name;	/* ���� */
	string id;	/* ID */
	string unit;	/* ��λ */
	int amount;	/* ���� */
	int buy;	/* �չ����� */
	string from;	/* �չ��ص� */
	string now;	/* ���ﵱǰ���ڵ� */
	string to;	/* ���ﵱǰ����ǰ���ĵص� */
	int time;	/* Ԥ�Ƶ����ʱ�� */
}

int trade_amount = 0; /* �����й��Ľ��״��� */
int profit = 0;	/* ��׬ȡ������(silver) */

private class business *all = ({});

private void get_fasong_number(string num,object me,class business *have);
private void get_fasong_where(string num,object me,string *ds,class business ware);

// ����ֵ 0 �����ڱ���û�����ֻ���, -1 ��������.
nomask int sell_out(string id,int amount,int value)
{
	string domain;
	int n,i,have;

	if(!previous_object()
	|| !sscanf(file_name(previous_object()),"/d/%s/business",domain))
		return 0;

	if(member_array(domain,BUSINESS_D->query_valid_domains()) == -1)
		return 0;

	if(!all || !(n=sizeof(all)))
		return 0;

	for(i=0;i<n;i++)
		if((all[i]->now == domain) && (all[i]->id == id))
			have += all[i]->amount;

	if( !have )
		return 0;

	if(have < amount)
		return -1;

	for(i=0;i<n;i++)
	{
		if(!amount)
			break;

		if(all[i]->now != domain || all[i]->id != id)
			continue;
		if(all[i]->amount <= amount)
		{
			profit += (value - all[i]->buy)*amount;
			amount -= all[i]->amount;
			all[i] = 0;
		}

		else
		{
			profit += (value - all[i]->buy)*amount;
			all[i]->amount -= amount;
			break;
		}
	}

	all -= ({ 0 });
	trade_amount++;
	this_object()->save();
	return 1;
}

nomask int buy_in(string name,string id,string unit,int amount,int value)
{
	string domain;
	class business item;

	if(!previous_object()
	|| !sscanf(file_name(previous_object()),"/d/%s/business",domain))
		return 0;

	if(member_array(domain,BUSINESS_D->query_valid_domains()) == -1)
		return 0;

	if(!stringp(name)
	|| !stringp(id)
	|| !stringp(unit)
	|| amount <= 0
	|| value <= 0)
		return 0;

	item = new(class business);

	item->name = name;
	item->id = id;
	item->unit = unit;
	item->amount = amount;
	item->buy = value;
	item->from = domain;
	item->now = domain;

	if(!all)
		all = ({});
	all += ({ item });
	this_object()->save();
	return 1;
}

nomask string query_business_status()
{
	string output = "\n";
	int n;

	if(!n  = sizeof(all))
		output += "��Ŀǰ��ͷû���κλ��\n";
	else
	{
		output += "��Ŀǰ��ͷ�Ļ����У�\n";
		output += sprintf("%-22s%-12s%-12s%-12s%s\n",
			"��������","��������","�չ��ص�","�չ��۸�","״̬");
		output += "----------------------------------------------------------------------\n";
		for(int i=0;i<n;i++)
		{
			string status;

			if(!all[i]->to)
				status = sprintf("������%s",to_chinese(all[i]->now));
			else if(time() <=  all[i]->time)
				status = sprintf("��������%s��;��",to_chinese(all[i]->to));
			else
				status = sprintf("���˵�%s",to_chinese(all[i]->to));

			output += sprintf("%-22s%-12s%-12s%-12s%s\n",
				sprintf("%s(%s)",all[i]->name,all[i]->id),
				sprintf("%d%s",all[i]->amount,all[i]->unit),
				to_chinese(all[i]->from),
				sprintf("%d��/%s",all[i]->buy,all[i]->unit),
				status
				);
		}
	}

	if(!trade_amount)
		output += "\n�㻹û�д��¹�ó�׻��\n\n";
	else
		output += sprintf("\n�㹲���й�%s��ó�ס�\n\n",chinese_number(trade_amount));

	if(!profit)
		output += "�㻹û��ͨ��ó��׬ȡ������\n\n";
	else if(profit < 0)
		output += sprintf("���ڴ���ó���й������� %d ��������\n\n",abs(profit));
	else
		output += sprintf("���ڴ���ó���й�׬ȡ�� %d ��������\n\n",profit);

	return output;
}

nomask void fasong_ware()
{
	class business *have = ({});
	int i,n;
	string out,from;

	if(!previous_object()
	|| !sscanf(file_name(previous_object()),"/d/%s/business",from))
		return;

	if(member_array(from,BUSINESS_D->query_valid_domains()) == -1)
		return;

	if( !(n = sizeof(all)) )
	{
		write("����������û���κλ��\n");
		return;
	}

	for(i=0;i<sizeof(all);i++)
		if(all[i]->now == from)
			have += ({ all[i] });

	if( !(n = sizeof(have)) )
	{
		write(sprintf("����%sû���κλ��\n",to_chinese(from)));
		return;
	}

	if(n > 1)
	{
		out = sprintf("��Ŀǰ��%s����%s�ʻ��\n",to_chinese(from),chinese_number(n));
		for(i=0;i<n;i++)
			out += sprintf("%2d. %s %d %s��\n",(i+1),
				have[i]->name,have[i]->amount,have[i]->unit);
		out += "��ѡ����Ҫ���͵Ļ��\n";
		write(out);
		input_to( (: get_fasong_number :),this_player(),have );
		return;
	}

	get_fasong_number(sprintf("%d",1),this_player(),have);
}

private void get_fasong_number(string num,object me,class business *have)
{
	int n,l,bk,s,i;
	string *v_domains,*ds,out;

	if(!objectp(me) || (num[0] == 'q'))
		return;

	if(!sscanf(num,"%d",n))
	{
		write("��ѡ����Ҫ���͵Ļ��\n");
		input_to((: get_fasong_number :),me,have);
		return;
	}

	n--;
	if( (n < 0 ) || (n > sizeof(have)) )
	{
		write("��ѡ����Ҫ���͵Ļ��\n");
		input_to((: get_fasong_number :),me,have);
		return;
	}

	ds = BUSINESS_D->query_valid_domains()-({have[n]->now});
	v_domains = map_array(ds,(: to_chinese($1) :));

	s = sizeof(v_domains);

	for(i=0;i<s;i++)
		if(strlen(v_domains[i]) > l)
			l = strlen(v_domains[i]);

	out = "Ŀǰ���Է����ĵص��У�\n";
	bk = to_int(50/(l+5));
	l++;
	for(i=0;i<s;i++)
		out += sprintf("%-3d%-"+(string)l+"s  %s",(i+1),v_domains[i],(i%bk==(bk-1))||i==n-1?"\n":"" );

	out += "��ѡ����Ҫ�����ĵص㣺\n";
	write(out);
	input_to((: get_fasong_where :),me,ds,have[n]);
}

private void get_fasong_where(string num,object me,string *ds,class business ware)
{
	int n,time,fs_fee,plus;

	if(!objectp(me) || (num[0] == 'q'))
		return;

	if(!sscanf(num,"%d",n))
	{
		write("��ѡ����Ҫ�����ĵص㣺\n");
		input_to((: get_fasong_where :),me,ds,ware);
		return;
	}

	n--;
	if( (n < 0 ) || (n >= sizeof(ds)) )
	{
		write("��ѡ����Ҫ�����ĵص㣺\n");
		input_to((: get_fasong_where :),me,ds,ware);
		return;
	}

	time = BUSINESS_D->count_fasong_time(ware->now,ds[n],ware->buy*ware->amount/100);
	if(!time)
	{
		write("����ʧ�ܣ�������\n");
		return;
	}

	fs_fee = ware->buy*ware->amount/100;
	plus = time/10;
	if(plus > 1)
		fs_fee *= plus;

	if(fs_fee < 20) // 1000 ��������ÿ���˷�����Ϊ 20 silver��
		fs_fee = 20;

	if(!pay_from_bank(this_object(),fs_fee*100))
	{
		write(sprintf("���� %d %s%sȥ%s������˷� %d �������������д�����\n",
			ware->amount,ware->unit,ware->name,to_chinese(ds[n]),fs_fee ));
		return;
	}

	ware->now = 0;
	ware->to = ds[n];
	ware->time = time()+time*1440;
	this_object()->save();
	write(sprintf("%s�ѷ���%s,·�ϴ�Լ��Ҫ%s�졣\n",
		ware->name,to_chinese(ds[n]),chinese_number(time)));
}

int delete_all_wares()
{
	all = ({});
	this_object()->save();
	return 1;
}

private void random_happen(class business w)
{
	string reason,cl;
	int n,loss;

	// ��ʧ�� 1-5%��30% �����Է�����ʧ��

	if(random(100) >= 30)
		return;

	n = random(100);

	if(n < 10)	// 5%
		loss = w->amount*5/100;
	else if(n < 20)
		loss = w->amount*4/100;
	else if(n < 30)
		loss = w->amount*3/100;
	else if(n < 40)
		loss = w->amount*2/100;
	else if(n < 50)
		loss = w->amount*1/100;
	else
		return;

	if(!loss)
		return;

	cl = BUSINESS_D->query_ware_class(w->id);
	if(!cl)
		return;

	if( (cl == "����") || (cl == "���ز�") )
		reason = "�õ�";
	else
	{
		if(random(2))
			reason = "��͵";
		else
			reason = "����";
	}

	w->amount -= loss;

	tell_object(this_object(),sprintf("���%s������;��%s�� %d %s��\n",
		w->name,reason,loss,w->unit ));
}

nomask void update_all_wares()
{
	int n,i,t,flag = 0;

	if(!n = sizeof(all))
		return;

	t = time();

	for(i=0;i<n;i++)
	{
		if(!all[i]->to)
			continue;
		if( t <= all[i]->time )
			continue;
		random_happen(all[i]);
		all[i]->now = all[i]->to;
		all[i]->to = 0;
		all[i]->time = 0;
		flag++;
	}

	if(flag)
		this_object()->save();

}
