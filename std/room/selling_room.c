// selling_room.c
// by Find.

#include <ansi.h>

inherit ROOM;

#define MY_SAVE_ROOM	"/d/changan/save_room"

protected int MAX = 2000000000;
protected int valid_flag = 0, begin_time, busy, current_value, begin_value, no_accept;
protected object who_sell, selling_ob, save_room, current_buyer;
protected string channel_name = "个人交易";

int is_selling()
{
	if(no_accept)
		return 0;

	return ( who_sell && (environment(who_sell) == this_object()) && objectp(selling_ob));
}

protected void create()
{
	save_room = find_object(MY_SAVE_ROOM);
	if(!save_room)
		save_room = load_object(MY_SAVE_ROOM);
	if(!save_room)
		return;

	if(file_name(this_object()) == "/d/changan/selling_room")
		valid_flag = 1;
}

protected void refresh_objs()
{
	if(save_room)
		save_room->refresh_inv();

	if(current_buyer)
		current_buyer->delete_temp("be_in_sale_meeting_chu");
	current_buyer = 0;
	who_sell = 0;
	selling_ob = 0;
}

protected void stop_selling(int flag)
{
	switch(flag)
	{
		case 1:
			message("channel:psell",sprintf(HIY"\n【%s】由于卖品丢失，这次拍卖中止。\n\n"NOR,
				channel_name), users());
			break;
		case 2:
			message("channel:psell",sprintf(HIY"\n【%s】由于卖主离开，这次拍卖中止。\n\n"NOR,
				channel_name), users());
			break;
		case 3:
			message("channel:psell",sprintf(HIY"\n【%s】由于%s，这次拍卖中止。\n\n"NOR,
				channel_name, current_buyer?who_sell->name()+"长时间无法决定":"长时间无人应价"),
				users());
			break;
		case 4:
			message("channel:psell",sprintf(HIY"\n【%s】由于拍卖大会召开，这次交易被中止。\n\n"NOR,
				channel_name), users());
			break;

		default:
			message("channel:psell",sprintf(HIY"\n【%s】%s取消了拍卖%s的打算。\n\n"NOR,
				channel_name, who_sell->name(), selling_ob?selling_ob->name()+HIY:""),
				users());
	}

	if(objectp(selling_ob) && objectp(who_sell) && (environment(who_sell) == this_object()))
		selling_ob->move(who_sell);

	refresh_objs();
}

protected void do_continue()
{
	if(!selling_ob)
	{
		stop_selling(1);
		return;
	}

	if(!who_sell || (environment(who_sell) != this_object()))
	{
		stop_selling(2);
		return;
	}

	if(time() - begin_time > 120)
	{
		stop_selling(3);
		return;
	}

	call_out("do_continue",3);
}

protected int can_sell(object me)
{
	if(who_sell && (environment(who_sell) == this_object()) && objectp(selling_ob) && (me != who_sell))
		return 0;

	return 1;
}

protected int accept_sell_ob(object ob)
{
	if(!objectp(ob)
	|| !clonep(ob)
#ifdef WIZARD_FLAG
	|| ob->query_wiz_flag()
#endif
	|| is_money(ob)
	|| ob->is_food()
	|| ob->is_liquid()
	|| ob->is_corpse()
	|| ob->is_character()
	|| ob->query("no_drop")
	|| ob->query("no_sell")
	|| (base_name(ob) == "/obj/armor/cloth") )
		return 0;

	return 1;
}

protected void begin_selling(object me, object ob, int value)
{
	string msg;

	if(!save_room)
	{
		save_room = load_object(MY_SAVE_ROOM);
		if(!save_room)
		{
			tell_object(me, "现在无法叫卖，请向管理员报告。\n");
			return;
		}
	}

	if(ob->is_weapon() || ob->is_armor())
		ob->unequip();
	if(!ob->move(save_room))
	{
		tell_object(me, "这样东西不能卖。\n");
		return;
	}

	who_sell = me;
	selling_ob = ob;
	begin_value = value;
	current_value = value;
	current_buyer = 0;
	begin_time = time();

	message("channel:psell",sprintf(HIY"\n【%s】%s开始叫卖自己的%s，起价为 %d 两白银，
%s有感兴趣的请用 <chu 愿出的银两数> 命令竞买。\n\n"NOR,
		channel_name, who_sell->name(1), 
		(msg = selling_ob->query_selling_msg())?sprintf("%s[%s]"+HIY,selling_ob->name(),msg):selling_ob->name()+HIY,
		begin_value, repeat_string(" ", sizeof(channel_name)+3)),
		users());

	call_out("do_continue",3);
}

void init()
{
	if(!valid_flag)
		return;
	add_action("do_sell", "sell");
	add_action("do_accept", "accept");
}

int do_sell(string arg)
{
	object me = this_player(), ob;
	int rtn, value;

	if(PAWN_D->query_being_meeting())
		return notify_fail("拍卖大会期间不能进行私人交易。\n");

#ifdef WIZARD_FLAG
	if(wizardp(me))
		return notify_fail("巫师不允许进行交易。\n");
#endif

	if(!can_sell(me))
		return notify_fail(sprintf("%s正在这里进行交易，请等一会儿。\n", who_sell->name()));

	if(busy)
		return notify_fail("正忙着呢，等一会儿。\n");

	busy = 1;

	if(!stringp(arg) || !sizeof(arg))
	{
		busy = 0;
		return notify_fail("叫卖指令的格式：sell 物品 起始价格(单位：白银)\n  例如：sell sword 30\n  代表：叫卖自己身上的剑，起始价格为 20 两白银\n\n");
	}

	if((arg == "stop") && (me == who_sell))
	{
		remove_call_out("do_continue");
		stop_selling(0);
		write("ok.\n");
		busy = 0;
		return 1;
	}

	if(me == who_sell)
	{
		busy = 0;
		return notify_fail(sprintf("你正在拍卖自己的%s，如要取消请用命令 sell stop。\n", selling_ob->name()));
	}

	if(sscanf(arg, "%s %d", arg, value) != 2)
	{
		busy = 0;
		return notify_fail("叫卖指令的格式：sell 物品 起始价格(单位：白银)\n  例如：sell sword 30\n  代表：叫卖自己身上的剑，起始价格为 20 两白银\n\n");
	}

	if(value < 10)
	{
		busy = 0;
		return notify_fail("这里不能叫卖起始价格少于 10 两白银的物品。\n");
	}

	if(!arg || !objectp(ob = present(arg, me)))
	{
		busy = 0;
		return notify_fail("你要卖什么？\n");
	}

	if(ob->query_credit_point_flag())	// 信用点物品
	{
		busy = 0;
		return notify_fail("这样东西分文不值。\n");
	}

	if(!accept_sell_ob(ob))
	{
		busy = 0;
		return notify_fail("这样东西不能卖。\n");
	}

	if(!(rtn = player_pay(me, 200)) || (rtn == 2))
	{
		busy = 0;
		return notify_fail("每笔交易要缴纳 2 两银子的手续费，你身上的钱不够。\n");
	}
	begin_selling(me, ob, value);

	busy = 0;
	return 1;
}

int valid_leave(object me, string dir)
{
	if(objectp(who_sell) && (me == who_sell))
	{
		remove_call_out("do_continue");
		stop_selling(2);
	}

	return 1;
}

int accept_chu(object me, int value)
{
	if(!previous_object()
	|| (geteuid(previous_object()) != ROOT_UID))
		return 0;

	if(!is_selling())
		return 0;

	if(me == who_sell)
		return notify_fail(sprintf("你正在拍卖自己的%s，如要取消请用命令 sell stop。\n", selling_ob->name()));

	if(me == current_buyer)
		return notify_fail("现在的价格就是你出的，还没有人出比你更高的价格。\n");

	if(current_buyer && (value <= current_value))
		return notify_fail(sprintf("你的出价至少要多于 %d 两白银才有资格竞买。\n", current_value));
	if(!current_buyer && (value < current_value))
		return notify_fail(sprintf("你的出价至少要 %d 两白银才有资格竞买。\n", current_value));

	if(!pay_from_bank(me,value*100,1))
		return notify_fail("你银行里目前没有这么多存款。\n");

	message("channel:psell",sprintf(HIY"\n【%s】%s出价 %d 两白银竞买%s。\n\n"NOR,
		channel_name, me->name(1), value, selling_ob->name()),
		users());

	if(objectp(current_buyer))
		current_buyer->delete_temp("be_in_sale_meeting_chu");

	current_buyer = me;
	current_value = value;

	return 1;
}

int do_accept()
{
	object me = this_player();

	if(!who_sell || !selling_ob || (who_sell != me))
		return 0;

	if(!current_buyer)
		return notify_fail("目前还没有人出价竞买，如要取消请用命令 sell stop。\n");

	no_accept = 1;

	message("channel:psell",sprintf(HIY"\n【%s】%s决定将%s以 %d 两白银的价格卖给%s。\n\n"NOR,
		channel_name, me->name(1), selling_ob->name()+HIY, current_value, current_buyer->name(1)),
		users());

	if(!pay_from_bank(current_buyer,current_value*100,0))
	{
		no_accept = 0;
		notify_fail(sprintf("%s银行存款不够了。\n", current_buyer));
		current_buyer->delete_temp("be_in_sale_meeting_chu");
		current_buyer = 0;
		current_value = begin_value;
		return 0;
	}

	remove_call_out("do_continue");

	if(selling_ob->move(current_buyer))
		tell_object(current_buyer, "-->小伙计跑到你跟前说：给你这是你买的东西。\n");
	else
	{
		selling_ob->move(environment(current_buyer));
		tell_object(current_buyer, "-->小伙计跑到你跟前说：给你这是你买的东西给你放地上了。\n");
	}

	me->add("save_in_bank/silver", to_int(current_value*9/10));
	tell_object(me, sprintf("你的东西共卖得 %d 两白银，除去百分之十的交易税，
其余的银两都存到你的银行账户上了。\n", current_value));

	refresh_objs();

	no_accept = 0;
	return 1;
}

int clean_up()
{
	if(who_sell)
		return 1;

	return ::clean_up();
}

void begin_paimai_meeting()
{
	if(!previous_object()
	|| (geteuid(previous_object()) != ROOT_UID))
		return;

	remove_call_out("do_continue");
	stop_selling(4);
}
