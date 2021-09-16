// cloth_li.c

#include <ansi.h>

inherit NPC;

#define CLOTH_FEE	400000	/* 定做衣服的价格，约为 40 gold */

mapping clothes = ([
	"t_chougua" : ([
		"name" : HIC"蓝缎大氅"NOR,
		"value": 250000,]),
	"b_chougua" : ([
		"name" : HIB"宝蓝绸袄"NOR,
		"value": 220000,]),
	"s_skirt"   : ([
		"name" : BWHT HIM"镂花长裙"NOR,
		"value": 250000,]),
	"l_skirt"   : ([
		"name" : BWHT HIG"绿玉长裙"NOR,
		"value": 300000,]),
]);

void create()
{
        set_name("李大姐", ({ "boss li","li" }) );
	set("title","巧手");
        set("gender", "女性" );
        set("age", 45);
        set("long","这是一位精干的中年妇女。\n");
        set("combat_exp", 50);
        set("attitude", "friendly");
        setup();
	carry_object(__DIR__"obj/hua_skirt")->wear();
}

void init()
{
        object ob;

	add_action("do_list","list");
	add_action("do_buy",({ "mai","buy" }));
	add_action("do_ding","ding");

        if( living(ob = previous_object()) && !is_fighting() )
	{
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}

void greeting(object ob)
{
	string day_night;
	int time;

	if( !ob
	|| (environment(ob) != environment())
	|| file_name(environment()) != this_object()->query("startroom"))
		return;

	if(!userp(ob) && ob->query("is_beggar"))
	{
		message_vision(CYN"$N冲着$n喊道：这不是你来的地方，赶紧滚！\n"NOR,this_object(),ob);
		ob->go_back_direction();
		return;
	}

	if(!is_day())
	{
		sscanf( day_night(),"%s %d",day_night,time);
		say( (time > 480) ? CYN"我们这已经打烊了，"+RANK_D->query_respect(ob)+
			"请明天再来吧。\n"NOR
			: ( (time <= 60) ? CYN"李大姐嫣然一笑道：马上就要开门了，请您等一下吧。\n"NOR
			: CYN"李大姐说道：小店还没有开门，请天亮了再来吧。\n"NOR ) );
		return;
	}
	else
	{
		switch( random(2) )
		{
                case 0:
                        say( CYN"张大嫂微笑着说道：客官要买衣服吗？请随便看看。\n"NOR);
                        break;
                case 1:
                        say( CYN"张大嫂微笑着说道：没有满意的衣服，我们这也可以量身定做。\n"NOR);
                        break;
		}
	}
}

int do_list(string arg)
{
	string *pattern;
	int i;

	if(!is_day())
	{
		command("say 客官请白天再来吧。\n");
		return 1;
	}

	pattern = keys(clothes);

	printf("目前出售的服装有：\n");
	for(i=0;i<sizeof(pattern);i++)
	{
		printf("%40-s：%s\n",
			clothes[pattern[i]]["name"]+"("+pattern[i]+")",
			chinese_value((int)clothes[pattern[i]]["value"]));
	}
	write("\n");
	return 1;
}

int do_buy(string arg)
{
	object ob,me = this_player();

	if(!is_day())
	{
		command("say 客官请白天再来吧。\n");
		return 1;
	}

	if(!arg || member_array(arg,keys(clothes)) == -1)
		return notify_fail("你要买什么？\n");

        switch (player_pay(me, clothes[arg]["value"]))
	{
		case 0:
			return notify_fail("小店也要糊口呀，没有钱怎么行。\n");
		case 2:
			return notify_fail("您的零钱不够了，银票又没人找得开。\n");
		default:
			ob = new(ARMOR_DIR"cloth");
			ob->set("name",clothes[arg]["name"]);
			ob->move(me);
			write("衣服给您，您穿上一定"+((me->query("gender") == "男性")?
				"英俊":"漂亮")+"！\n");
			me->set("self_cloth",clothes[arg]["name"]);
			me->save();
			return 1;
	}
}

int do_ding(string arg)
{
	string help = "
定做男女服装每件需"+chinese_value(CLOTH_FEE)+"。

 ding <服装的名称>
如要名称中使用颜色，可以用以下控制符：
注意：控制符字母要大写。

$BLK$ - 黑色		$NOR$ - 恢复正常颜色
$RED$ - 红色		$HIR$ - 亮红色
$GRN$ - 绿色		$HIG$ - 亮绿色
$YEL$ - 土黄色		$HIY$ - 黄色
$BLU$ - 深蓝色		$HIB$ - 蓝色
$MAG$ - 浅紫色		$HIM$ - 粉红色
$CYN$ - 蓝绿色		$HIC$ - 天青色
$WHT$ - 浅灰色		$HIW$ - 白色

";
	object ob, me = this_player();

	if(!stringp(arg) || arg == "")
		return notify_fail(help);

	// "巫师四季袍" 是巫师服装的名称。
	if(strsrch(arg,"巫师四季袍") != -1)
		return notify_fail("这种衣服是仙界圣物，小店可是做不了。\n");

        switch (player_pay(me, CLOTH_FEE))
	{
		case 0:
			return notify_fail("小店也要糊口呀，没有钱怎么行。\n");
		case 2:
			return notify_fail("您的零钱不够了，银票又没人找得开。\n");
		default:
			arg = replace_string(arg, "$BLK$", BLK);
			arg = replace_string(arg, "$RED$", RED);
			arg = replace_string(arg, "$GRN$", GRN);
			arg = replace_string(arg, "$YEL$", YEL);
			arg = replace_string(arg, "$BLU$", BLU);
			arg = replace_string(arg, "$MAG$", MAG);
			arg = replace_string(arg, "$CYN$", CYN);
			arg = replace_string(arg, "$WHT$", WHT);
			arg = replace_string(arg, "$HIR$", HIR);
			arg = replace_string(arg, "$HIG$", HIG);
			arg = replace_string(arg, "$HIY$", HIY);
			arg = replace_string(arg, "$HIB$", HIB);
			arg = replace_string(arg, "$HIM$", HIM);
			arg = replace_string(arg, "$HIC$", HIC);
			arg = replace_string(arg, "$HIW$", HIW);
			arg = replace_string(arg, "$NOR$", NOR);
			arg += NOR;

			ob = new(ARMOR_DIR"cloth");
			ob->set("name",arg);
			ob->move(me);
			me->set("self_cloth",arg);
			me->save();
			write("衣服做好了，您试试看满意不满意。\n");
			return 1;
	}
}
