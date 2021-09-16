// /banghui/smith.c
// ���ɵ�����
// by Find.

#include <ansi.h>
#include <weapon.h>
#include <mine_def.h>
#include <mangle.h>
#include <self.h>
#define WEAPON_VALUE	500	/* ÿ��ɱ����5�����ӡ�*/
#define ARMOR_VALUE	200
#define KEY_VALUE	10000	/* �����Կ�ף�1 gold һ�� */
#define MIN_FEE		200	/* ���������͵ķ��� */
#define MAX_SELL_RATE	80

inherit NPC;
inherit F_SAVE;

string query_save_file()
{
	if(!clonep())
		return 0;
	return base_name("this_object()");
}

protected int sell_rate = 50;	// Ĭ��Ϊ����չ�
protected mapping make_weapon_ability = ([]);
protected nosave int do_nothing;
protected nosave object master;
protected nosave string b_id, b_name;
protected nosave string *can_epurate = ({
	IRON_MINE,
	IRON_RES_CU,
	IRON_RES_JING,
	BLACK_IRON,
});
protected nosave mapping res_cost = ([
"axe" : 5,
"blade" : 5,
"dagger" : 1,
"hammer" : 8,
"dhammer" : 6,
"spear" : 6,
"stick" : 6,
"sword" : 5,
"whip" : 6,
]),

res_cost_desc = ([
"axe" : "����(Axe) [�� %d ��ԭ��]\n",
"blade" : "��(Blade) [�� %d ��ԭ��]\n",
"dagger" : "ذ��(dagger) [�� %d ��ԭ��]\n",
"hammer" : "˫�ִ�(hammer) [�� %d ��ԭ��]\n",
"dhammer" : "���ִ�(hammer) [�� %d ��ԭ��]\n",
"spear" : "ǹ(spear) [�� %d ��ԭ��]\n",
"stick" : "��(stick) [�� %d ��ԭ��]\n",
"sword" : "��(sword) [�� %d ��ԭ��]\n",
"whip" : "��(whip) [�� %d ��ԭ��]\n",
]),

std_self_weapon = ([
"axe" : SELF_W_AXE,
"blade" : SELF_W_BLADE,
"dagger" : SELF_W_DAGGER,
"hammer" : SELF_W_HAMMER,
"dhammer" : SELF_W_DHAMMER,
"spear" : SELF_W_SPEAR,
"stick" : SELF_W_STICK,
"sword" : SELF_W_SWORD,
"whip" : SELF_W_WHIP,
]);

protected void get_self_weapon_unwield_msg(string, object, object);
protected void get_self_weapon_wield_msg(string, object, object);
protected void get_self_weapon_desc(string, object, object, string);
protected void get_self_weapon_id(string, object, object);
protected void get_self_weapon_name(string, object, object);
protected void select_weapon_class(string, object, string);
protected void rong_he(object, object);

int learn_make_weapon_ability(string cls)
{
#ifdef WIZARD_FLAG
	object pob;

	if( ( pob
	&& ( pob->query_wiz_flag()
	|| sscanf(file_name(pob),WIZ_DIR"%*s") ) )
	|| (this_player(1) && wizardp(this_player(1))) )
		return 0;
#endif

	if(!stringp(cls))
		return 0;

	if(!mapp(make_weapon_ability))
		make_weapon_ability = ([]);

	if(!undefinedp(make_weapon_ability[cls]))
		return notify_fail(sprintf("%s�Ѿ���������ֱ����ˡ�\n", name()));

	if(undefinedp(res_cost[cls]))
		return notify_fail(sprintf("%sû��ѧ�����ֱ����Ĵ��췽����\n", name()));

	make_weapon_ability += ([ cls : 5 ]);
	save();

	return 1;
}

int add_make_weapon_ability(string cls)
{
#ifdef WIZARD_FLAG
	object pob;

	if( ( pob
	&& ( pob->query_wiz_flag()
	|| sscanf(file_name(pob),WIZ_DIR"%*s") ) )
	|| (this_player(1) && wizardp(this_player(1))) )
		return 0;
#endif

	if(!stringp(cls))
		return 0;

	if(!mapp(make_weapon_ability) || undefinedp(make_weapon_ability[cls]))
		return notify_fail(sprintf("%s������������ֱ�����\n", name()));

	make_weapon_ability[cls]++;
	save();

	return 1;
}

protected void find_banghui_master()
{
	if(!objectp(master = query_bh_master_ob()))
	{
		init_banghui_data();
		if(!objectp(master = query_bh_master_ob()))
			return;
	}

	if(!(b_id = master->query_banghui_id())
	|| !(b_name = master->query_banghui_name()) )
		master = 0;
}

protected int set_sell_rate(int n)
{
	if(!intp(n) || (n < 0) || (n > MAX_SELL_RATE))
		return 0;

	sell_rate = n;
	return 1;
}

void init()
{
	::init();
	add_action("do_sell", "sell");
	add_action("do_fix",({"fix","xiuli"}));
	add_action("do_epurate", "ti");	// ������������
	add_action("do_make_self", "dazao");
	add_action("do_ronghe", "ronghe");
}

int do_sell(string arg)
{
	object ob,me = this_player();
	int temp,value,mangle, save_value;
    
	if(!environment() || base_name(environment()) != query("startroom"))
		return 0;
	if(!master)
	{
		find_banghui_master();
		if(!objectp(master))
			return notify_fail("�˰��ɿ������ĳ��ִ�����֪ͨ��ʦ�����\n");
	}

	if( me->is_busy() )
		return notify_fail(BUSY_MESSAGE);

	if( !arg || ! ob = present(arg, this_player()) )
		return notify_fail( "��Ҫ��ʲô��Ʒ��\n" );

	if(!ob->is_weapon() && !ob->is_armor())
		return notify_fail(name()+"ҡҡͷ˵����������ֻ�չ������ͻ��ס���\n");

	if(ob->query("no_drop") || ob->query("no_sell"))
		return notify_fail("����������������\n");

	if(ob->is_weapon())
	{
		temp = ob->query("weapon_prop/damage");

		if(ob->is_self_make_weapon())
			value = ob->query("value");

		else if(temp <= 50) /* ��ͨ�������� value ��ۡ�*/
		{
			if(ob->query("base_value")) /* combined ob */
				value = ob->value();
			else
				value = ob->query("value");
			if( !value )
				return notify_fail("����������ֵǮ��\n");
			if(value < 10)
				return notify_fail(ob->query("name")+"��ֵ̫�ͣ��ⲻ�ա�\n");
		}

		else
			value = temp * WEAPON_VALUE;

		value = value*sell_rate/100;
		save_value = value*(MAX_SELL_RATE - sell_rate)/100;

		mangle = ob->query("weapon_mangle");
		value = value*(W_MAX_MANGLE-mangle)/W_MAX_MANGLE;

		if(value < 10)
			return notify_fail(sprintf("%s˵������%s�Ѿ���ֵǮ�ˡ���\n",
				this_object()->name(),ob->name()));

		if(mangle == W_MAX_MANGLE)
			return notify_fail(sprintf("%s˵������%s�Ѿ��ƾɵ�һǮ��ֵ�ˡ���\n",
				this_object()->name(),ob->name()));
		else
			write(sprintf("���%s�������õ�%s��\n",ob->name(),chinese_value(value)));

		if(mangle >= W_MAX_MANGLE/2)
			write(sprintf("%s˵������%s�Ѿ��ƾɵĲ��������ˣ�ֻ��ֵ�⼸��Ǯ�ˡ���\n",
				this_object()->name(),ob->name()));
		else if(mangle >= W_MAX_MANGLE/5)
			write(sprintf("%s˵������%s��һЩ�ƾɣ�����ֻ��ֵ��ЩǮ����\n",
				this_object()->name(),ob->name()));
		else if(mangle >0)
			write(sprintf("%s˵������%s��΢��һ���𻵣������Ǯ�Ѿ������ˡ���\n",
				this_object()->name(),ob->name()));

		pay_player(me, value, ob->query_credit_point_flag()?1:0);
		if(ob->query("equipped"))
			ob->unequip();
		destruct(ob);

		// ��۲��ִ�����ɽ��
		if(save_value)
			master->save_to_treasury(save_value);

		return 1;
	}

	else if(ob->is_armor())
	{
		temp = ob->query("armor_prop/armor");
		if(temp <= 50) /* ��ͨ���ף��� value ��ۡ�*/
		{
			value = ob->query("value");
			if( !value )
				return notify_fail("����������ֵǮ��\n");
			if(value < 10)
				return notify_fail(ob->query("name")+"��ֵ̫�ͣ��ⲻ�ա�\n");
		}

		else
			value = temp * ARMOR_VALUE;

		value = value*sell_rate/100;
		save_value = value*(MAX_SELL_RATE - sell_rate)/100;

		mangle = ob->query("armor_mangle");
		value = value*(A_MAX_MANGLE-mangle)/A_MAX_MANGLE;

		if(value < 10)
			return notify_fail(sprintf("%s˵������%s�Ѿ���ֵǮ�ˡ���\n",
				this_object()->name(),ob->name()));

		if(mangle == A_MAX_MANGLE)
			return notify_fail(sprintf("%s˵������%s�Ѿ��ƾɵ�һǮ��ֵ�ˡ���\n",
				this_object()->name(),ob->name()));
		else
			write(sprintf("���%s�������õ�%s��\n",ob->name(),chinese_value(value)));

		if(mangle >= A_MAX_MANGLE/2)
			write(sprintf("%s˵������%s�Ѿ��ƾɵĲ��������ˣ�ֻ��ֵ�⼸��Ǯ�ˡ���\n",
				this_object()->name(),ob->name()));
		else if(mangle >= A_MAX_MANGLE/5)
			write(sprintf("%s˵������%s��һЩ�ƾɣ�����ֻ��ֵ��ЩǮ����\n",
				this_object()->name(),ob->name()));
		else if(mangle >0)
			write(sprintf("%s˵������%s��΢��һ���𻵣������Ǯ�Ѿ������ˡ���\n",
				this_object()->name(),ob->name()));

		pay_player(me, value, ob->query_credit_point_flag()?1:0);
		if(ob->query("equipped"))
			ob->unequip();
		destruct(ob);

		if(save_value)
			master->save_to_treasury(save_value);

		return 1;
	}
	return 0;
}

int do_fix(string arg)
{
	object me = this_player(),ob;
	int mangle,value,fee,f;

	if(!master)
	{
		find_banghui_master();
		if(!objectp(master))
			return notify_fail("�˰��ɿ������ĳ��ִ�����֪ͨ��ʦ�����\n");
	}

	if(!arg || !ob = present(arg,me))
		return notify_fail(this_object()->name()+"������˵��������Ҫ����ʲô����\n");

	if(!ob->is_weapon() && !ob->is_armor())
		return notify_fail(this_object()->name()+"ҡҡͷ˵����������ֻ��������ͻ��ס���\n");

	if(ob->query("base_value")) /* combined ob */
		value = ob->value();
	else
		value = ob->query("value");

	if( !value )
		return notify_fail(this_object()->name()+"˵�����ⶫ����ֵǮ����ʲô���������ˣ�\n");
	if(value < 10)
		return notify_fail(this_object()->name()+
			"˵����"+ob->name()+"ֵ���˼���Ǯ���ⲻ�ޡ�\n");

	if(ob->is_weapon())
	{
		mangle = ob->query("weapon_mangle");

		if(!mangle)
			return notify_fail(this_object()->name()+"˵����ո�µ�"+
				ob->name()+"����ʲô��\n");

		if(me->query_banghui_id() == b_id)
		{
			ob->delete("weapon_mangle");
			write(sprintf("%s���ͷ˵����%s�޺��ˣ�������Ϊ����%s�������\n",
				name(), ob->name(), b_name));
			return 1;
		}

		fee = value/W_MAX_MANGLE*mangle;
		if(fee < MIN_FEE)
			fee = MIN_FEE;

		if(!f=player_pay(me,fee) || f == 2)
			return notify_fail(this_object()->name()+"˵�����������������Ҫ"+
				chinese_value(fee)+"�������ϵ�Ǯ������\n");

		else
		{
			ob->delete("weapon_mangle");
			write(sprintf("%s˵������%s�޺��ˣ������һ��%s�������ܽ���Ҳ�����ף������������ˡ���\n",
				this_object()->name(),ob->name(),chinese_value(fee)));
			return 1;
		}
	}

	else
	{
		mangle = ob->query("armor_mangle");

		if(!mangle)
			return notify_fail(this_object()->name()+"˵����ո�µ�"+
				ob->name()+"����ʲô��\n");

		if(me->query_banghui_id() == b_id)
		{
			ob->delete("armor_mangle");
			write(sprintf("%s���ͷ˵����%s�޺��ˣ���������Ϊ����%s�������\n",
				name(), ob->name(), b_name));
			return 1;
		}

		fee = value/A_MAX_MANGLE*mangle;
		if(fee < MIN_FEE)
			fee = MIN_FEE;

		if(!f=player_pay(me,fee) || f == 2)
			return notify_fail(this_object()->name()+"˵�����������������Ҫ"+
				chinese_value(fee)+"�������ϵ�Ǯ������\n");

		else
		{
			ob->delete("armor_mangle");
			write(sprintf("%s˵������%s�޺��ˣ������һ��%s�������ܽ���Ҳ�����ף������������ˡ���\n",
				this_object()->name(),ob->name(),chinese_value(fee)));
			return 1;
		}
	}
}

// NEW:
void setup()
{
	mapping inq;

	::setup();

	if(!query("no_kill"))
		set("no_kill",1);

	if(!master)
		find_banghui_master();

	if(!mapp(inq = this_object()->query("inquiry",1)))
		inq = ([ "����" : (: call_other, this_object(), "identify_mine_stone" :) ]);
	else if(undefinedp(inq["����"]))
		inq += ([ "����" : (: call_other, this_object(), "identify_mine_stone" :) ]);
	else
		return;

	this_object()->set("inquiry",inq);
}

string identify_mine_stone(object who)
{
	object *inv;

	if(!who)
		return 0;

	if(!sizeof(inv = filter_array(all_inventory(who), (: $1->is_mine_stone() && !$1->query_check() :))))
		return "������û����Ҫ�����Ŀ�ʯ��\n";

	inv->set_check_flag(1);
	return sprintf("����������%s��\n",!random(3)?"��ûʲôֵǮ�Ķ���":"");
}

int do_epurate(string arg)
{
	object tg, ob, me = this_player();
	string mcs, cmcs;
	int ew, value, rtn;

	if(!master)
	{
		find_banghui_master();
		if(!objectp(master))
			return notify_fail("�˰��ɿ������ĳ��ִ�����֪ͨ��ʦ�����\n");
	}

	if(do_nothing)
		return notify_fail(sprintf("%s˵�����Ȼ������æ���ء�\n", name()));

	if(!arg || !objectp(ob = present(arg, me)))
		return notify_fail("��Ҫ����ʲô��\n");

	if(ob->is_mine_stone())		// ������ʯ
	{
		if(!ob->query_check())
			ob->set_check_flag(1);

		if( !(mcs = ob->query_mine_class())
		|| !(cmcs = MINE_D->chinese_mine_class(mcs))
		|| (member_array(mcs, can_epurate) == -1) )
			return notify_fail(sprintf("%sҡҡͷ˵�������ﲻ���κο���ɷݡ�\n", name()));

		if( (ew = ob->query_eff_weight()) < 1 )
			return notify_fail(sprintf("%sҡҡͷ˵�������ﺬ��%s̫���ˣ�û��������\n", name(), cmcs));

		if(!objectp(tg = MINE_D->query_mine_class_up_ob(mcs)))
			return notify_fail(sprintf("%sҡҡͷ˵��������ʯû��������\n", name()));

		if(me->query_banghui_id() != b_id)
		{
			value = MINE_D->query_mine_class_value(tg->query_mine_class()) * ew * 3 / 10;
			if(value < 1)
				value = 1;

			if(!(rtn=player_pay(me,value)) || (rtn == 2))
			{
				destruct(tg);
				return notify_fail(sprintf("%s˵������������ʯ���%s��Ҫ%s��\n",
					name(), cmcs, chinese_value(value)));
			}
		}

		do_nothing = 1;
		message_vision("$N����$n���ͷ˵������һ�����\n", this_object(), me);

		call_out("epurate_it", 1+random(2), me, ob, tg);
		return 1;
	}

	else if(ob->is_iron_class_res())	// ����
	{
		int upq;

		if( !(mcs = ob->query_mine_class())
		|| !(cmcs = MINE_D->chinese_mine_class(mcs))
		|| (member_array(mcs, can_epurate) == -1)
		|| !(upq = MINE_D->query_mine_class_up_quantity(mcs)) )
			return notify_fail(sprintf("%sҡҡͷ˵�����ⶫ��û���پ����ˡ�\n", name()));

		if( (ew = ob->query_weight()/100) < upq )
			return notify_fail(sprintf("%sҡҡͷ˵������%s����������Ҫ %d �������%s������\n",
				cmcs, upq, cmcs));

		if(!objectp(tg = MINE_D->query_mine_class_up_ob(mcs)))
			return notify_fail(sprintf("%sҡҡͷ˵��������û����%s���о����ˡ�\n", name(), cmcs));

		ew /= upq;

		if(me->query_banghui_id() != b_id)
		{
			value = (MINE_D->query_mine_class_value(tg->query_mine_class()) -
				MINE_D->query_mine_class_value(mcs)*upq) * ew/2;

			if(value < 10)
				value = 10;

			if(!(rtn=player_pay(me,value)) || (rtn == 2))
			{
				destruct(tg);
				return notify_fail(sprintf("%s˵���������%s���о�����Ҫ%s��\n",
					name(), cmcs, chinese_value(value)));
			}
		}

		destruct(ob);
		tg->set_weight(ew*100);
		if(!tg->move(me) && !tg->move(environment()))
		{
			destruct(tg);
			return notify_fail("�쳣���أ�����ʦ����ɡ�\n");
		}

		rong_he(me, tg);
		write(sprintf("%s���ͷ˵�������ˣ���ȥ�ɡ�\n", name()));
		return 1;
	}

	else
		return notify_fail(sprintf("%sҡҡͷ˵�����ⶫ��û��������\n", name()));
}

protected void epurate_it(object me, object ob, object tg)
{
	int ew;

	if(!ob || !me || !tg || (environment(me) != environment()))
	{
		if(tg)
			destruct(tg);
		do_nothing = 0;
		return;
	}

	ew = ob->query_eff_weight()*9/10;
	if(ew < 1)
		ew = 1;

	if(ob->query_mine_class() == BLACK_IRON)
		tg->set_sum(ew);
	else
		tg->set_weight(ew*100);

	destruct(ob);
	if(!tg->move(me) && !tg->move(environment()))
		destruct(tg);

	rong_he(me, tg);
	do_nothing = 0;
	message_vision("$N����$n���ͷ˵�����������ˣ���ȥ�ɡ�\n", this_object(), me);
}

int do_ronghe(string arg)
{
	object me = this_player(), ob;

	if(!stringp(arg)
	|| !sizeof(arg)
	|| !objectp(ob = present(arg, me))
	|| !ob->is_iron_class_res() )
		return notify_fail("��Ҫ�ۺ�ʲô��\n");

	rong_he(me, ob);
	write(sprintf("%s���ͷ˵�������ˡ�\n", name()));
	return 1;
}

protected void rong_he(object me, object ob)
{
	object *inv;
	string cms;
	int wt;

	if(!objectp(me)
	|| !objectp(ob)
	|| !ob->is_iron_class_res()
	|| !(cms = ob->query_mine_class()) )
		return;

	if( !sizeof(inv = filter_array(all_inventory(me), (: ($1->is_iron_class_res())
		&& ($1->query_mine_class() == $(cms))
		&& ($1 != $(ob)) :))) )
		return;

	if(cms == BLACK_IRON)
	{
		foreach(object tmp in inv)
		{
			wt += tmp->query_sum();
			destruct(tmp);
		}

		ob->add_sum(wt);
		return;
	}

	foreach(object tmp in inv)
	{
		wt += tmp->query_weight();
		destruct(tmp);
	}

	wt += ob->query_weight();
	ob->set_weight(wt);
}

nomask int do_make_self(string arg)
{
	object me = this_player(1), *inv, ob;
	int vl;

	if(!master)
	{
		find_banghui_master();
		if(!objectp(master))
			return notify_fail("�˰��ɿ������ĳ��ִ�����֪ͨ��ʦ�����\n");
	}

	if(me->query_banghui_id() != b_id)
		return notify_fail(sprintf("%sҡҡͷ˵�����㲻������%s���ˡ�\n", name(), b_name));

#ifdef WIZARD_FLAG
	if(wizardp(me))
		return notify_fail("��ʦ��������������\n");
	if(query_wiz_flag() && !wizardp(me))
		return notify_fail(sprintf("%sҡҡͷ˵�����Ҳ���Ϊ��Ҵ��������\n", name()));
#endif

	if(!arg)	// ��ʼ�������
	{
		string out, *can;

		if(!make_weapon_ability || !sizeof(make_weapon_ability))
			return notify_fail(sprintf("%sҡҡͷ˵�����Ҳ�����������\n", name()));

		if(!sizeof(inv = filter_array(all_inventory(me), (: is_money :))))
			return notify_fail("���������Ҫ 5 ��������������ûǮ��\n");

		foreach(object tmp in inv)
			vl += tmp->value();

		if(vl < 500)
			return notify_fail("���������Ҫ 5 ��������������Ǯ������\n");

		can = keys(make_weapon_ability);
		out = "�ɴ���ı������ࣺ\n";
		for(int i=0; i<sizeof(can); i++)
			out += sprintf((string)i+1+". "+res_cost_desc[can[i]],
				res_cost[can[i]]);
		out += sprintf("��ѡ����Ҫ����ı�������[1-%d, q�˳�]��\n", sizeof(can));
		write(out);
		input_to( (: select_weapon_class :), me, out);
		return 1;
	}

	else
	{
		int damage, amount, pay, n, cost;

		if(!objectp(ob = present(arg, me)) || !ob->is_self_make_weapon())
			return notify_fail("��Ҫ�����ļ�������\n");

		damage = ob->query("weapon_prop/damage") - ob->query_base_damage() + 1;

		vl = damage*damage;

		if(!n = sizeof(inv = filter_array(all_inventory(me),
			(: $1->is_iron_class_res() && ($1->query_mine_class() == BLACK_IRON) :))))
			return notify_fail(sprintf("����%s��Ҫ�� %d Ǯ������������û�С�\n", ob->name(), vl));

		foreach(object tmp in inv)
			amount += tmp->query_sum();

		if(amount < vl)
			return notify_fail(sprintf("����%s��Ҫ�� %d Ǯ�����������ϲ�����\n", ob->name(), vl));

		cost = vl*70/100;
		if(cost < 1)
			cost = 1;

		if(!(pay = player_pay(me, cost*100)) || (pay == 2) )
			return notify_fail(sprintf("����%s��Ҫ���� %d ��������\n", ob->name(), vl));

		for(int i=0; i<n; i++)
		{
			amount = inv[i]->query_sum();

			if(amount == vl)
			{
				destruct(inv[i]);
				break;
			}

			if(amount > vl)
			{
				inv[i]->add_sum(-vl);
				break;
			}

			else
			{
				vl -= amount;
				destruct(inv[i]);
			}
		}

		ob->add("weapon_prop/damage", 1);
		ob->set_weapon_weight();
		ob->set_weapon_value();
		write(sprintf("%s���ͷ˵����������ˣ���ӭ�´��ٹ�ˡ�\n", name()));
		return 1;
	}
}

protected void select_weapon_class(string str, object me, string out)
{
	object ob, *inv;
	int cost, wt, n, i, black;

	if(!me || (environment(me) != environment()) )
		return;

	if(!stringp(str) || !sizeof(str))
	{
		tell_object(me, out);
		input_to( (: select_weapon_class :), me, out);
		return;
	}

	if((str[0] == 'q') || (str[0] == 'Q'))
	{
		tell_object(me, "ok.\n");
		return;
	}

	if(!sscanf(str, "%d", i) || (i<1) || (i>sizeof(make_weapon_ability)))
	{
		tell_object(me, out);
		input_to( (: select_weapon_class :), me, out);
		return;
	}

	ob = new(std_self_weapon[make_weapon_ability[i-1]]);
	cost = res_cost[make_weapon_ability[i-1]];

	if(!ob)
	{
		tell_object(me, "����������ִ�����֪ͨ��ʦ����\n");
		return;
	}

	if(!n = sizeof(inv = filter_array(all_inventory(me),
		(: $1->is_iron_class_res() && ($1->query_mine_class() == STEEL_RES) :))))
	{
		black = 1;
		if(!n = sizeof(inv = filter_array(all_inventory(me),
			(: $1->is_iron_class_res() && ($1->query_mine_class() == BLACK_IRON) :))))
			{
				destruct(ob);
				tell_object(me, sprintf("�������������Ҫ %d ��ԭ�ϣ�������û�С�\n", cost));
				return;
			}
	}

	if(black)
	{
		for(i=0; i<n; i++)
		{
			wt += inv[i]->query_sum();
			if(wt >= cost*10000)
				break;
		}

		if(wt < cost*10000)
		{
			destruct(ob);
			tell_object(me, sprintf("�������������Ҫ %d ��ԭ�ϣ������ϲ�����\n", cost));
			return;
		}

		ob->set("material", BLACK_IRON);
	}

	else
	{
		for(i=0; i<n; i++)
		{
			wt += inv[i]->query_weight();
			if(wt >= cost*1000)
				break;
		}

		if(wt < cost*1000)
		{
			destruct(ob);
			tell_object(me, sprintf("�������������Ҫ %d ��ԭ�ϣ������ϲ�����\n", cost));
			return;
		}

		ob->set("material", STEEL_RES);
	}

	ob->set_require_res(cost*1000);

	tell_object(me, "
��Ҫ������ʹ����ɫ�����������¿��Ʒ���
ע�⣺���Ʒ���ĸҪ��д��

$RED$ - ��ɫ		$HIR$ - ����ɫ
$GRN$ - ��ɫ		$HIG$ - ����ɫ
$YEL$ - ����ɫ		$HIY$ - ��ɫ
$BLU$ - ����ɫ		$HIB$ - ��ɫ
$MAG$ - ǳ��ɫ		$HIM$ - �ۺ�ɫ
$CYN$ - ����ɫ		$HIC$ - ����ɫ
$WHT$ - ǳ��ɫ		$HIW$ - ��ɫ

�趨����������[1-6������, q�˳�]��\n");
	input_to( (: get_self_weapon_name :), me, ob);
}

protected void get_self_weapon_name(string str, object me, object ob)
{
	int i;
	string tmp;

	if(!me || !ob || (environment(me) != environment()))
	{
		if(ob)
			destruct(ob);
		return;
	}

	if(!stringp(str) || !sizeof(str))
	{
		tell_object(me, "
��Ҫ������ʹ����ɫ�����������¿��Ʒ���
ע�⣺���Ʒ���ĸҪ��д��

$RED$ - ��ɫ		$HIR$ - ����ɫ
$GRN$ - ��ɫ		$HIG$ - ����ɫ
$YEL$ - ����ɫ		$HIY$ - ��ɫ
$BLU$ - ����ɫ		$HIB$ - ��ɫ
$MAG$ - ǳ��ɫ		$HIM$ - �ۺ�ɫ
$CYN$ - ����ɫ		$HIC$ - ����ɫ
$WHT$ - ǳ��ɫ		$HIW$ - ��ɫ

�趨����������[1-6������, q�˳�]��\n");
		input_to( (: get_self_weapon_name :), me, ob);
		return;
	}

	if( (str[0] == 'q') || (str[0] == 'Q') )
	{
		destruct(ob);
		tell_object(me, "ok.\n");
		return;
	}

	str = clr_ansi(str);
	str = replace_string(str, "$RED$", RED);
	str = replace_string(str, "$GRN$", GRN);
	str = replace_string(str, "$YEL$", YEL);
	str = replace_string(str, "$BLU$", BLU);
	str = replace_string(str, "$MAG$", MAG);
	str = replace_string(str, "$CYN$", CYN);
	str = replace_string(str, "$WHT$", WHT);
	str = replace_string(str, "$HIR$", HIR);
	str = replace_string(str, "$HIG$", HIG);
	str = replace_string(str, "$HIY$", HIY);
	str = replace_string(str, "$HIB$", HIB);
	str = replace_string(str, "$HIM$", HIM);
	str = replace_string(str, "$HIC$", HIC);
	str = replace_string(str, "$HIW$", HIW);
	str = replace_string(str, "$NOR$", NOR);
	str += NOR;

	tmp = clr_ansi(str);

	if(((i = sizeof(tmp)) < 2) || (i > 12))
	{
		tell_object(me, "[�������Ʊ���ʹ�� 1-6 ������]\n�趨����������[1-6������, q�˳�]��\n");
		input_to( (: get_self_weapon_name :), me, ob);
		return;
	}

	while(i--)
	{
		int section;

                if( tmp[i]<128 )
		{
			tell_object(me, "[�������Ʊ���ʹ�ú���]\n�趨����������[1-6������, q�˳�]��\n");
			input_to( (: get_self_weapon_name :), me, ob);
			return;
                }

		if( i%2==0 )
		{
			section = tmp[i] - 160;

			if( (section < 16)
			|| (section > 87) )
			{
				tell_object(me, "[�������Ʊ���ʹ�ó��ú���]\n�趨����������[1-6������, q�˳�]��\n");
				input_to( (: get_self_weapon_name :), me, ob);
				return;
			}
		}
	}

	ob->set("name", str);
	tell_object(me, "
�趨������ ID
  ������ ID ����ʹ�� 4 ������
  ÿ��������� 7 ��Ӣ����ĸ���
���趨������ ID [q�˳�]��\n");
	input_to( (: get_self_weapon_id :), me, ob);
}

protected void get_self_weapon_id(string str, object me, object ob)
{
	string *words;
	int n;

	if(!me || !ob || (environment(me) != environment()))
	{
		if(ob)
			destruct(ob);
		return;
	}

	if(!stringp(str) || !sizeof(str))
	{
		tell_object(me, "
�趨������ ID
  ������ ID ����ʹ�� 4 ������
  ÿ��������� 7 ��Ӣ����ĸ���
���趨������ ID [q�˳�]��\n");
		input_to( (: get_self_weapon_id :), me, ob);
		return;
	}

	if( (sizeof(str) == 1) && ((str[0] == 'q') || (str[0] == 'Q')) )
	{
		destruct(ob);
		tell_object(me, "ok.\n");
		return;
	}

	if( !(n = sizeof(words = explode(str, " ") - ({ "" }))) || (n > 4) )
	{
		tell_object(me, "
  ������ ID ���ֻ��ʹ�� 4 ��Ӣ�ĵ���
                         ~~~~
  ÿ��������� 7 ��Ӣ����ĸ���
�趨������ ID [q�˳�]��\n");
		input_to( (: get_self_weapon_id :), me, ob);
		return;
	}

	foreach(string tmp in words)
	{
		if(sizeof(tmp) > 7)
		{
			tell_object(me, "
  ������ ID ���ֻ��ʹ�� 4 ��Ӣ�ĵ���
  ÿ��������� 7 ��Ӣ����ĸ���
               ~~~~
�趨������ ID [q�˳�]��\n");
			input_to( (: get_self_weapon_id :), me, ob);
			return;
		}

		if(!regexp(tmp, "^[a-zA-Z]+$"))
		{
			tell_object(me, "
  ������ ID ���ֻ��ʹ�� 4 ��Ӣ�ĵ���
  ÿ��������� 7 ��Ӣ����ĸ���
                   ~~~~~~~~
�趨������ ID [q�˳�]��\n");
			input_to( (: get_self_weapon_id :), me, ob);
			return;
		}
	}

	str = lower_case(str);

	ob->set_name(ob->query("name"), ({ str }) );

	tell_object(me, "���趨������������\n���������ݲ��ܳ�������\n��ÿ�в�����20������
������('.'�������룬'q'�˳�)��\n------------------------------------------------------\n");
	input_to((: get_self_weapon_desc :), me, ob, "");
}

protected void get_self_weapon_desc(string str, object me, object ob, string desc)
{
	if(!me || !ob || (environment(me) != environment()))
	{
		if(ob)
			destruct(ob);
		return;
	}

	if(!stringp(str) || !sizeof(str))
	{
		input_to((: get_self_weapon_desc :), me, ob, desc);
		return;
	}

	if( (str[0] == 'q') || (str[0] == 'Q') )
	{
		destruct(ob);
		tell_object(me, "ok.\n");
		return;
	}

	if(str[0] == '.')	// ��������
	{
		if( !sizeof(desc) )
		{
			ob->set("long", 0);
			tell_object(me, "
�趨װ��˱���ʱ����Ϣ
 $N Ϊװ��˱�������
 $n Ϊ�˱���
���磺
  װ����Ϣ�趨Ϊ��$N�ó�һ��$n�������е���������
  װ��������˾ͻῴ���������ó�һ����а�̽��������е���������

���趨�˱�����װ����Ϣ[�������25������, q �˳�]��
");
			input_to((: get_self_weapon_wield_msg :), me, ob);
			return;
		}

		if( sizeof(explode(desc, "\n")) > 3)
		{
			tell_object(me, HBCYN HIG"���������������ݲ��ܳ������У��������趨����������
���������ݲ��ܳ�������\n��ÿ�в�����20������
������('.'�������룬'q'�˳�)��\n------------------------------------------------------\n"NOR);
			input_to((: get_self_weapon_desc :), me, ob, "");
			return;
		}

		if(desc[<1] != '\n')
			desc += "\n";
		ob->set("long", desc);
		tell_object(me, "
�趨װ��˱���ʱ����Ϣ
 $N Ϊװ��˱�������
 $n Ϊ�˱���
���磺
  װ����Ϣ�趨Ϊ��$N�ó�һ��$n�������е���������
  װ��������˾ͻῴ���������ó�һ����а�̽��������е���������

���趨�˱�����װ����Ϣ[�������25������, q �˳�]��
");
		input_to((: get_self_weapon_wield_msg :), me, ob);
		return;
	}

	if(strsrch(str, '\n'))
	{
		int n;
		string *tmp;

		n = sizeof(tmp = explode(str, "\n"));
		for(int i=0; i<n; i++)
			if(strlen(tmp[i]) > 40)
			{
				tell_object(me, HBCYN HIG"ÿһ�в��ܳ�����ʮ�������֣�����������ղ���������ݣ�\n");
				input_to((: get_self_weapon_desc :), me, ob, desc);
				return;
			}

			if( sizeof(explode(desc, "\n")) > 3)
			{
				tell_object(me, HBCYN HIG"���������������ݲ��ܳ������У��������趨����������
���������ݲ��ܳ�������\n��ÿ�в�����20������
������('.'�������룬'q'�˳�)��\n------------------------------------------------------\n"NOR);
				input_to((: get_self_weapon_desc :), me, ob, "");
				return;
			}
	}

	else
	{
		if(strlen(str) > 40)
		{
			tell_object(me, HBCYN HIG"ÿһ�в��ܳ�����ʮ�������֣�����������ղ���������ݣ�\n");
			input_to((: get_self_weapon_desc :), me, ob, desc);
			return;
		}

		if( sizeof(explode(desc, "\n")) > 2)
		{
			tell_object(me, HBCYN HIG"���������������ݲ��ܳ������У��������趨����������
���������ݲ��ܳ�������\n��ÿ�в�����20������
������('.'�������룬'q'�˳�)��\n------------------------------------------------------\n"NOR);
			input_to((: get_self_weapon_desc :), me, ob, "");
			return;
		}
	}

	desc += str + "\n";
	input_to((: get_self_weapon_desc :), me, ob, desc);
}

protected void get_self_weapon_wield_msg(string str, object me, object ob)
{
	if(!me || !ob || (environment(me) != environment()))
	{
		if(ob)
			destruct(ob);
		return;
	}

	if(!stringp(str) || !sizeof(str))
	{
		tell_object(me, "
�趨װ��˱���ʱ����Ϣ
 $N Ϊװ��˱�������
 $n Ϊ�˱���
���磺
  װ����Ϣ�趨Ϊ��$N�ó�һ��$n�������е���������
  װ��������˾ͻῴ���������ó�һ����а�̽��������е���������

���趨�˱�����װ����Ϣ[�������25������, q �˳�]��
");
		input_to((: get_self_weapon_wield_msg :), me, ob);
		return;
	}

	if( (str[0] == 'q') || (str[0] == 'Q') )
	{
		destruct(ob);
		tell_object(me, "ok.\n");
		return;
	}

	if(sizeof(str) > 50)
	{
		tell_object(me, "
** ��Ϣ�������25������ **

�趨װ��˱���ʱ����Ϣ
 $N Ϊװ��˱�������
 $n Ϊ�˱���

���趨�˱�����װ����Ϣ[�������25������, q �˳�]��
");
		input_to((: get_self_weapon_wield_msg :), me, ob);
		return;
	}

	if(str[<1] != '\n')
		str += "\n";

	ob->set("wield_msg", str);

	tell_object(me, "
�趨���´˱���ʱ����Ϣ
 $N Ϊ���´˱�������
 $n Ϊ�˱���
���磺
  ��Ϣ�趨Ϊ��$N�����е�$n��������Ľ��ʡ�
  ���´˱������˾ͻῴ�������������е���а�̽���������Ľ��ʡ�

���趨���´˱�������Ϣ[�������25������, q �˳�]��
");
	input_to((: get_self_weapon_unwield_msg :), me, ob);
}

protected void get_self_weapon_unwield_msg(string str, object me, object ob)
{
	object *inv;
	int n, cost, pay, wt, black;
	string cls;

	if(!me || !ob || (environment(me) != environment()))
	{
		if(ob)
			destruct(ob);
		return;
	}

	if(!stringp(str) || !sizeof(str))
	{
		tell_object(me, "
�趨���´˱���ʱ����Ϣ
 $N Ϊ���´˱�������
 $n Ϊ�˱���
���磺
  ��Ϣ�趨Ϊ��$N�����е�$n��������Ľ��ʡ�
  ���´˱������˾ͻῴ�������������е���а�̽���������Ľ��ʡ�

���趨���´˱�������Ϣ[�������25������, q �˳�]��
");
		input_to((: get_self_weapon_unwield_msg :), me, ob);
		return;
	}

	if( (str[0] == 'q') || (str[0] == 'Q') )
	{
		destruct(ob);
		tell_object(me, "ok.\n");
		return;
	}

	if(sizeof(str) > 50)
	{
		tell_object(me, "
** ��Ϣ�������25������ **

�趨���´˱���ʱ����Ϣ
 $N Ϊ���´˱�������
 $n Ϊ�˱���

���趨���´˱�������Ϣ[�������25������, q �˳�]��
");
		input_to((: get_self_weapon_unwield_msg :), me, ob);
		return;
	}

	if(str[<1] != '\n')
		str += "\n";

	ob->set("unwield_msg", str);

	if(!(pay = player_pay(me, 500)) || (pay == 2) )
	{
		tell_object(me, sprintf("����˱�����Ҫ���� 5 �������������ϵ�Ǯ������\n"));
		destruct(ob);
		return;
	}

	cost = ob->query_require_res();

	if(!n = sizeof(inv = filter_array(all_inventory(me),
		(: $1->is_iron_class_res() && ($1->query_mine_class() == STEEL_RES) :))))
	{
		black = 1;
		if(!n = sizeof(inv = filter_array(all_inventory(me),
			(: $1->is_iron_class_res() && ($1->query_mine_class() == BLACK_IRON) :))))
			{
				destruct(ob);
				tell_object(me, sprintf("�������������Ҫ %d ��ԭ�ϣ�������û�С�\n", cost/10000));
				return;
			}
	}

	if(black)
	{
		for(int i=0; i<n; i++)
		{
			wt += inv[i]->query_sum();
			if(wt >= cost)
				break;
		}

		if(wt < cost)
		{
			destruct(ob);
			tell_object(me, sprintf("�������������Ҫ %d ��ԭ�ϣ������ϲ�����\n", cost/10000));
			return;
		}

		for(int i=0; i<n; i++)
		{
			wt = inv[i]->query_sum();

			if(wt == cost)
			{
				destruct(inv[i]);
				break;
			}

			if(wt > cost)
			{
				inv[i]->set_sum(wt - cost);
				break;
			}

			else
			{
				cost -= wt;
				destruct(inv[i]);
			}
		}
	}

	else
	{
		for(int i=0; i<n; i++)
		{
			wt += inv[i]->query_weight();
			if(wt >= cost)
				break;
		}

		if(wt < cost)
		{
			destruct(ob);
			tell_object(me, sprintf("�������������Ҫ %d ��ԭ�ϣ������ϲ�����\n", cost/1000));
			return;
		}

		for(int i=0; i<n; i++)
		{
			wt = inv[i]->query_weight();

			if(wt == cost)
			{
				destruct(inv[i]);
				break;
			}

			if(wt > cost)
			{
				inv[i]->set_weight(wt - cost);
				break;
			}

			else
			{
				cost -= wt;
				destruct(inv[i]);
			}
		}
	}

	cls = ob->query("skill_type");
	if( (cls == "hammer") && (ob->query("flag") & SECONDARY) )
		cls = "dhammer";

	n = make_weapon_ability[cls] * 1.2;
	n = random(n*0.6) + n*0.7;
	if(n > 0)
		ob->add("weapon_prop/damage", n);

	ob->set_weapon_weight();
	ob->set_weapon_value();

	if( !ob->move(me) && !ob->move(environment()) )
	{
		tell_object(me, sprintf("%s˵�������ò������%s�ˣ�û�취��\n", name(), ob->name()));
		destruct(ob);
		return;
	}

	tell_object(me, sprintf("%s˵����%s������ˣ��������ⲻ���⡣\n", name(), ob->name()));
}
