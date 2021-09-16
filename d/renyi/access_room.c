// Room: /d/enyi/access_room.c
// by Find.

/*
 * 功能：
 *   1。察看所有被悬赏人、或指定悬赏人赏金的情况
 *   2。领取任务
 *   3。退还任务
 *   4。悬赏
 */

#include <renyi.h>

#undef IN_TEST
#define LIMIT_KILLER

inherit ROOM;

inherit __DIR__"die";

protected mixed *ran_name = ({
	({ "行人", "xingren" }),
	({ "路人", "luren" }),
	({ "商人", "shangren" }),
	({ "商客", "shangke" }),
	({ "青年", "qingnian" }),
	({ "中年人", "zhongnian" }),
});

protected void create()
{
	set("short", "仁义庄账房");
	set("long", @LONG
这是一间宽大空旷的房间，迎面八仙桌后面一位在一边翻着
帐本，一边打着算盘。右面站着一位精神矍铄的老人，满面红光，
不怒自威。门边贴着一张告示(paper)，已经发黄了。
LONG
	);

	set(SAFE_ENV, 1);

	set("exits", ([
	"west" : __DIR__"renyi1",
]));

	set("objects", ([
	__DIR__"npc/zz" : 1,
]));

	set("item_desc", ([
	"paper" : "
            《仁义庄告示》

    当今天下纷争，武林杀戮，一等肖小之辈
趁机欺压良善，无恶不作。奸邪横行之日，非
我侠义之士悠游江湖之时，老儿不惜绵薄之力，
散尽家财，创建“仁义庄”，但望惩恶扬善，
还我武林之正义。

   check [id] : 察看悬赏榜或某人的悬
                赏情况

   accept ID  ：接受除掉一个被悬赏人
                的任务

   tui        ：退还已领取的任务

   award ID   ：出资对某人进行悬赏

   wancheng   : 完成任务领取奖金


                    ----- 仁义庄主 启
",
	"告示" : "
            《仁义庄告示》

    当今天下纷争，武林杀戮，一等肖小之辈
趁机欺压良善，无恶不作。奸邪横行之日，非
我侠义之士悠游江湖之时，老儿不惜绵薄之力，
散尽家财，创建“仁义庄”，但望惩恶扬善，
还我武林之正义。

   check [id] : 察看悬赏榜或某人的悬
                赏情况

   accept ID  ：接受除掉一个被悬赏人
                的任务

   tui        ：退还已领取的任务

   award ID   ：出资对某人进行悬赏

   wancheng   : 完成任务领取奖金


                    ----- 仁义庄主 启
",
]));
	setup();
}

protected string list_on_item(mixed *one, int wiz)
{
	string out = "";

	if(one && sizeof(one))
		out = sprintf("%-24s %s\t悬赏%d两黄金%s\n",
			sprintf("%s(%s)",one[1],one[0]),
			sizeof(one[2])?sprintf("曾在%s学艺",one[2]):"没能查出此人门派",
			one[3],
			sizeof(one[4])?(wiz?"\t"+one[4]:"\t★"):"");

	return out;
}

protected int sort_killer_award(mixed a, mixed b)
{
	if(a[3] > b[3])
		return -1;
	return 1;
}

void init()
{
	add_action("do_check", "check");	// 察看赏金情况
	add_action("do_accept", "accept");	// 领任务来了
	add_action("do_return", "tui");		// 退还任务
	add_action("do_award", "award");	// 进行悬赏
	add_action("do_wancheng", "wancheng");	// 完成任务
}

// 察看赏金情况
int do_check(string arg)
{
	object me = this_player();
	string out = "";
	int flag = wizardp(me);

	if(!arg || !sizeof(arg))
	{
		mixed *all;

		if( !sizeof(all = RENYI_D->query_killer_detail()) )
			return notify_fail("目前本庄的悬赏榜上还没有任何人。\n");

		else
		{
			all = sort_array(all, "sort_killer_award", this_object());

			out = "                     《仁义庄悬赏榜》\n\n";
			foreach(mixed *tmp in all)
				out += list_on_item(tmp, flag);

			out += "\n";
			this_player()->start_more(out);
			return 1;
		}
	}

	else
	{
		mixed *one;

		if( !sizeof(one = RENYI_D->query_killer_detail(arg)) )
			return notify_fail("目前本庄的悬赏榜上还没有此人。\n");

		out = sprintf("                     《仁义庄悬赏榜》\n\n%s", list_on_item(one[0], flag));

		write(out+"\n");

		return 1;
	}
}

// 领任务来了
int do_accept(string arg)
{
	mapping ey;
	object me = this_player();
	string *apply;
	mixed *killer;

	if(me->query("combat_exp") <= MIN_XIAKE_EXP)
		return notify_fail("武功不高就如此疾恶如仇，真是侠义本色，不过为了安全还是以后再说吧。\n");

	if( (mapp(ey = me->query("enyi_class")) && sizeof(ey))
	|| RENYI_D->query_have_killer_quest(geteuid(me)) )
		return notify_fail("你现有的任务还没有完成呢，快去吧。\n");

	if(!sizeof(arg))
		return notify_fail("你要接受除掉哪个人的任务？\n");

#ifdef IN_TEST
	if(!wizardp(me))
		return notify_fail("测试期间，不允许玩家接任务。\n");
#else
	if(wizardp(me))
		return notify_fail("正式运行期间，不允许巫师接任务。\n");
#endif

	switch(RENYI_D->accept_xiake_quest(arg, me))
	{
		case 1:
			if( !sizeof(killer = RENYI_D->query_killer_detail(arg)[0]) )
				return notify_fail("被悬赏人资料出问题，请发信给管理员处理！！\n");
			ey = allocate_mapping(7);
			apply = ran_name[random(sizeof(ran_name))];
			ey["id"] = killer[0];
			ey["name"] = killer[1];
			ey["class"] = killer[2];
			ey["award"] = killer[3];
			ey["a_name"] = apply[0];
			ey["a_id"] = apply[1];
			ey["time"] = time();
			me->set("enyi_class", ey);
			me->set_mask_name(ey["a_name"]);
			me->set_mask_id(ey["a_id"]);
			// 任务时间为 60 天，也就是现实生活一天，86400秒
			tell_object(me, sprintf("
庄主对你说道：此贼奸滑无比，要小心从事！万万不可掉以轻心！
    今天是%s创世%s年%s月%s日，老夫给你『60天』的
    时间，如果不能完成，老夫就委托别人了；一旦能手刃此贼，
    务必『要在这个期限内回来告诉老夫(wancheng)』！！
    在这期间要专心完成这个任务！其它的事情要受到一些限制。\n
", MUD_NAME, chinese_number(query_year()), chinese_number(query_month()), chinese_number(query_day_in_month())) );

			tell_object(me, sprintf("庄主走过来描画了一番，将你扮成了一位%s。\n\n", ey["a_name"]));
			me->save();
			return 1;
		case SAME_XID_KID:
			return notify_fail("悔恨的都想自己杀了自己？自杀来的比较容易。\n");
		case NO_THIS_KILLER:
			return notify_fail("悬赏榜上没有这个人。\n");
		case HAVE_KQUEST:
			return notify_fail("赶紧去完成你现在的任务吧。\n");
		case QUEST_BEEN_USE:
			return notify_fail("追杀此人的任务正在有人作，你后再说吧。\n");
		case GET_MAX_XIAKE_NUM:
			return notify_fail("现在已经有不少人正在追杀被悬赏人了，你过一段时间再说吧。\n");
		default:	// 包括 0
			return notify_fail("目前无法接这个任务。\n");
	}
}

// 退还任务
int do_return()
{
	object me = this_player();
	mapping ey;
	string kid;

	if(!mapp(ey = me->query("enyi_class")) || !sizeof(ey))
		return notify_fail("你目前没有承担仁义庄的任务。\n");

	if( stringp(kid = ey["finish"]) && (ey["id"] == kid) ) // 已完成
	{
		int gold;

		gold = RENYI_D->finish_renyi_quest(geteuid(me), ey["id"]);
		log_file("renyi", sprintf("%s(%s) 成功的追杀了 %s%s\n", me->name(1), geteuid(me),ey["name"], ey["id"]));
		write(sprintf("庄主高兴地说道：好呀，立了这么大功都不要奖赏，\n这 %d 两黄金我们仁义庄收下了。\n",
			gold ));
		
	}
	else
	{
		if(!RENYI_D->return_xiake_quest(geteuid(me)))
			return notify_fail("现在没法退任务，等忙过这几天再说。\n");

		tell_object(me, "庄主说道：这斯的确不容易对付，只有等以后再说吧，唉。。。\n");
	}

	me->delete("enyi_class");
	me->remove_mask_name();
	me->remove_mask_id();
	me->set_mask_name("陌生人");
	me->set_mask_id("xiake");

	return 1;
}

protected void accept_award_gold(string str, object me, string killer)
{
	int n;

	if(!me || (environment(me) != this_object()) || !sizeof(killer))
		return;

	if(!sizeof(str))
	{
		tell_object(me, "你要对此人悬赏多少两黄金？(q 退出)\n");
		input_to((: accept_award_gold:), me, killer);
		return;
	}

	if((str[0] == 'q') || (str[0] == 'Q'))
	{
		tell_object(me, "ok.\n");
		return;
	}

	if(!sscanf(str, "%d", n) || (n < 5))
	{
		tell_object(me, "每次悬赏最少要五两黄金\n你要对此人悬赏多少两黄金？(q 退出)\n");
		input_to((: accept_award_gold:), me, killer);
		return;
	}

	if(n > 20000)
	{
		tell_object(me, "每次悬赏最多两万两黄金\n你要对此人悬赏多少两黄金？(q 退出)\n");
		input_to((: accept_award_gold:), me, killer);
		return;
	}

	if(!pay_from_bank(me, n*10000,1))
	{
		tell_object(me, "你银行里没有这么多存款\n你要对此人悬赏多少两黄金？(q 退出)\n");
		input_to((: accept_award_gold:), me, killer);
		return;
	}

	switch(RENYI_D->accept_award_gold(killer, n))
	{
		case 1:
			if(!pay_from_bank(me, n*10000))
			{
				tell_object(me, "你银行里没有这么多存款");
				log_file("enyi", sprintf("被悬赏人 %s 的赏金数量多加了 %d 两黄金。\n", killer, n));
				return;
			}
			tell_object(me, "赏金已被接受。\n");
			return;
		case AWARD_GET_MAX:
			tell_object(me, "此人的赏金已达到最高限，不能再增加了。\n");
			return;
		case GET_MAX_KILLER_NUM:
			tell_object(me, "目前被悬赏人已经够多了，不能再增加了。\n");
			return;
		default:
			tell_object(me, "目前无法进行悬赏。\n");
			return;
	}
}

// 进行悬赏
int do_award(string arg)
{
	object me = this_player();

	if(!stringp(arg) || !sizeof(arg))
		return notify_fail("你要对谁悬赏？\n");

#ifdef LIMIT_KILLER
	if(me->query("my_killer") != arg)
		return notify_fail("你只能对你的仇人悬赏。\n");
#endif

	if(geteuid(me) == arg)
		return notify_fail("你要悬赏你自己？\n");

#ifndef IN_TEST
	if(wizardp(me))
		return notify_fail("正是运行期间，不允许巫师参与。\n");
	if(wiz_level(arg) > 0)
		return notify_fail("你找错人了！！\n");
#endif

	switch(RENYI_D->check_valid_killer(arg))
	{
		case 1:
			write("你要对此人悬赏多少两黄金？(q 退出)\n");
			break;
		case NO_THIS_USER:
			return notify_fail("没有这么一个人存在。\n");
		case IN_PROTECTED:
			return notify_fail("对方还处于被保护年龄，不能悬赏。\n");
		default:
			return notify_fail("你要对谁悬赏？\n");
	}

	input_to((: accept_award_gold:), me, arg);
	return 1;
}

// 完成任务
int do_wancheng()
{
	object me = this_player();
	mapping ey;
	int gold, n, bank;
	string out;

	if(!mapp(ey = me->query("enyi_class")) || !sizeof(ey))
		return notify_fail("你并没有领取本庄的任务。\n");

	if(!ey["finish"] || (ey["finish"] != ey["id"]))
		return notify_fail(sprintf("你并没有杀死本庄要你去杀的%s(%s)。\n", ey["name"], ey["id"]));

	gold = RENYI_D->finish_renyi_quest(geteuid(me), ey["id"]);

	me->remove_mask_name();
	me->remove_mask_id();
	me->set_mask_name("陌生人");
	me->set_mask_id("xiake");

	if(gold <= 0)
		switch(gold)
		{
			case NO_THIS_KILLER:
				me->delete("enyi_class");
				me->save();
				return notify_fail("本庄的悬赏榜上并没有此人，是谁交给你的任务？\n");
			case QUEST_BEEN_USE:
				me->delete("enyi_class");
				me->save();
				return notify_fail("本庄的并没有把这个任务交待给你。\n");
			default:
				return notify_fail("出现了异常错误致使你无法领取奖金，请向管理员申请解决。\n");
		}

	if(gold > 200000000)
		n = gold/10*8;
	else
		n = gold*8/10;

	bank = me->query("save_in_bank/gold");

	out = sprintf("
庄主笑着点点头说道：像%s这等奸狞凶残之徒都被你解决，
    老朽真是佩服，仗剑江湖，行侠仗义，前途不可限量！
    此人的赏金一共 %d 两黄金，鄙庄留下一点手续
    费维持的生机，其余的一共 %d 两黄金。", ey["name"], gold, n);

	if(2100000000 - bank < n)
	{
		out += "你银行已
    经存不下了，请通知管理员帮你处理。\n\n";
		log_file("enyi", sprintf("%s(%s) 银行账户已满，共有 %d 两黄金无法领取。\n",
			me->name(1), geteuid(me), n));
	}

	else
	{
		out += "都转到你
    的帐上了。\n\n";
		me->add("save_in_bank/gold", n);
	}

	log_file("renyi", sprintf("%s(%s) 成功的追杀了 %s%s\n", me->name(1), geteuid(me),ey["name"], ey["id"]));

	tell_object(me, out);

	me->delete("enyi_class");
	me->save();

	return 1;
}
