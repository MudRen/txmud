// liehu_zhao.c
// 每人只能收一件活.
// by Find.

#include <ansi.h>
#define MAX		10
#define GET_RATE	20

inherit NPC;
inherit F_SAVE;

string ask_me(object who);
string query_save_file() { return __DIR__"liehu_zhao"; }

class items{
	int year;
	int month;
	int day;
	string request_liewu;
	string playerid;
	int payed;
}

class items *wild_requests = ({});

static mapping liewu = ([ "野山鸡":__DIR__"obj/shanji",
"獐子":__DIR__"obj/zhangzi",
"麋鹿":__DIR__"obj/milu",
"山虎":__DIR__"obj/shanhu", ]);

private string pay_request(object who,string name,int yufu);
string check_request(string id);

void create()
{
	set_name("老赵", ({ "old zhao", "zhao" }) );
	set("title","猎户");
	set("gender", "男性" );
	set("age", 47);
	set("long", "老赵是这一带闻名的神猎手，不但每次打猎回
来收获丰厚，而且有时还能打到一些珍奇的野
兽，但是怎么打到的却是死活不说，别看是一
个猎户，也是很有头脑的，如果你想搞一些珍
奇野兽找他也许有办法，不过价钱可不会便宜
呀。你可以问问他关于“打猎”的事情。 \n");

	restore();
	set("inquiry",([
	"打猎" : (: ask_me :),
]));
	set("chat_chance",10);
	set("chat_msg",({
	CYN"老赵说道：“以前我爹常和我说：猎户的饭碗就在打猎的地方和方法上，就是死也不能和别人说。”\n"NOR,
	CYN"老赵说道：“这附近的山上有不少珍奇野兽，就是很难打到。”\n"NOR,
}));

	set("combat_exp", 20000);
	set("per", 30);
	set_skill("dodge", 200);
	set_skill("parry", 200);
	set_skill("unarmed", 200);

	setup();
	carry_object(__DIR__"obj/hupi")->wear();
}

void init()
{
	add_action("huan_qian","huan");
}

int huan_qian()
{
	int value;
	object who = this_player();

	value = who->query("liehu_zhao");

	if(!value)
		return notify_fail("老赵说道：您没有欠小的钱呀。\n");

	if(!player_pay(who,value))
		return notify_fail(sprintf("老赵说道：您差小的%s，看样子您身上带的钱不够。\n",
			chinese_value(value)));

	else
	{
		write("老赵说道：钱我收了，以后您有什么需要尽管来找小的。\n");
		who->delete("liehu_zhao");
		return 1;
	}
}

string ask_me(object who)
{
	int i,n,last_month;
	class items item;
	string id;
	int year,month,day;

	if(who->query("liehu_zhao"))
		return sprintf("你还欠着我%s没还呢！\n",chinese_value(who->query("liehu_zhao")));

	n = sizeof(wild_requests);
	id = who->query("id");

	if(n)
	{
		for(i=0;i<n;i++)
		{
			if(!wild_requests[i])
				continue;

			if(wild_requests[i]->playerid == id)
			{
				item = wild_requests[i];
				break;
			}
		}
	}

	if(!item)
		return "这附近的山里有不少珍奇野兽。我打到过野山鸡(shan ji)、
          獐子(zhang zi)、麋鹿(mi lu)、山虎(shan hu)，不知您对
          哪种感兴趣？可以说(say)给我听。普通的猎物打回来我都卖
          给肉铺了，您要需要的话可以去那看看。\n";

	else
	{
		year = query_year();
		month = query_month();
		day = query_day_in_month();

		if(year > item->year)
			last_month = month + 12 - item->month;
		else
			last_month = month - (int)item->month;

		if(last_month < 0)
		{
			if( (day - item->day) < 7)
				return sprintf("“您不是刚托小的打%s，等%s月%s日以后您再来问吧。”\n",
					item->request_liewu,chinese_number(item->month),chinese_number(item->day));
			else
				return sprintf("“您托小的打%s的事还没到一个月呢，等%s月%s日以后您再来问吧。”\n",
					item->request_liewu,chinese_number(item->month),chinese_number(item->day));
		}

		else if(last_month == 0)
		{
			if(item->day > day)
				return sprintf("“您托小的打%s的事还没到一个月呢，等%s月%s日以后您再来问吧。”\n",
					item->request_liewu,chinese_number(item->month),chinese_number(item->day));

			else
			{
				wild_requests[i] = 0;
				wild_requests -= ({0});
				save();
				return pay_request(who,item->request_liewu,item->payed);
			}
		}

		else if(last_month == 1)
		{
			wild_requests[i] = 0;
			wild_requests -= ({0});
			save();

			if(item->day < day)
				return "“您要的"+item->request_liewu+"我给您打到了！可您总不来，都快放坏了，没办法小的就给吃了。”\n";

			else
				return pay_request(who,item->request_liewu,item->payed);
		}

		else
		{
			wild_requests[i] = 0;
			wild_requests -= ({0});
			save();
			return "“您要的"+item->request_liewu+"我给您打到了！可您总不来，都快放坏了，没办法小的就给吃了。”\n";
		}
	}
}

void relay_say(object ob, string arg)
{
	string req,what;

	if(!stringp(arg) || arg == "")
		return;

	if(strsrch(arg,"野山鸡") != -1 || strsrch(arg,"shan ji") != -1)
		req = "野山鸡";
	else if(strsrch(arg,"獐子") != -1 || strsrch(arg,"zhang zi") != -1)
		req = "獐子";
	else if(strsrch(arg,"麋鹿") != -1 || strsrch(arg,"mi lu") != -1)
		req = "麋鹿";
	else if(strsrch(arg,"山虎") != -1 || strsrch(arg,"shan hu") != -1)
		req = "山虎";

	if(!req)
		return;

	if(ob->query("liehu_zhao"))
	{
		write(sprintf("你还欠着我%s没还呢！\n",chinese_value(ob->query("liehu_zhao"))));
		return;
	}

	if(sizeof(wild_requests) >= MAX)
	{
		write(CYN"老赵说道：实在抱歉，小的最近接的活太多了，您过一段时间再来看看吧。\n"NOR);
		return;
	}

	what = check_request(ob->query("id"));
	if(what)
	{
		write(CYN"老赵说道：您不是已经托付小的去打"+what+"了吗？您过段时间再来问问吧。\n"NOR);
		return;
	}

	ob->set_temp("liehu_zhao/request",req);
	write(CYN"老赵说道：“"+req+"这东西很不好打，您得给我一个月的时间。不过您要先付十两银子的订金，
          如果打到了就从价格里刨去这十两，如果没打到就算您赏给小的的跑腿钱了。”\n"NOR);

	return;
}

int accept_object(object me,object obj)
{
	string req;
	int year,month,day,flag;
	class items item;

	if(!is_money(obj))
		return 0;

	if(!req = me->query_temp("liehu_zhao/request"))
		return notify_fail(CYN"老赵说道：“无功不受禄，小的怎敢平白无故接受您的钱。”\n"NOR);

	if(obj->value() < 1000)
		return notify_fail(CYN"老赵说道：“打"+req+"至少也要是两银子的订金。”\n"NOR);

	year = query_year();
	month = query_month();
	day = query_day_in_month();

	month++;

	if(month > 12)
	{
		month -= 12;
		year++;
		flag = 1;
	}

	item = new(class items);
	item->year = year;
	item->month = month;
	item->day = day;
	item->request_liewu = req;
	item->playerid = me->query("id");
	item->payed = (int)obj->value();

	wild_requests += ({ item });
	save();

	write(sprintf(CYN+"老赵看了看皇历说道：“好吧，我紧这一个月的时间给您打，您在%s月%s日以后来问我结果，
                      如果打到了，小的沾您的光也能赚一比，如果实在打不到您也别怪我。
                      对了！您来千万别超过2个月，畜生死了放不长，您要没来我只好处
                      理给别人了。”\n"+NOR,(flag)?"明年"+chinese_number(month):chinese_number(month),chinese_number(day)));

	me->delete_temp("liehu_zhao/request");
	return 1;
}

void refresh_requests()
{
	int i,n,year,month,day,last_month;

	if(!n = sizeof(wild_requests))
		return;

	year = query_year();
	month = query_month();
	day = query_day_in_month();

	for(i=0;i<n;i++)
	{
		if(year > wild_requests[i]->year)
			last_month = month + 12 - wild_requests[i]->month;
		else
			last_month = month - wild_requests[i]->month;

		if(last_month == 2)
		{
			if(day >= wild_requests[i]->day)
				wild_requests[i] = 0;
		}

		else if(last_month > 2)
			wild_requests[i] = 0;
	}

	wild_requests -= ({0});
	save();
}

private string pay_request(object who,string name,int yufu)
{
	int value,flag;
	object ob;
	string msg;

	if(random(100) > GET_RATE)
		return "“实在抱歉，小的最近天天都在找，可连的影子也没看见过，
          您再看看还需要什么别的吧，小的一定给您尽力。”";

	else
	{
		write(CYN"老赵说道：“您要的"+name+"给您打到了！可真费了小的不少力气。”\n");
		ob = new(liewu[name]);
		value = ob->query("value")/10*4;

		if(!ob->move(who))
		{
			flag = 1;
			ob->move(environment());
		}

		write(sprintf("老赵从后面拖出一只%s%s。\n",ob->name(),flag?"":"交给你"));
		if(value <= yufu)
			return "您付给我的预付款已经很多了，这"+ob->name()+"就算小的孝敬您的了。\n";

		msg = sprintf("这%s算您%s，刨去您的预付款%s，您只要再付给我%s就行了。\n",
			ob->name(),chinese_value(value),chinese_value(yufu),chinese_value(value-yufu));
		value -= yufu;
		if(!player_pay(who,value-yufu))
		{
			
			who->set("liehu_zhao",(int)value);
			msg += "看您身上的钱带的不够，下回您路过这里再还(huan)我就是了。\n";
		}
		else
			msg += "钱我收了，下回您有什么需要再来找我。";

		return msg;
	}
}

string check_request(string id)
{
	int i,n;

	n = sizeof(wild_requests);
	if(!n) return 0;
	for(i=0;i<n;i++)
	{
		if(wild_requests[i]->playerid == id)
			return wild_requests[i]->request_liewu;
	}

	return 0;
}