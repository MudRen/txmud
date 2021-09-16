// bank.c
// Modified by Find.

#define MAX	2000000000	/* long max 2^32 ���Թ涨���ܳ���21�� */
#define THOUSAND_CASH		/* define this for enable 'thousand-cash' */
#define IMPAWN_RATE	80/100	/* ��Ѻ���� */
#undef DAY_NIGHT

#include <ansi.h>

inherit ROOM;

float accrual = 0.01;	/*ÿ�µĵ�Ѻ��������*/
nomask int check_money(object money,object me);
nomask int save_money(string arg,object me);
private void go_on_pawn(string arg,object me,object home);
private void go_impawn(string arg,object me,string *domains);
private void go_redeem(string arg,object me,string *domains);

void init()
{
	add_action("do_convert", ({ "huan", "convert" }));
        add_action("do_save",({"cunqian","cun"}));
        add_action("do_seek",({"chazhang","cha"}));
        add_action("do_get",({"quqian","qu"}));
	add_action("do_paijia","paijia");
	add_action("do_impawn",({ "impawn","diya" }));
	add_action("do_redeem",({ "redeem","shuhui"}));
	add_action("do_zhuanzhang",({ "zhuan","zhuanzhang" }));
}

nomask int do_seek()
{
	mapping amount;
	int gold,silver,coin;
	object me=this_player();
	string msg;


#ifdef DAY_NIGHT
	string day_night;
	int time;
	if ( sscanf( NATURE_D->day_or_night(),"%s %d",day_night,time) )
	{
		if(day_night == "night")
		{
			write( (time > 240) ? "��ô����죬��ׯ�Ѿ������ˣ������������ɡ�\n"
				: ( (time <= 60) ? "���Ͼ�Ҫ�����ˣ����һ�°ɡ�\n"
				: "��ׯ��û�п��ţ��������������ɡ�\n" ) );
			return 1;
		}
	}
#endif

	if(me->is_busy())
		return notify_fail(BUSY_MESSAGE);

	amount=me->query("save_in_bank");
	if(!amount)
        {
                write("��û�д��\n");
                return 1;
        }

	if(undefinedp(amount["gold"]))
		gold = 0;
	else
		gold = (int)amount["gold"];

	if(undefinedp(amount["silver"]))
		silver = 0;
	else
		silver = (int)amount["silver"];

	if(undefinedp(amount["coin"]))
		coin = 0;
	else
		coin = (int)amount["coin"];

	if(!gold && !silver && !coin)
	{
		write("��û�д��\n");
                return 1;
	}

        msg="����У�\n"
		+((gold)?chinese_number(gold)+"��"+HIY "�ƽ�\n" NOR:"")
		+((silver)?chinese_number(silver)+"��������\n":"")
		+((coin)?chinese_number(coin)+"��"+YEL "ͭǮ��\n" NOR:"");
        write(msg);
        return 1;
}

nomask int do_save(string arg)
{
	object me = this_player();
	object g_ob,s_ob,c_ob,t_ob;

#ifdef DAY_NIGHT
	string day_night;
	int time;
        if ( sscanf( NATURE_D->day_or_night(),"%s %d",day_night,time) )
        {
                if(day_night == "night")
                {
                        write( (time > 240) ? "��ô����죬��ׯ�Ѿ������ˣ������������ɡ�\n"
                                : ( (time <= 60) ? "���Ͼ�Ҫ�����ˣ����һ�°ɡ�\n"
                                : "��ׯ��û�п��ţ��������������ɡ�\n" ) );
                        return 1;
                }
        }
#endif
        if( me->is_busy() )
                return notify_fail(BUSY_MESSAGE);

	if(!arg) 
		return notify_fail("ָ���ʽ��cunqian <����> <��������> \n");

	if(arg == "money")
	{
		g_ob = present("gold_money", me);
		s_ob = present("silver_money", me);
		c_ob = present("coin_money", me);
#ifdef THOUSAND_CASH
		t_ob = present("thousand-cash_money", me);
#endif
		if(g_ob)
			save_money("gold",me);
		if(s_ob)
			save_money("silver",me);
		if(c_ob)
			save_money("coin",me);
		if(t_ob)
			save_money("thousand-cash",me);
		return 1;
	}

	else
		return save_money(arg,me);
}

nomask int save_money(string arg,object me)
{
        string from;
        int amount,flag=0;
	mapping base;
        object money;

	if( sscanf(arg, "%d %s", amount, from) == 2 )
	{
		if(amount <1)
			return notify_fail("��������1\n");
	}

	else
	{
		amount = 0;
		from = arg;
	}

	if(from != "gold"
	&& from != "silver"
	&& from != "coin"
#ifdef THOUSAND_CASH
	&& from != "thousand-cash"
#endif
	)
		return notify_fail("ָ���ʽ��cunqian <����> <��������> \n");

        money=present(from+ "_money", me);

        if( !money )
                return notify_fail("������û�����ֻ��ҡ�\n");

	if(!check_money(money,me))
		return 1;

	if(amount == 0)
		amount = (int)money->query_amount();

        else if( (int)money->query_amount() < amount )
                return notify_fail("������û����ô��" + money->query("name") + "��\n");

        base = me->query("save_in_bank");

#ifdef THOUSAND_CASH
	if(from == "thousand-cash")
	{
		flag = 1;
		from = "silver";
		amount *= 1000;
	}
#endif

	if(!base || !base[from])
		me->set("save_in_bank/"+from,amount);
	else if( amount > (MAX - base[from]) )
			return notify_fail("��治����ô��"+money->query("name")+"��\n");
	else
                me->add("save_in_bank/"+from,amount);

	tell_object(me,sprintf("�㽫%s%s%s������С�\n",
		chinese_number(flag?amount/1000:amount),
		money->query("base_unit"),
		money->query("name")));
        money->add_amount((flag)?-1*amount/1000:-1*amount);
        me->start_busy(1);
	me->save();
        return 1;
}

nomask int do_get(string arg)
{
        string from;
        int amount;
	mapping base;
        object money,me = this_player();

#ifdef DAY_NIGHT
        string day_night;
        int time;
        if ( sscanf( NATURE_D->day_or_night(),"%s %d",day_night,time) )
        {
                if(day_night == "night")
                {
                        write( (time > 240) ? "��ô����죬��ׯ�Ѿ������ˣ������������ɡ�\n"
                                : ( (time <= 60) ? "���Ͼ�Ҫ�����ˣ����һ�°ɡ�\n"
                                : "��ׯ��û�п��ţ��������������ɡ�\n" ) );
                        return 1;
                }
        }
#endif

        if( me->is_busy() )
                return notify_fail(BUSY_MESSAGE);

        if( !arg || sscanf(arg, "%d %s", amount, from)!=2 )
		return notify_fail("ָ���ʽ��quqian<����> <��������> \n");

        if(from != "coin"
	&& from != "silver"
	&& from != "gold"
#ifdef THOUSAND_CASH
	&& from != "thousand-cash"
#endif
	)
                return notify_fail("ָ���ʽ��quqian<����> <��������> \n");

        if (amount<1)
                return notify_fail("��������1\n");

	if(me->query_temp("be_in_sale_meeting_chu"))
		return notify_fail("�����ڲμ��������ľ�����ʱ���ܶ������д�\n");

        base=me->query("save_in_bank");

	if(!base || !mapp(base))
		return notify_fail("��û���κδ�\n");

	if(undefinedp(base[((from == "thousand-cash")?"silver":from)])
	|| !base[((from == "thousand-cash")?"silver":from)])
		return notify_fail("��������û�������ֻ��ҡ�\n");

	if(base[((from == "thousand-cash")?"silver":from)] <
		((from == "thousand-cash")?amount*1000:amount) )
                return notify_fail("��û�д���ô��Ǯ\n");

        if(!money = new("/obj/money/" + from))
                return notify_fail("ָ���ʽ��quqian<����> <��������> \n");

        money->set_amount(amount);
	if(!money->move(this_player()))
	{
		destruct(money);
		return notify_fail("���ò�����ô�ණ��.\n");
	}

	tell_object(me,"���������ȡ��"+chinese_number(amount)+money->query("base_unit")
		+money->query("name")+"��\n");

#ifdef THOUSAND_CASH
	if(from == "thousand-cash")
	{
		from = "silver";
		amount *= 1000;
	}
#endif

        me->add("save_in_bank/"+from,-amount);
        me->start_busy(1);
	me->save();
        return 1;
}

nomask int do_convert(string arg)
{
	string from, to,from_name;
	int amount,sum,charge;
	float bv1, bv2;
	object from_ob, to_ob, me=this_player(),charge_ob;

#ifdef DAY_NIGHT
        string day_night;
        int time;
        if ( sscanf( NATURE_D->day_or_night(),"%s %d",day_night,time) )
        {
                if(day_night == "night")
                {
                        write( (time > 240) ? "��ô����죬��ׯ�Ѿ������ˣ������������ɡ�\n"
                                : ( (time <= 60) ? "���Ͼ�Ҫ�����ˣ����һ�°ɡ�\n"
                                : "��ׯ��û�п��ţ��������������ɡ�\n" ) );
                        return 1;
                }
        }
#endif

	if( me->is_busy() )
                return notify_fail(BUSY_MESSAGE);

	if( !arg )
		return notify_fail("ָ���ʽ��huan <����> <��������> to <��������>\n");

	if( sscanf(arg, "%d %s to %s",amount, from, to) == 3 )
	{
		if(amount < 1)
			return notify_fail("�һ�����һ������Ҫ�һ�һ����\n");
	}

	else if(sscanf(arg, "%s to %s",from, to) == 2)
		amount = 0;
	else
		return notify_fail("ָ���ʽ��huan <����> <��������> to <��������>\n");

        if(from != "coin"
	&& from != "silver"
	&& from != "gold"
#ifdef THOUSAND_CASH
	&& from != "thousand-cash"
#endif
	)
		return notify_fail("ָ���ʽ��huan <����> <��������> to <��������>\n");

	if(to != "coin"
	&& to != "silver"
	&& to != "gold"
#ifdef THOUSAND_CASH
	&& to != "thousand-cash"
#endif
	)
		return notify_fail("ָ���ʽ��huan <����> <��������> to <��������>\n");

	from_ob = present(from + "_money", me);

	if(!from_ob)   return notify_fail("������û�����ֻ��ҡ�\n");

	if(!check_money(from_ob,me))
		return 1;

	if(from == to)
	{
		from_name = from_ob->name();
		return notify_fail("��"+from_name+"�һ�"+from_name
			+"�������ϵ�"+from_name+"���Ǽٵİɣ�\n");
	}

	if(amount == 0)
		amount = (int)from_ob->query_amount();

	if( (int)from_ob->query_amount() < amount )
		return notify_fail("������û����ô��" + from_ob->query("name") + "��\n");

	bv1 = from_ob->query("base_value");
	if( !bv1 ) return notify_fail("���ֶ�����ֵǮ��\n");

	bv2 = call_other("/obj/money/" + to, "query", "base_value" );

	if(bv1 < bv2)
	{
		amount -= amount % ((to_int(bv2/bv1) == bv2/bv1)?
				to_int(bv2/bv1):to_int(bv2/bv1)+1);
		if(amount == 0)
			return notify_fail("��Щ" + from_ob->query("name") +
				"�ļ�ֵ̫���ˣ�������\n");
	}

	sum = (bv1*amount/bv2);
	if( ((bv1 < bv2)?from:to) != "coin")
		charge = ((bv1*amount)-(bv2*sum))/(FINANCE_D->base_coin_value());
	to_ob = new("/obj/money/" + to);
	to_ob->set_amount(sum);

	if(charge)
	{
		charge_ob = new("/obj/money/coin");
		charge_ob->set_amount(charge);
	}

	if( (to_ob->query_weight()
	+ ((charge_ob)?charge_ob->query_weight():0)
	+ me->query_encumbrance()) >= me->query_max_encumbrance())
	{
		destruct(to_ob);
		if(charge_ob)
			destruct(charge_ob);
		return notify_fail("���ò�����ô�ණ��.\n");
	}

	to_ob->move(me);
	if(charge_ob)
		charge_ob->move(me);
	tell_object(me,sprintf("�������ȡ��%s%s%s������%s%s%s%s��\n",
		chinese_number(amount), from_ob->query("base_unit"), from_ob->query("name"),
		chinese_number(sum), to_ob->query("base_unit"), to_ob->query("name"),
		(charge_ob)?"��"+chinese_number(charge)+"��"+YEL+"ͭǮ"+NOR:""));

	from_ob->add_amount(-amount);
	me->start_busy(1);
	return 1;
}

nomask int do_zhuanzhang(string arg)
{
	int amount,save;
	string which,name;
	object ob,me = this_player();

	if(!arg)
		return notify_fail("��Ҫ�������µ����ֻ���ת��˭��\n");

	if(sscanf(arg,"%d %s to %s",amount,which,arg) != 3)
	{
		if(sscanf(arg,"%s to %s",which,arg) != 2)
			return notify_fail("��Ҫ�������µ����ֻ���ת��˭��\n");
	}
	else if(amount < 1)
		return notify_fail("ת����������Ϊ 1��\n");

	if(arg == me->query("id"))
		return notify_fail("��ת�˸��Լ������ĵ��ҵ��İ���Ĵ��û���ˡ�\n");

	switch (which)
	{
		case "gold":
			name = HIY"�ƽ�"NOR;
			break;
		case "silver":
			name = HIW"����"NOR;
			break;
		case "coin":
			name = YEL"ͭǮ"NOR;
			break;
		default:
			return notify_fail("��Ҫ�����ֻ��ҽ���ת�ˣ�\n");
	}

	save = me->query(sprintf("save_in_bank/%s",which));
	if(!amount)
		amount = save;
	if(amount > save)
		return notify_fail(sprintf("�������û��%s%s��\n",
			save?"�㹻������":"����",name));

	if(!(ob = find_player(arg)))
		return notify_fail("Ŀǰû��"+arg+"����������ϡ�\n");

	if(wizardp(ob) != wizardp(me))
		return notify_fail("����涨��ʦ�����֮�䲻���໥ת�ˡ�\n");

	if((MAX - ob->query(sprintf("save_in_bank/%s",which),amount)) < amount)
		return notify_fail(sprintf("�Է������˻����޷�������ô��������%s��\n",name));

	me->add(sprintf("save_in_bank/%s",which),-amount);
	tell_object(me,sprintf("������֪ͨ�����㽫%s%s%sת�뵽��%s�����¡�\n",
		chinese_number(amount),which=="coin"?"��":"��",name,ob->name()
	));
	me->save();
	ob->add(sprintf("save_in_bank/%s",which),amount);
	ob->save();
	tell_object(ob,sprintf("������֪ͨ����%s��%s%s%sת�뵽��������¡�\n",
		me->name(),chinese_number(amount),which=="coin"?"��":"��",name
	));

	return 1;
}

nomask int do_paijia(string arg)
{
	string msg = "";

	msg += "\n��ǰȫ����ͨ�л���֮��ȼ�Ϊ��\n\n";
	msg += sprintf("һ��"+HIY+"�ƽ�"+NOR+"�һ� %6.2f ��������\n",gtos_ratio());
	msg += sprintf("һ��"+HIY+"�ƽ�"+NOR+"�һ� %6.2f ��"+YEL+"ͭǮ"+NOR+"��\n",gtoc_ratio());
	msg += sprintf("һ��"+HIW+"����"+NOR+"�һ� %6.2f ��"+YEL+"ͭǮ"+NOR+"��\n\n",stoc_ratio());
	msg += "---------------------------------\n";
	msg += "\t"+MUD_NAME+"����"+chinese_number(query_year())+"������\n";

	write(msg);
	return 1;
}

nomask int do_impawn(string arg)
{
	string *homes, *domains = ({});
	int i,n,l,bk;
	object me = this_player();

	if(!arg || arg != "home")
		return notify_fail("��Ҫ��ʲô������Ѻ��\n");

	if( ! (homes = PLAYERHOME_D->user_have_home(me->query("id"))) )
		return notify_fail("�㻹û���Լ���סլ��ʲô��Ѻ��\n");

	n = sizeof(homes);

	for(i=0;i<n;i++)
	{
		string domain;
		if(sscanf(homes[i],PHOME_DIR+"%s/%*s",domain))
			domains += ({ domain });
	}

	if( (n=sizeof(domains)) == 1 )
		go_impawn("1",me,domains);

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
		write("��������"+chinese_number(n)+"�������������Լ���סլ������ѡ��һ����\n"+out+"\n");
		input_to( (: go_impawn :),me, domains );
	}

	return 1;
}

private void go_impawn(string arg,object me,string *domains)
{
	object home;
	string file;
	int level,time,n;

	if(arg[0] == 'q')
		return;

	n = atoi(arg);
	--n;
	if( (n<0) || (n>=sizeof(domains)) || !me)
		return;

	if(!objectp(me))
		return;

	file = sprintf("%s%s/%s_home",PHOME_DIR,domains[n],me->query("id"));

	home = find_object(file);
	if(!home)
		home = load_object(file);
	if(!home)
	{
		write("���סլ�����⣬������ʦ�걨����\n");
		return;
	}

	if(mapp(home->query("bank")))
	{
		write(sprintf("����%s��סլ�Ѿ���Ѻ���ˣ�ͬһ��Ʒ��������ص�Ѻ��\n",
			to_chinese(domains[n])));
		return;
	}

	time = time() - home->query("built_time");
	if(time > 788400) /* һ��� */
	{
		write(sprintf("����%s��סլ�Ѿ���Ҫ�����ˣ����ܵ�Ѻ��\n",
			to_chinese(domains[n])));
		return;
	}
	else if(time > 525600) /* һ�� */
	{
		write(sprintf("����%s��סլ�Ѿ����ʧ�ޡ��ƾɲ����ˣ����ܵ�Ѻ��\n",
			to_chinese(domains[n])));
		return;
	}

	level = home->home_level();
	write(sprintf("���ס����ǰ��ֵ��%s\n���Ե�Ѻ��%s",
		chinese_value(PLAYERHOME_D->home_value(level)),
		chinese_value(to_int(PLAYERHOME_D->home_value(level)*IMPAWN_RATE)) +"\n"));
	write("��Ҫ��Ѻ���ٸ��£�(q �˳�)\n");
	input_to((: go_on_pawn :),me,home);
	return;
}

private void go_on_pawn(string arg,object me,object home)
{
	int m,pay;
	int time,i,level;
	object *homes;

	if(arg[0] == 'q')
		return;

	if(!objectp(me))
		return;

	if(!m = atoi(arg))
	{
		write("��Ҫ��Ѻ���ٸ��£�(q �˳�)\n");
		input_to((: go_on_pawn :),me,home);
		return;
	}

	time = home->query("built_time");
	if( (time() + m*43200 - time) >= 525600 )
	{
		write("����סլ�ڴ����ڼ���Ҫ����ά�޲��ܱ������м�ֵ��\n�뵽����Ԥ�������ɷѺ���������\n");
		return;
	}

	level = home->home_level();
	write("���˽��סլ����н��е�Ѻ��Ӧ��"+
		chinese_value(pay = to_int(PLAYERHOME_D->home_value(level)*IMPAWN_RATE))+"��\n");

	homes = PLAYERHOME_D->player_homes(me,home);
	for(i=0;i<sizeof(homes);i++)
	{
		homes[i]->set("bank/time",time()+m*43200);
		homes[i]->set("bank/value",pay);
		homes[i]->save();
	}

	write("��ȥ"+chinese_number(m)+"���µĴ�����Ϣ"+
	chinese_value(to_int(pay *accrual*m))+"��\n" );
	write("ʵ��"+chinese_value(pay = to_int(pay*(1-m*accrual))) +"��\n");

	save_to_bank(me,pay);

	write("�˿����Ѵ������������˻���\n");
	return;
}

nomask int do_redeem(string arg)
{
	string *homes, file, *domains=({});
	int i,n,l,bk;
	object home, me=this_player();

	if(!arg || arg != "home")
		return notify_fail("��Ҫ���ʲô��\n");

	if( ! (homes = PLAYERHOME_D->user_have_home(me->query("id"))) )
		return notify_fail("�㻹û���Լ���סլ��\n");

	if((n=sizeof(homes)) == 1)
	{
		string domain;
		home = find_object((file = homes[0]));
		if(!home)
			home = load_object(file);
		if(!home)
			return notify_fail("���סլ�����⣬������ʦ�걨����\n");
		if(!mapp(home->query("bank")))
			return notify_fail("���סլû�н��й���Ѻ��\n");
		if(sscanf(homes[0],PHOME_DIR+"%s/%*s",domain))
		{
			domains += ({ domain });
			go_redeem("1",me,domains);
			return 1;
		}
		else
			return notify_fail("���סլ�����⣬������ʦ�걨����\n");
	}

	for(i=0;i<n;i++)
	{
		string domain;
		home = find_object((file = homes[i]));
		if(!home)
			home = load_object(file);
		if(!home)
			continue;
		if(!mapp(home->query("bank")))
			continue;
		if(sscanf(homes[i],PHOME_DIR+"%s/%*s",domain))
			domains += ({ domain });
	}

	if(!(n=sizeof(domains)))
		return notify_fail("��û�н��й���Ѻ��סլ��\n");

	if( n == 1 )
	{
		go_redeem("1",me,domains);
		return 1;
	}

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
		write("��������"+chinese_number(n)+"��������סլ�����й���Ѻ������ѡ��һ����\n"+out+"\n");
		input_to( (: go_redeem :),me, domains );
	}

	return 1;
}

private void go_redeem(string arg,object me,string *domains)
{
	string file;
	object home,*homes;
	mapping bank;
	int value,i,n;

	if(arg[0] == 'q')
		return;

	n = atoi(arg);
	n--;
	if( (n<0) || (n>=sizeof(domains)) || !me)
		return;

	if(!objectp(me))
		return;

	file = sprintf("%s%s/%s_home",PHOME_DIR,domains[n],me->query("id"));

	home = find_object(file);
	if(!home)
		home = load_object(file);
	if(!home)
	{
		write("���סլ�����⣬������ʦ�걨����\n");
		return;
	}

	if(!mapp(bank = home->query("bank")))
	{
		write("���סլû�н��й���Ѻ��\n");
		return;
	}

	value = to_int(PLAYERHOME_D->home_value(home->home_level())*IMPAWN_RATE);

	write("������סլ����黹��Ѻ���"+chinese_value(value)+"��\n");
	if(!pay_from_bank(me,value))
	{
		write("���ǣ���������û���㹻�Ĵ�\n");
		return;
	}

	homes = PLAYERHOME_D->player_homes(me,home);
	for(i=0;i<sizeof(homes);i++)
	{
		homes[i]->delete("bank");
		homes[i]->save();
	}

	write("������Ѵ����������˻������������Ժ�������������չ�С�ġ�\n");
	return;
}

nomask int check_money(object money,object me)
{
	if(!money || !me)
		return 0;

	if(!sscanf(file_name(money),"/obj/money/%*s"))
	{
		sys_log("wiz_ob",sprintf("(%s)��ͼ��α��(%s)�����д�Ǯ��û��.(%s)\n",
		geteuid(me),base_name(money),ctime(time())));
		destruct(money);
		tell_object(me,"�����ϵ�α����û���ˡ�\n");
		return 0;
	}

#ifdef WIZARD_FLAG
	if( money->query_wiz_flag() && !wizardp(me) )
	{
		sys_log("wiz_ob",sprintf("(%s)��ͼ����ʦ����Ǯ(%s:%d)�����д�û��.(%s)\n",
		geteuid(me),money->query("id"),money->query_amount(),ctime(time())));
		destruct(money);
		tell_object(me,"����Ǯ����ʦ�����,��û����,����������������������,�������Ը�.\n");
	}
#endif
	else
		return 1;
}
