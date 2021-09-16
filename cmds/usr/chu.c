// /cmds/usr/chu.c
// by Find.

inherit F_CLEAN_UP;

protected int MAX = 20000000;

int main(object me,string arg)
{
	int s_num,value,per_chu,min_value;
	object who;

        if(wizardp(me))
                return notify_fail("巫师不允许参加竞买。\n");

	seteuid(getuid());

	if(!PAWN_D->query_being_meeting())
	{
		object sroom;

		sroom = find_object("/d/changan/selling_room");
		if(!sroom || !sroom->is_selling())
			return 0;

		s_num = atoi(arg);
		if((s_num < 1) || (s_num > MAX))
			return notify_fail("你要出多少两银子竞买正在叫卖的物品？\n");

		if(sroom->accept_chu(me, s_num))
		{
			me->set_temp("be_in_sale_meeting_chu",1);
			return 1;
		}

		return 0;
	}

	if(PAWN_D->query_num_during_meeting() == -1)
		return notify_fail("还没有开始拍卖呢，请等一会儿再出价吧。\n");

	if(PAWN_D->query_unvalid_flag())
		return notify_fail("当前物品已经卖出去了，你等下一件物品吧。\n");

	s_num = atoi(arg);
	if((s_num < 1) || (s_num > MAX))
		return notify_fail("你要出多少两银子购买正在拍卖的物品？\n");

	value = PAWN_D->query_current_value();
	per_chu = PAWN_D->query_min_value_per_chu();
	who = PAWN_D->query_current_user();

	if(who)
	{
		if(who == me)
			return notify_fail("现在的价钱就是你出的，目前还没有人和你争，不用再加价了。\n");
		else
			min_value = to_int(ceil((value+per_chu)/100));
	}
	else
		min_value = to_int(ceil(value/100));

	if(s_num < min_value)
		return notify_fail(sprintf("竞买当前物品至少要出 %d 两银子。\n",min_value));

	if(!pay_from_bank(me,s_num*100,1))
		return notify_fail("你银行里目前没有这么多存款。\n");

	PAWN_D->accept_chujia(me,s_num*100);

	write(sprintf("你出价 %d 两银子参加竞买。\n",s_num));

	me->set_temp("be_in_sale_meeting_chu",1);
	return 1;
}


int help(object me)
{
        write(@HELP
指令格式 : chu <银两数>

此指令用于在拍卖大会期间或其它玩家叫卖时，
对当前的竞买物品出价。

例如：
	chu 1000

你愿出 1000 两白银购买当前正在竞买的物品。
当然首先你银行里要有这么多存款。

HELP
    );
    return 1;
}
