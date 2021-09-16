// /std/room/duchang.c
// by Find.

#define BASE_KAR 20 // 基准福缘
#define BASE_QUOTIETY 10 // 基准胜率
#define MAX_QUOTIETY 50 // 最高胜率
#define MIN_QUOTIETY 5 // 最低胜率
#define KAR_IMPROVE 1 // 福缘每高于基准福缘1点在基准胜率上所增加的胜率点数
#define SKILL_IMPROVE 2 // 每增长10 级赌术在基准胜率上所增加的胜率点数

inherit ROOM;

private void do_result();

private string *dianshu = ({
"
	⊙ 

",
"	⊙

	    ⊙
",
"	⊙
	  ⊙ 
	    ⊙
",
"	⊙  ⊙

	⊙  ⊙
",
"	⊙  ⊙
	  ⊙
	⊙  ⊙
",
"	⊙ ⊙
	⊙ ⊙
	⊙ ⊙
",
});

private int betting,money,win,*points = allocate(3);
private object better;

// 是否能赢?
private int can_win(object me,string kind)
{
	int kar, quotiety, skill;

	kar = me->query_kar();

	if(kar = BASE_KAR)
		quotiety = BASE_QUOTIETY;

	if(kar < BASE_KAR)
		quotiety = BASE_QUOTIETY-(BASE_KAR-kar)*KAR_IMPROVE;

	if(kar > BASE_KAR)
		quotiety = BASE_QUOTIETY+(kar-BASE_KAR)*KAR_IMPROVE;

	skill = me->query_skill("betting",1);

	if(skill && skill >= 10)
		quotiety += skill/10*SKILL_IMPROVE;

	if(quotiety < MIN_QUOTIETY)
		quotiety = MIN_QUOTIETY;

	if(quotiety > MAX_QUOTIETY)
		quotiety = MAX_QUOTIETY;

	switch (kind)
	{
		case "all":
			if(random(100) > quotiety/5 )
				return 0;
			else
				return 2;
			break;
		default :
			if(random(100) > quotiety)
				return 0;
			else
				return 1;
	}
}

// 产生点数
private void bring_point(int n)
{
	int a,b,c;

	switch (n)
	{
		case -2:	// 产生不同的点
			do
			{
				a = random(6)+1;
				b = random(6)+1;
				c = random(6)+1;
			}
			while( (a==b) && (b==c) );
			break;

		case -1:	// 产生小点
			while(a<1||a>6||b<1||b>6||c<1||c>6)
			{
				a = random(6)+1;
				if((9-a) > 6 )
					b = random(6)+1;
				else
					b = random(9-a)+1;
				c = random(10-a-b)+1;
			}
			break;

		case 1:		// 产生大点
			while(a<1||a>6||b<1||b>6||c<1||c>6)
			{
				a = random(6)+1;
				if((10-a-6) > 0)
					b = random(6-(11-a-6)+1)+(11-a-6);
				else
					b = random(6)+1;
				if((11-a-b) == 6)
					c = 6;
				else if((10-a-b) <= 0)
					c = random(6)+1;
				else
					c = random(6-(11-a-b)+1)+(11-a-b);
			}
			break;

		default:	// 相同
			a = random(6)+1;
			b = a;
			c = a;
	}

	points[0] = a;
	points[1] = b;
	points[2] = c;
}

void init()
{
	add_action("do_bet","bet");
}

int do_bet(string arg)
{
	object mtype,me;
	string kind;

	if( betting )
		return notify_fail("这把你赶不上了，等下把吧。\n");
	if (!arg)
		return notify_fail("bet big|small|all  <银子数>\n");

	if(sscanf(arg,"%s %d",kind,money) != 2)
		return notify_fail("bet big|small|all  <银子数>\n");

	me = this_player();

	if(me->is_busy())
		return notify_fail(BUSY_MESSAGE);

	if(!(mtype = present("silver_money", me)) || !is_money(mtype))
		return notify_fail("你身上没有银子。\n");

	if((int)mtype->query_amount() < money)
		return notify_fail("你身上没有那么多银子。\n");

	if(kind != "big" && kind != "small" && kind != "all")
		return notify_fail("你要赌大、赌小还是赌全色？\n");

	if(money < 1)
		return notify_fail("你要压多少银子作赌注？\n");

	betting = 1;
	better = me;
	// 先把玩家押的银子减掉，避免出现骰子掷一半发现输了跑出去而赢不到他钱的情况。
	mtype->add_amount(-money);
	me->start_busy(3);

	win = can_win(me,kind);

	switch(kind)
	{
		case "big" :
			message_vision("$N从身上拿出"+chinese_number(money)+"两银子压在“大”上。\n",me);
			bring_point(win?1:-1);
			break;
		case "small":
			message_vision("$N从身上拿出"+chinese_number(money)+"两银子压在“小”上。\n",me);
			bring_point(win?-1:1);
			break;
		default :
			message_vision("$N从身上拿出"+chinese_number(money)+"两银子压在“全色”上。\n",me);
			bring_point(win?0:-2);
	}

	call_out("show_point",2,0);
	return 1;
}

private void show_point(int n)
{
	string *view = ({
({
"\n一粒骰子在碗里弹了几下，停在：\n\n",
"\n一粒骰子＂叮叮＂的跳动了几下，最后停在了：\n\n",
"\n三粒骰子相互一撞，一颗直落碗底：\n\n", }),

({
"\n又一粒骰子停了下来：\n\n",
"\n第二粒骰子在碗边旋转不停．．最后翻了个身：\n\n",
"\n二粒骰子相互一撞，其中一颗跳了一跳停在：\n\n", }),

({
"\n最后一粒骰子在碗里滑了两下，终于停在：\n\n",
"\n还有最后一粒骰子嘀遛遛的转个不停．．终于停在：\n\n",
"\n最后一粒骰子也终于停稳了：\n\n", }),
});

	remove_call_out("show_point");

	if(n > 2)
	{
		do_result();
		return;
	}

	tell_room( this_object(),sprintf("%s%s",view[n][random(3)],
dianshu[points[n]-1]) );

	call_out("show_point",1,++n);
}

private void do_result()
{
	string output;
	object silver;
	int imp;

	betting = 0;

	output = sprintf("开%s、%s、%s，",chinese_number(points[0]),
		chinese_number(points[1]),chinese_number(points[2]) );

	if(points[0] == points[1] && points[1] == points[2])
		output += "爆子！！\n";

	else if( (points[0]+points[1]+points[2]) < 11 )
		output += "小。\n";
	else
		output += "大。\n";

	if(!better)
	{
		tell_room( this_object(),output);
		return;
	}

	if(!win)
	{
		output += sprintf("%s输了 %d 两银子。\n",better->name(),money);
		tell_room( this_object(),output);
		return;
	}

	output += sprintf("%s赢了 %d 两银子！！\n",better->name(),win==1?money:money*8);

	if(environment(better) != this_object())
	{
		output += "本主不在场，盈利归赌场所有。\n";
		tell_room( this_object(),output);
		return;
	}

	tell_room( this_object(),output);

	money *= win==1?2:9;
	silver = new(SILVER_OB);
	silver->set_amount(money);

	if(!silver->move(better))
	{
		destruct(silver);
		better->add("save_in_bank/silver",money);
		tell_object(better,"你拿不了更多的东西了，你赢的钱已经存到你的银行账户上了。\n");
	}

	imp = money/5;
	if(imp < 1)
		imp = 1;

	better->improve_skill("betting",imp);

}
