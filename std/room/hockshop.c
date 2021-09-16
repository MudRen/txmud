// hockshop.c
// by Find.

#define sell_rate	7/10
#define pawn_rate	6/10

inherit ROOM;
inherit F_SAVE;

int do_sellt(object ob,object me);
mapping pawned_objects = ([]);

static int max_items = 60;
static int mudday_in_realtime_second = 1440;

/* �������Ʒ dummy �ĳ��֡�
 * ���ڴ˷���ĸ�ϵͳ������Ҳ������������
 * �಻�ȶ����ռ�ø߶�ϵͳ��Դ��
 * ��ʽ�����ȶ����������׼��Ӧ��ߣ�
 * ����Ϊ age : 18, exp : 50000 ��Ϊ���ʡ�
 */
static int min_age = 15;	// 15����ǰ���ܵ䵱��
static int min_exp = 20000;	// exp < 20000 ���ܵ䵱
static int min_value = 1000;	// ��ֵС�� 10 �����ӵ���Ʒ���̲���

#ifdef WIZARD_FLAG
private int check_pawn_object(object me,object ob)
{
	string name;

	if(!objectp(me) || !objectp(ob))
		return 0;

	/* �������������̻��ǵ������̵Ķ�����Ҿ�����ͨ�����������Ӵ���
           ���ֻҪ�� wiz_ob ��Ʒ�Ͳ��������뵱�̣����۶������ǲ�����ʦ
	*/
	if(ob->query_wiz_flag())
	{
		name = ob->name();
		log_file("shop",sprintf("%s �� %s %s %s ��û��. %s\n",
			geteuid(me),to_chinese(domain_file(base_name(this_object()))),
			(ob->is_pawn_stamp())?"ʹ����ʦ�����ֽŵĵ�Ʊ":"����ʦ��Ʒ",
			base_name(ob),ctime(time())));
		notify_fail(ob->name()+"����ʦ��Ʒ��û���ˣ����������������������ͣ�\n");
		destruct(ob);
		return 0;
	}
	else
		return 1;
}
#endif

string query_save_file()
{
	string name;

	name = base_name(this_object());
	if(name[0..0] == "/")
		name = name[1..];
	name = replace_string(name,"/","_");

	return DATA_DIR+"hockshop/"+name;
}

void setup()
{
	::setup();
	seteuid(getuid());
	restore();
}

void init()
{
	add_action("do_value", ({"value", "gujia"}) );
	add_action("do_pawn", ({"pawn", "dang"}) );
	add_action("do_sell", "sell");
	add_action("do_retrieve", ({"redeem", "shu", "shuhui"}) );
	add_action("do_list", "list");
	add_action("do_buy", ({"buy","mai"}));
}

int do_value(string arg)
{
	object ob;
	int value;

	if( !arg || !(ob = present(arg, this_player())) )
		return notify_fail("��Ҫ��ʲô��Ʒ�����̹��ۣ�\n");

	if( ob->query("money_id") )
		return notify_fail("���ǡ�Ǯ������û������\n");

	if(ob->is_food())
		return notify_fail("ʳƷ�����Լ��԰ɡ�\n");
	if(ob->is_corpse())
		return notify_fail("����˭��ʬ�׿���ߣ������⻹Ҫ�������ء�\n");
	if(ob->is_weapon())
		return notify_fail("����С��ɲ����գ���ȥ���������ʰɡ�\n");
	if(ob->is_character())
		return notify_fail("С���ط������ҷ����˿ڡ�\n");
	if(ob->is_ctl_ob() || ob->is_iron_class_res() || ob->is_self_object())
		return notify_fail("��������С�̿��ǲ��ұ��档\n");
	if(ob->is_poison())
		return notify_fail("����С��ɲ����գ�\n");
	if(ob->query("no_drop"))
		return notify_fail("�����������겻�ա�\n");
	if(ob->query("no_sell"))
		return notify_fail("�����������겻�ա�\n");

#ifdef WIZARD_FLAG
	if(!check_pawn_object(this_player(),ob))
		return 0;
#endif

	if(ob->query_credit_point_flag())
		return notify_fail(sprintf("%sһ�Ĳ�ֵ��\n", ob->query("name")));

	value = ob->query("value");
	if(!value)
		value = ob->value();

	if( !value )
		return notify_fail(sprintf("%sһ�Ĳ�ֵ��\n", ob->query("name")));
	if(value < min_value)
		return notify_fail(ob->query("name")+"��ֵ̫�ͣ��ⲻ�ա�\n");

	else
	{
		value = value*price_ratio(this_object())/100;

		printf("%s��ֵ%s��\n�����Ҫ�䵱(pawn)�������õ�%s��һ�ŵ�Ʊ��\n�������(sell)�������õ�%s��\n",
			ob->query("name"), chinese_value(value),
			chinese_value(value*pawn_rate), chinese_value(value*sell_rate));
	}
	return 1;
}

int do_pawn(string arg)
{
        object ob, stamp,me = this_player();
        int value,real_value,year,month,day,last_days,how;
	string time,redeem_time;

	if( !arg || !(ob = present(arg, me)) )
		return notify_fail("��Ҫ�䵱ʲô��Ʒ��\n");

	if(me->query("age") < min_age)
		return notify_fail("�����仹̫С���ȳ���һ����˵�ɡ�\n");
	if(me->query("combat_exp") < min_exp)
		return notify_fail("��Ľ���������̫ǳ�����Ժ�����������˵�ɡ�\n");

	if(PAWN_D->query_being_meeting())
		return notify_fail("��������᡻�ڼ���ʱ������䵱���굱���ˡ�\n");

	if( ob->query("money_id") )
		return notify_fail("���ǡ�Ǯ������û������\n");
	if(ob->is_food())
		return notify_fail("ʳƷ�����Լ��԰ɡ�\n");
	if(ob->is_corpse())
		return notify_fail("����˭��ʬ�׿���ߣ������⻹Ҫ�������ء�\n");
	if(ob->is_weapon())
		return notify_fail("����С��ɲ����գ���ȥ���������ʰɡ�\n");
	if(ob->is_character())
		return notify_fail("С���ط������ҷ����˿ڡ�\n");
	if(ob->is_ctl_ob() || ob->is_iron_class_res() || ob->is_self_object())
		return notify_fail("��������С�̿��ǲ��ұ��档\n");
	if(ob->is_poison())
		return notify_fail("����С��ɲ����գ�\n");
	if(ob->query("no_drop"))
		return notify_fail("�����������겻�ա�\n");
	if(ob->query("no_sell"))
		return notify_fail("�����������겻�ա�\n");

#ifdef WIZARD_FLAG
	if(!check_pawn_object(me,ob))
		return 0;
#endif

	if(ob->query_credit_point_flag())
		return notify_fail(sprintf("%sһ�Ĳ�ֵ��\n", ob->query("name")));

	if(!PAWN_D->can_pawn_ob(geteuid(me)))
		return notify_fail("��䵱�Ķ������кܶ�û����أ�С�̱�С��΢����������ĵ���\n");

	value = ob->query("value");
	if(!value)
		value = ob->value();

	if( !value )
		return notify_fail(sprintf("%sһ�Ĳ�ֵ��\n", ob->query("name")));
	if(value < min_value)
		return notify_fail(ob->query("name")+"��ֵ̫�ͣ��ⲻ�ա�\n");

	real_value = value;
	value = value*price_ratio(this_object())/100;
	value = value*pawn_rate;
	/*
		���¼���ݣ�
		ʱ�䡢�ص㡢�����Ʒ
	*/

	year = query_year();
	month = query_month();
	day = query_day_in_month();
	time = sprintf("%s����%s��%s��%s��",MUD_NAME,(!year)?"Ԫ":chinese_number(year),
		chinese_number(month),chinese_number(day));
	month += 6;
	if(month > 12)
	{
		year += 1;
		month -=12;
		last_days = query_day( ({month,day}) ) + (365 - query_day(0));
	}
	else
		last_days = query_day( ({month,day}) ) - query_day(0);
	redeem_time = sprintf("%s����%s��%s��%s��",MUD_NAME,(!year)?"Ԫ":chinese_number(year),
		chinese_number(month),chinese_number(day));


	stamp = new(__DIR__"obj/pawn_stamp");

	stamp->use_this_stamp(
		({
		geteuid(me),
		base_name(ob),
		time()+mudday_in_realtime_second*last_days,
		base_name(this_object()),
		sprintf("���յ���\n%s�䵱�����ò���%sһ%s\nӦ��%s��ǰ���\n���Ӧ��%s\n\n\t%s\n\t%s\n",
			me->name(1),ob->name(),
			ob->query("unit"),redeem_time,chinese_value(real_value),
			to_chinese(domain_file(file_name(this_object())))+
			this_object()->query("short"),time)
		})
	);

	how = PAWN_D->pawn_one_object(stamp);

	if(!how)	// PAWN_D ���ִ���
	{
		destruct(stamp);
		return notify_fail("���������ʽ���ת���ѣ���ʱ���յ��ˣ��뵽�𴦿����ɡ�\n");
	}

	if(how == -1)
	{
		destruct(stamp);
		return notify_fail("��䵱�Ķ������кܶ�û����أ�С�̱�С��΢����������ĵ���\n");
	}

	stamp->move(me);
	pay_player(me, value);
	message_vision("$N�����ϵ�" + ob->query("name") + "�ó����䵱��"
		+ chinese_value(value) + "������һ�ŵ�Ʊ��\n", me);

	destruct(ob);
	return 1;
}

int do_sellob_filter(object ob)
{
	if(!objectp(ob))
		return 0;
	if( ob->query("money_id") )
		return notify_fail("���ǡ�Ǯ������û������\n");
	if(ob->is_food())
		return notify_fail("ʳƷ�����Լ��԰ɡ�\n");
	if(ob->is_corpse())
		return notify_fail("����˭��ʬ�׿���ߣ������⻹Ҫ�������ء�\n");
	if(ob->is_weapon())
		return notify_fail("����С��ɲ����գ���ȥ���������ʰɡ�\n");
	if(ob->is_character())
		return notify_fail("С���ط������ҷ����˿ڡ�\n");
	if(ob->query("no_drop"))
		return notify_fail("�����������겻�ա�\n");
	if(ob->query("no_sell"))
		return notify_fail("�����������겻�ա�\n");
	else
		return 1;
}

int do_sell(string arg)
{
        object ob,*inv,me;
        int i;

        me=this_player();

	if(!arg)
		return notify_fail("��Ҫ����ʲô��Ʒ��\n");
	if(arg!="all")
	{
		if(!(ob = present(arg,me)))
			return notify_fail("��Ҫ����ʲô��Ʒ��\n");

		if(!do_sellob_filter(ob))
			return 0;

#ifdef WIZARD_FLAG
		if(!check_pawn_object(me,ob))
			return 0;
#endif

		return do_sellt(ob,me);
	}

	else
	{
		inv = all_inventory(me);
		if(!sizeof(inv))
			return notify_fail("������û���κζ�����\n");
		for(i=0; i<sizeof(inv); i++)
		{
			if(!do_sellob_filter(ob))
				continue;

#ifdef WIZARD_FLAG
			if(!check_pawn_object(me,ob))
				return 0;
#endif

			else
				do_sellt(inv[i],me);
		}
	}
	return 1;
}

int do_sellt(object ob,object me)
{
	int value;
	string file;

	if(!objectp(ob) || !objectp(me))
		return 0;

	value = ob->query("value");
	if(!value)
		value = ob->value();
	if(!value)
		return notify_fail(sprintf("%sһ�Ĳ�ֵ��\n", ob->query("name")));
	if(value < min_value)
		return notify_fail(ob->query("name")+"��ֵ̫�ͣ��ⲻ�ա�\n");

	value = value*price_ratio(this_object())/100;
	value = value * sell_rate;

	message_vision("$N�����ϵ�"+ob->query("name")+"�ó�����"+chinese_value(value)+"��\n",me);

	pay_player(me, value, ob->query_credit_point_flag()?1:0);

	if(ob->is_self_object() || ob->is_iron_class_res())
	{
		destruct(ob);
		return 1;
	}

	file = base_name(ob);

	if(!undefinedp(pawned_objects[file]))
	{
		if(pawned_objects[file] > 500)
			pawned_objects[file] = 500;
		else if(pawned_objects[file] < 500)
			pawned_objects[file]++;
	}

	else if(sizeof(pawned_objects) < max_items)
		pawned_objects += ([ file : 1 ]);
	else
	{
		map_delete(pawned_objects,keys(pawned_objects)[0]);
		pawned_objects += ([ file : 1 ]);
	}

	destruct(ob);
	save();

	return 1;
}

int do_retrieve(string arg)// ��Ʊ����� wiz_ob ���
{
	object stamp, ob,me = this_player();
	int value,pay,flag;
	string ob_name;

	if(PAWN_D->query_being_meeting())
		return notify_fail("��������᡻�ڼ���ʱ������䵱���굱���ˡ�\n");

	if( !arg || arg=="" || !(stamp = present(arg, me)) )
		return notify_fail("��Ҫ�����һ�ŵ�Ʊ�ϵĵ��\n");

	if( !stamp->is_pawn_stamp() )
		return notify_fail("�ⲻ�ǵ�Ʊ��\n");

#ifdef WIZARD_FLAG
	if(!check_pawn_object(me,stamp))
		return 0;
#endif

	if(stamp->query_master() != geteuid(me))
		return notify_fail("���ŵ�Ʊ������ġ�\n");

	if( stamp->query_hockshop() != base_name(this_object()) )
		return notify_fail("���ŵ�Ʊ�������⿪���ģ���ȥ��ĵط������ɡ�\n");

	if(time() > stamp->query_rtime())
	{
		destruct(stamp);
		return notify_fail("���ŵ�Ʊ�ϵ���Ʒ�Ѿ������굱�ڡ�\n"+
			"���̵ĵ��ְ����ŵ�Ʊ˺�����ˡ�\n");
	}

	if( !(ob_name = stamp->query_pob_file())
	|| !objectp(ob = new(ob_name)) )
		return notify_fail("û�����ŵ�Ʊ�ϵ���Ʒ����ĵ�Ʊ���Ǽٵİɣ�\n"+
			"���̵ĵ��ְ����ŵ�Ʊ˺�����ˡ�\n");
	value = ob->query("value");
	if(!value)
		value = ob->value();
	if(!value)
	{
		destruct(ob);
		destruct(stamp);
		return notify_fail("û�����ŵ�Ʊ�ϵ���Ʒ����ĵ�Ʊ���Ǽٵİɣ�\n"+
			"���̵ĵ��ְ����ŵ�Ʊ˺�����ˡ�\n");
	}

	pay = player_pay(me,value); // ��ظ�ȫ��
	if(!pay || pay == 2)
	{
		destruct(ob);
		return notify_fail(sprintf("������ŵ�Ʊ�ϵ���Ʒ��Ҫ%s\n�����ϵ�Ǯ������\n",
			chinese_value(value)));
	}

	flag = PAWN_D->redeem_one_object(stamp);
	if(!flag || flag == -1)
	{
		destruct(ob);
		destruct(stamp);
		return notify_fail("û�����ŵ�Ʊ�ϵ���Ʒ����ĵ�Ʊ���Ǽٵİɣ�\n"+
			"���̵ĵ��ְ����ŵ�Ʊ˺�����ˡ�\n");
	}		

	else
	{
		destruct(stamp);
		if(!flag = ob->move(me))
		{
			ob->move(this_object());
			write(sprintf("���ò��˸���Ķ����ˣ�����ص�%s������ڵ����ˡ�\n",
				ob->name()));
		}
		else
			write(sprintf("��������ص�%s���պá�\n",ob->name()));
		return 1;
	}
}

int do_list(string arg)
{
	string msg,*items;
	int i,n,value;
	float rate;

	if(!sizeof(pawned_objects))
		return notify_fail("����������û�д����۵Ļ��\n");

	rate = price_ratio(this_object());

	msg = "���������������»�����ۣ�\n";
	msg += sprintf(" %-26s%-10s%-10s\n","    ��  Ʒ","  ����","   ��  ��");
	msg += "----------------------------------------------\n";

	items = keys(pawned_objects);
	n = sizeof(items);
	for(i=0;i<n;i++)
	{
		value = items[i]->query("value");
		if(!value)
			value = items[i]->value();
		value = value*rate/100*9/10;
		msg += sprintf(" %-26s%-10s%s\n",clr_ansi(items[i]->short()),
			sprintf("%-3d%s",pawned_objects[items[i]],items[i]->query("unit")),
			chinese_value(value));
	}

	msg += "\n";
	this_player()->start_more(msg);
	return 1;
}

int do_buy(string arg)
{
	int i,n,value,pay;
	object ob;
	string *items;

	if(!sizeof(pawned_objects))
		return notify_fail("����������û�д����۵Ļ��\n");

	if( !arg )
		return notify_fail("��Ҫ��ʲô������\n");

	items = keys(pawned_objects);
	n = sizeof(items);

	for(i=0;i<n;i++)
		if(items[i]->id(arg))
			break;
	if( i >= sizeof(pawned_objects) )
		return notify_fail("��Ҫ��ʲô������\n");

	value = items[i]->query("value");
	if(!value)
		value = items[i]->value();

	value = value*price_ratio(this_object())/100*9/10;

	pay = player_pay(this_player(),value);
	if(!pay || (pay == 2))
		return notify_fail("�����ϵ�Ǯ������\n");

	ob = new(items[i]);
	if(pay == 3)
		ob->set_credit_point_flag();

	if( --pawned_objects[items[i]] <= 0)
		map_delete(pawned_objects,items[i]);
	save();

	if(!ob->move(this_player()))
		ob->move(this_object());
	message_vision("$N�ͳ�Ǯ����һ" + ob->query("unit") + ob->name() + "��\n",
		this_player() );

	return 1;
}
