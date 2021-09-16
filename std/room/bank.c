// bank.c
// Modified by Find.

#define MAX	2000000000	/* long max 2^32 所以规定不能超过21亿 */
#define THOUSAND_CASH		/* define this for enable 'thousand-cash' */
#define IMPAWN_RATE	80/100	/* 抵押比例 */
#undef DAY_NIGHT

#include <ansi.h>

inherit ROOM;

float accrual = 0.01;	/*每月的抵押贷款利率*/
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
			write( (time > 240) ? "这么晚的天，鄙庄已经打烊了，请明天再来吧。\n"
				: ( (time <= 60) ? "马上就要开门了，请等一下吧。\n"
				: "鄙庄还没有开门，请天亮了再来吧。\n" ) );
			return 1;
		}
	}
#endif

	if(me->is_busy())
		return notify_fail(BUSY_MESSAGE);

	amount=me->query("save_in_bank");
	if(!amount)
        {
                write("你没有存款\n");
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
		write("你没有存款\n");
                return 1;
	}

        msg="你存有：\n"
		+((gold)?chinese_number(gold)+"两"+HIY "黄金。\n" NOR:"")
		+((silver)?chinese_number(silver)+"两白银。\n":"")
		+((coin)?chinese_number(coin)+"文"+YEL "铜钱。\n" NOR:"");
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
                        write( (time > 240) ? "这么晚的天，鄙庄已经打烊了，请明天再来吧。\n"
                                : ( (time <= 60) ? "马上就要开门了，请等一下吧。\n"
                                : "鄙庄还没有开门，请天亮了再来吧。\n" ) );
                        return 1;
                }
        }
#endif
        if( me->is_busy() )
                return notify_fail(BUSY_MESSAGE);

	if(!arg) 
		return notify_fail("指令格式：cunqian <数量> <货币种类> \n");

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
			return notify_fail("数量大于1\n");
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
		return notify_fail("指令格式：cunqian <数量> <货币种类> \n");

        money=present(from+ "_money", me);

        if( !money )
                return notify_fail("你身上没有这种货币。\n");

	if(!check_money(money,me))
		return 1;

	if(amount == 0)
		amount = (int)money->query_amount();

        else if( (int)money->query_amount() < amount )
                return notify_fail("你身上没有那么多" + money->query("name") + "。\n");

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
			return notify_fail("你存不了这么多"+money->query("name")+"。\n");
	else
                me->add("save_in_bank/"+from,amount);

	tell_object(me,sprintf("你将%s%s%s存进银行。\n",
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
                        write( (time > 240) ? "这么晚的天，鄙庄已经打烊了，请明天再来吧。\n"
                                : ( (time <= 60) ? "马上就要开门了，请等一下吧。\n"
                                : "鄙庄还没有开门，请天亮了再来吧。\n" ) );
                        return 1;
                }
        }
#endif

        if( me->is_busy() )
                return notify_fail(BUSY_MESSAGE);

        if( !arg || sscanf(arg, "%d %s", amount, from)!=2 )
		return notify_fail("指令格式：quqian<数量> <货币种类> \n");

        if(from != "coin"
	&& from != "silver"
	&& from != "gold"
#ifdef THOUSAND_CASH
	&& from != "thousand-cash"
#endif
	)
                return notify_fail("指令格式：quqian<数量> <货币种类> \n");

        if (amount<1)
                return notify_fail("数量大于1\n");

	if(me->query_temp("be_in_sale_meeting_chu"))
		return notify_fail("你正在参加拍卖大会的竞买，暂时不能动用银行存款。\n");

        base=me->query("save_in_bank");

	if(!base || !mapp(base))
		return notify_fail("你没有任何存款。\n");

	if(undefinedp(base[((from == "thousand-cash")?"silver":from)])
	|| !base[((from == "thousand-cash")?"silver":from)])
		return notify_fail("你在银行没存有这种货币。\n");

	if(base[((from == "thousand-cash")?"silver":from)] <
		((from == "thousand-cash")?amount*1000:amount) )
                return notify_fail("你没有存那么多钱\n");

        if(!money = new("/obj/money/" + from))
                return notify_fail("指令格式：quqian<数量> <货币种类> \n");

        money->set_amount(amount);
	if(!money->move(this_player()))
	{
		destruct(money);
		return notify_fail("你拿不了这么多东西.\n");
	}

	tell_object(me,"你从银行中取出"+chinese_number(amount)+money->query("base_unit")
		+money->query("name")+"。\n");

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
                        write( (time > 240) ? "这么晚的天，鄙庄已经打烊了，请明天再来吧。\n"
                                : ( (time <= 60) ? "马上就要开门了，请等一下吧。\n"
                                : "鄙庄还没有开门，请天亮了再来吧。\n" ) );
                        return 1;
                }
        }
#endif

	if( me->is_busy() )
                return notify_fail(BUSY_MESSAGE);

	if( !arg )
		return notify_fail("指令格式：huan <数量> <货币种类> to <货币种类>\n");

	if( sscanf(arg, "%d %s to %s",amount, from, to) == 3 )
	{
		if(amount < 1)
			return notify_fail("兑换货币一次至少要兑换一个。\n");
	}

	else if(sscanf(arg, "%s to %s",from, to) == 2)
		amount = 0;
	else
		return notify_fail("指令格式：huan <数量> <货币种类> to <货币种类>\n");

        if(from != "coin"
	&& from != "silver"
	&& from != "gold"
#ifdef THOUSAND_CASH
	&& from != "thousand-cash"
#endif
	)
		return notify_fail("指令格式：huan <数量> <货币种类> to <货币种类>\n");

	if(to != "coin"
	&& to != "silver"
	&& to != "gold"
#ifdef THOUSAND_CASH
	&& to != "thousand-cash"
#endif
	)
		return notify_fail("指令格式：huan <数量> <货币种类> to <货币种类>\n");

	from_ob = present(from + "_money", me);

	if(!from_ob)   return notify_fail("你身上没有这种货币。\n");

	if(!check_money(from_ob,me))
		return 1;

	if(from == to)
	{
		from_name = from_ob->name();
		return notify_fail("拿"+from_name+"兑换"+from_name
			+"？你身上的"+from_name+"别是假的吧？\n");
	}

	if(amount == 0)
		amount = (int)from_ob->query_amount();

	if( (int)from_ob->query_amount() < amount )
		return notify_fail("你身上没有那么多" + from_ob->query("name") + "。\n");

	bv1 = from_ob->query("base_value");
	if( !bv1 ) return notify_fail("这种东西不值钱。\n");

	bv2 = call_other("/obj/money/" + to, "query", "base_value" );

	if(bv1 < bv2)
	{
		amount -= amount % ((to_int(bv2/bv1) == bv2/bv1)?
				to_int(bv2/bv1):to_int(bv2/bv1)+1);
		if(amount == 0)
			return notify_fail("这些" + from_ob->query("name") +
				"的价值太低了，换不起。\n");
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
		return notify_fail("你拿不了这么多东西.\n");
	}

	to_ob->move(me);
	if(charge_ob)
		charge_ob->move(me);
	tell_object(me,sprintf("你从身上取出%s%s%s，换成%s%s%s%s。\n",
		chinese_number(amount), from_ob->query("base_unit"), from_ob->query("name"),
		chinese_number(sum), to_ob->query("base_unit"), to_ob->query("name"),
		(charge_ob)?"和"+chinese_number(charge)+"文"+YEL+"铜钱"+NOR:""));

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
		return notify_fail("你要将你名下的哪种货币转给谁？\n");

	if(sscanf(arg,"%d %s to %s",amount,which,arg) != 3)
	{
		if(sscanf(arg,"%s to %s",which,arg) != 2)
			return notify_fail("你要将你名下的哪种货币转给谁？\n");
	}
	else if(amount < 1)
		return notify_fail("转账数量至少为 1。\n");

	if(arg == me->query("id"))
		return notify_fail("想转账给自己？存心捣乱当心把你的存款没收了。\n");

	switch (which)
	{
		case "gold":
			name = HIY"黄金"NOR;
			break;
		case "silver":
			name = HIW"白银"NOR;
			break;
		case "coin":
			name = YEL"铜钱"NOR;
			break;
		default:
			return notify_fail("你要将哪种货币进行转账？\n");
	}

	save = me->query(sprintf("save_in_bank/%s",which));
	if(!amount)
		amount = save;
	if(amount > save)
		return notify_fail(sprintf("你的名下没有%s%s。\n",
			save?"足够数量的":"保存",name));

	if(!(ob = find_player(arg)))
		return notify_fail("目前没有"+arg+"这个人在线上。\n");

	if(wizardp(ob) != wizardp(me))
		return notify_fail("大神规定巫师与玩家之间不能相互转账。\n");

	if((MAX - ob->query(sprintf("save_in_bank/%s",which),amount)) < amount)
		return notify_fail(sprintf("对方银行账户里无法保存这么大数量的%s。\n",name));

	me->add(sprintf("save_in_bank/%s",which),-amount);
	tell_object(me,sprintf("【银行通知】：你将%s%s%s转入到了%s的名下。\n",
		chinese_number(amount),which=="coin"?"文":"两",name,ob->name()
	));
	me->save();
	ob->add(sprintf("save_in_bank/%s",which),amount);
	ob->save();
	tell_object(ob,sprintf("【银行通知】：%s将%s%s%s转入到了你的名下。\n",
		me->name(),chinese_number(amount),which=="coin"?"文":"两",name
	));

	return 1;
}

nomask int do_paijia(string arg)
{
	string msg = "";

	msg += "\n当前全国各通行货币之间比价为：\n\n";
	msg += sprintf("一两"+HIY+"黄金"+NOR+"兑换 %6.2f 两白银。\n",gtos_ratio());
	msg += sprintf("一两"+HIY+"黄金"+NOR+"兑换 %6.2f 文"+YEL+"铜钱"+NOR+"。\n",gtoc_ratio());
	msg += sprintf("一两"+HIW+"白银"+NOR+"兑换 %6.2f 文"+YEL+"铜钱"+NOR+"。\n\n",stoc_ratio());
	msg += "---------------------------------\n";
	msg += "\t"+MUD_NAME+"创世"+chinese_number(query_year())+"年御制\n";

	write(msg);
	return 1;
}

nomask int do_impawn(string arg)
{
	string *homes, *domains = ({});
	int i,n,l,bk;
	object me = this_player();

	if(!arg || arg != "home")
		return notify_fail("你要把什么拿来抵押？\n");

	if( ! (homes = PLAYERHOME_D->user_have_home(me->query("id"))) )
		return notify_fail("你还没有自己的住宅拿什么抵押！\n");

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
		write("你在以下"+chinese_number(n)+"处地区都建有自己的住宅，请你选择一处：\n"+out+"\n");
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
		write("你的住宅有问题，请向巫师申报处理。\n");
		return;
	}

	if(mapp(home->query("bank")))
	{
		write(sprintf("你在%s的住宅已经抵押过了，同一物品不允许多重抵押。\n",
			to_chinese(domains[n])));
		return;
	}

	time = time() - home->query("built_time");
	if(time > 788400) /* 一年半 */
	{
		write(sprintf("你在%s的住宅已经快要倒塌了，不能抵押。\n",
			to_chinese(domains[n])));
		return;
	}
	else if(time > 525600) /* 一年 */
	{
		write(sprintf("你在%s的住宅已经年久失修、破旧不堪了，不能抵押。\n",
			to_chinese(domains[n])));
		return;
	}

	level = home->home_level();
	write(sprintf("你的住房当前价值：%s\n可以抵押：%s",
		chinese_value(PLAYERHOME_D->home_value(level)),
		chinese_value(to_int(PLAYERHOME_D->home_value(level)*IMPAWN_RATE)) +"\n"));
	write("你要抵押多少个月？(q 退出)\n");
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
		write("你要抵押多少个月？(q 退出)\n");
		input_to((: go_on_pawn :),me,home);
		return;
	}

	time = home->query("built_time");
	if( (time() + m*43200 - time) >= 525600 )
	{
		write("您的住宅在贷款期间需要进行维修才能保持现有价值，\n请到工部预交足修缮费后再来办理。\n");
		return;
	}

	level = home->home_level();
	write("你把私人住宅向鄙行进行抵押，应得"+
		chinese_value(pay = to_int(PLAYERHOME_D->home_value(level)*IMPAWN_RATE))+"。\n");

	homes = PLAYERHOME_D->player_homes(me,home);
	for(i=0;i<sizeof(homes);i++)
	{
		homes[i]->set("bank/time",time()+m*43200);
		homes[i]->set("bank/value",pay);
		homes[i]->save();
	}

	write("扣去"+chinese_number(m)+"个月的贷款利息"+
	chinese_value(to_int(pay *accrual*m))+"。\n" );
	write("实得"+chinese_value(pay = to_int(pay*(1-m*accrual))) +"。\n");

	save_to_bank(me,pay);

	write("此款项已存入您的银行账户。\n");
	return;
}

nomask int do_redeem(string arg)
{
	string *homes, file, *domains=({});
	int i,n,l,bk;
	object home, me=this_player();

	if(!arg || arg != "home")
		return notify_fail("你要赎回什么？\n");

	if( ! (homes = PLAYERHOME_D->user_have_home(me->query("id"))) )
		return notify_fail("你还没有自己的住宅！\n");

	if((n=sizeof(homes)) == 1)
	{
		string domain;
		home = find_object((file = homes[0]));
		if(!home)
			home = load_object(file);
		if(!home)
			return notify_fail("你的住宅有问题，请向巫师申报处理。\n");
		if(!mapp(home->query("bank")))
			return notify_fail("你的住宅没有进行过抵押。\n");
		if(sscanf(homes[0],PHOME_DIR+"%s/%*s",domain))
		{
			domains += ({ domain });
			go_redeem("1",me,domains);
			return 1;
		}
		else
			return notify_fail("你的住宅有问题，请向巫师申报处理。\n");
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
		return notify_fail("你没有进行过抵押的住宅。\n");

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
		write("你在以下"+chinese_number(n)+"处地区的住宅都进行过抵押，请你选择一处：\n"+out+"\n");
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
		write("你的住宅有问题，请向巫师申报处理。\n");
		return;
	}

	if(!mapp(bank = home->query("bank")))
	{
		write("你的住宅没有进行过抵押。\n");
		return;
	}

	value = to_int(PLAYERHOME_D->home_value(home->home_level())*IMPAWN_RATE);

	write("赎回你的住宅你需归还抵押贷款："+chinese_value(value)+"。\n");
	if(!pay_from_bank(me,value))
	{
		write("但是，你银行里没有足够的存款。\n");
		return;
	}

	homes = PLAYERHOME_D->player_homes(me,home);
	for(i=0;i<sizeof(homes);i++)
	{
		homes[i]->delete("bank");
		homes[i]->save();
	}

	write("还款额已从您的银行账户划拨出，您以后有生意望多多照顾小的。\n");
	return;
}

nomask int check_money(object money,object me)
{
	if(!money || !me)
		return 0;

	if(!sscanf(file_name(money),"/obj/money/%*s"))
	{
		sys_log("wiz_ob",sprintf("(%s)企图用伪钞(%s)在银行存钱被没收.(%s)\n",
		geteuid(me),base_name(money),ctime(time())));
		destruct(money);
		tell_object(me,"你身上的伪钞被没收了。\n");
		return 0;
	}

#ifdef WIZARD_FLAG
	if( money->query_wiz_flag() && !wizardp(me) )
	{
		sys_log("wiz_ob",sprintf("(%s)企图用巫师给的钱(%s:%d)在银行存款被没收.(%s)\n",
		geteuid(me),money->query("id"),money->query_amount(),ctime(time())));
		destruct(money);
		tell_object(me,"这种钱是巫师给你的,被没收了,请立刻向天神发信做出解释,否则后果自负.\n");
	}
#endif
	else
		return 1;
}
