// meipo.c
// by Find.

#undef DEBUG

#include <ansi.h>

inherit NPC;

int is_marry_ob() { return 1; }

private int minm = 20,minf = 18,chk_flag,wait;
private object master,working;

private string *msg = ({
"$FNAME呀，我有一个大秘密要告诉你呢，你愿意听吗？",
"最近江湖上人人都在议论一件惊天动地的大事情你还不知道吧！！",
"前一段时间江湖上出现了一位大侠士，这位大
               侠士一出道，斩杀江南五虎，挑了黑风寨。。。
               一时间声名鹊起，侠名远播大江南北呀。",
"江湖上都在纷纷猜测这位大侠士的师承来历不少
              江湖前辈都说此人小小的年级武功高强，为人行
              侠仗义，将来定是领袖天下武林的人物！不少少
              年后辈都想拜他为师呢！",
"据传说此人由于不少奇遇，不少武林隐士都传授过他武功！！",
"但此人侠踪飘忽不定，令人无法捉摸。",
"这个人就叫：$MNAME！现在江湖上一提
              起 $MNAME 的名头。。。正道人士无不
              竖大拇指，邪道无不闻风丧胆哪！",
"据我听说江湖上不少少女都在打听他呢，都对
              他倾心不已，可是他都无动于衷。",
"$FNAME呀，说到这，我可是特意赶来给你报喜来啦！！",
"前两天$FM大侠找到我：他说久闻$FNAME女
              侠的芳名，愿娶您为妻，请我来提亲呢！！",
"这不是您天大的喜事！老婆子这就给你道喜啦！
              这一下。。。不知道要打翻多少醋坛子啦！您以
              后走江湖可就要多加小心了！",
"不过成亲以后您和 $FM大侠 双宿双飞，估计也
              没人有胆量找麻烦！你以后的幸福日子可是过也
              过不完啦！ 唉！其他的姑娘也只能羡慕的夜里
              自己掉眼泪了。。。",
"我一听，这是你的大喜事呀，我这不马不停蹄的就
              赶来找您报喜来啦，这种事我知道姑娘家是不好意
              思开口的，你只要点个头，这事就包在我身上了，
              包您办的满意！",
}),

*yes_msg = ({
"行",
"好",
"好的",
"好吧",
"同意","我同意","愿意","我愿意",
}),

*shy_msg = ({
"这有什么不好意思的，只要点个头，随便一句，只要让我明白就行了。",
"要不咱们摇头不算点头算。",
"这种关键时刻可是害羞不得呀。",
"俗话说的好，易求无价宝，难得有情人。",
"$FM大侠那长相，那气质，要是退回十年我真要和你争一争呢，唉。。。",
"这种事要是一味害羞，失之交臂可是要遗恨终生呀。",
"$FM大侠可是一心一意等你你那。",
});

varargs void fail(string msg)
{
	if(objectp(master) && stringp(msg))
		command(sprintf("tell %s %s",master->query("id"),msg));

	master = 0; working = 0;
}

private void go_home()
{
	object home = find_object(query("startroom")),env;

	if(!home)
		home = load_object(query("startroom"));
	if(!home)
	{
		destruct(this_object());
		return;
	}

	env = environment();

	if(env != home)
	{
		if(env)
			message_vision("$N匆匆忙忙的走了。\n",this_object());

		move(home);
			message_vision("$N匆匆忙忙的走了进来。\n",this_object());
	}

	fail("人家姑娘说什么也不愿意，唉，看样子你还要在努力呀，这事我看以后再说吧。\n");
}

private int valid_status()
{
	object env;

	if(objectp(working))
		return 0;

	if( !(env=environment())
	|| (base_name(env) != query("startroom")) )
		return 0;

	return 1;
}

string ask_mei(object usr);

void create()
{
	set_name("媒婆", ({"mei po"}));
	set("long", "这是一位三十多岁的中年妇女，脸上微施
粉黛，虽说人老珠黄，却也风韵犹存。薄
薄的嘴唇、机灵的双眼看得出是一位能说
会道的角色。\n");

	set("gender","女性");

	set("title",HIM"秀口巧嘴"NOR);

	set("age",35);
	set("con",20);
	set("per",25);

	set(NO_KILL, 1);
	set("no_return_home",1);

	set("inquiry",([
	"说媒" : (: ask_mei :),
]));

	set("combat_exp",1500);

	setup();
	carry_object(__DIR__"obj/skirt")->wear();
}

string ask_mei(object usr)
{
	if(!objectp(usr) || !userp(usr))
		return 0;

#ifndef DEBUG
	if(wizardp(usr))
		return "巫师不允许结婚。\n";
#endif

	if(!valid_status())
		return "您先等一下吧，我这正忙着呢。\n";

	if(usr->query("gender") == "女性")
	{
		if(usr->query("age") < minf)
			return "这么小的岁数就着急嫁人啦，过几年再说吧。\n";
		return "哪有女孩求人娶自己的，我当了这许多年媒婆还没替女孩子去说过媒呢。\n";
	}

	if(usr->query("age") < minm)
		return "小小的年纪就着急娶老婆啦，过几年再说吧。\n";

        if(usr->query("is_bonze"))
                return "出家人又想结婚了？哈哈。\n";

	if(usr->query("marry/id"))
		return "怎么娶了老婆还要再找，娶妾是要朝廷批准的，要不我可是不敢干。";

	usr->set_temp("mei_po/ask",1);
	return "这可是大事，看上哪家姑娘了告诉(say)我，保你说成。\n";
}

void relay_say(object who,string arg)
{
	int n;
	object ob;

	if(!stringp(arg) || arg == "")
		return;

#ifndef DEBUG
	if(wizardp(who))
		return;
#endif

	if(chk_flag && (who == working))
	{
		if(member_array(arg,yes_msg) != -1)
		{
			chk_flag = 0;
			call_out("do_success",2);
		}
		return;
	}

	if(!valid_status() || !who->query_temp("mei_po/ask"))
		return;

	n = strlen(arg);

	if((n < 3) || (n > 10))
		return;

	for(int i=0;i<n;i++)
		if( (arg[i] < 'a') || (arg[i] > 'z') )
			return;

	if(objectp(working))
		command("say 您先等一下吧，我这正忙着呢。\n");

	if( !objectp(ob = find_player(arg)) || !environment(ob))
	{
		command("say 现在好像没有这个人，你找好了再说吧。\n");
		who->delete_temp("mei_po");
		return;
	}

	if(ob->query("gender") == "男性")
	{
		command("say 那可是个男人呀！可羞死我了，这种事你们自己去搞吧！\n");
		who->delete_temp("mei_po");
		return;
	}

#ifndef DEBUG
	if(wizardp(ob))
	{
		command("say 大神规定不允许和巫师结婚。\n");
		return;
	}
#endif

	if(ob->query("age") < minf)
	{
		command("say 你眼光真不错！这闺女我看这都喜欢，不过年龄太小了，你再耐心等几年吧。\n");
		who->delete_temp("mei_po");
		return;
	}

	if(mapp(ob->query("marry")))
	{
		command("say 人家可是有夫之妇啦，偷鸡摸狗的事情自己想办法吧。\n");
		who->delete_temp("mei_po");
		return;
	}

	if( base_name(environment(ob)) == PRISON_OB )
	{
		command("say 好家伙，这姑娘在坐牢呢！我可不敢招惹！\n");
		return;
	}

	command(sprintf("say 哎呀！%s这姑娘看着真让人喜欢！您的眼光真是不错！
	和您真是天生的一对、地造的一双，这趟媒我是做定啦！
	不过做咱们这行的就靠行善积德挣点活命钱，您好歹赏
	几个跑腿钱吧，这么好的新娘子您就出个五两黄金吧。
",ob->name()));
	who->set_temp("mei_po/want",arg);
}

int accept_object(object me, object ob)
{
	if(!me || !me->query_temp("mei_po/want"))
		return 0;

#ifndef DEBUG
	if(wizardp(me))
		return 0;
#endif

	if(!valid_status())
	{
		command("say 您先等一下吧，我这正忙着呢。\n");
		return 0;
	}

	if( !objectp(working = find_player(me->query_temp("mei_po/want"))) )
	{
		command("say 唉。你想的人已经走了，以后再说吧。");
		me->delete_temp("mei_po");
		working = 0;
		return 0;
	}

	if(!is_money(ob) || ob->value() < 50000)
	{
		command("say 为了终身幸福连五两金子都不肯出呀。。。\n");
		working = 0;
		return 0;
	}

	if(environment(ob) == environment())
		command(sprintf("say 谢您的赏！%s大官人等会儿，我这就给您说！\n",me->name()[0..1]));
	else
		command(sprintf("say 谢您的赏！%s大官人在这等会儿，我这就去给您说媒去！\n",me->name()[0..1]));

	master = me;
	me->delete_temp("mei_po");
	call_out("go_to",3);
	return 1;
}

private void go_to()
{
	if(!working)
	{
		fail("你看上的姑娘已经走了，只能以后再说了，心急吃不了热豆腐，也别太着急。");
		return;
	}

	if(environment(working) == environment())
	{
		tell_room(environment(),sprintf("\n%s把%s拉到一边说起了悄悄话。\n\n",
			name(),working->name()),({working,this_object()}));

		tell_object(working,sprintf("\n%s凑到你跟前，神秘的朝你笑了笑，象是有什么话要说。\n\n",name()));
	}

	else
	{
		tell_room(environment(),name()+"匆匆忙忙的走了出去。\n");
	
		move(environment(working));
	
		message_vision("\n$N匆匆忙忙的走了过来，凑到$n的身边。\n\n",this_object(),working);
		tell_object(working,sprintf("%s凑到你跟前，神秘的朝你笑了笑，象是有什么话要说。\n",name()));
	}

	set_leader(working);
	call_out("talking",3,0);
}

private void talking(int n)
{
	string fname,mname,sent;

	remove_call_out("talking");

	if(!objectp(working) || !objectp(master))
	{
		go_home();
		return;
	}

	fname = working->name();
	mname = master->name();
	sent = msg[n++];
	sent = replace_string(sent,"$FNAME",fname);
	sent = replace_string(sent,"$MNAME",mname);
	sent = replace_string(sent,"$FM",mname[0..1]);
	sent = replace_string(sent,"$FF",fname[0..1]);

	if(environment(working) != environment())
	{
		message_vision("$N匆匆忙忙的走了。\n",this_object());
		this_object()->move(environment(working));
		message_vision("$N急急忙忙的走了过来。\n",this_object());
	}

	command(sprintf("tell %s %s\n",working->query("id"),sent));

	if(n >= sizeof(msg))
	{
		chk_flag = 1;
		call_out("check_result",6,0,0);
		return;
	}

	call_out("talking",6,n);
}

private void check_result(int n,int times)
{
	string fname,mname,sent;

	if(!chk_flag)
		return;

	if(!objectp(working) || !objectp(master))
	{
		chk_flag = 0;
		go_home();
		return;
	}

	fname = working->name();
	mname = master->name();
	sent = shy_msg[n++];
	sent = replace_string(sent,"$FM",mname[0..1]);

	if(environment(working) != environment())
	{
		message_vision("$N匆匆忙忙的走了。\n",this_object());
		this_object()->move(environment(working));
		message_vision("$N急急忙忙的走了过来。\n",this_object());
	}

	command(sprintf("tell %s %s\n",working->query("id"),sent));

	if(n >= sizeof(shy_msg))
	{
		if(!times)
		{
			times++; n = 0;

		}
		else
		{
			chk_flag = 0;
			command("sigh");
			go_home();
			return;
		}
	}

	call_out("check_result",6,n,times);
}

void find_emote(object who,string verb)
{
	if(!who || !chk_flag)
		return;

	if( (who == working) && (verb == "nod") )
	{
		chk_flag = 0;
		call_out("do_success",2);
	}
}

private void do_success()
{
	object jf,jz;

	if(!objectp(working))
	{
		command("sigh");
		go_home();
		return;
	}

	if(!objectp(master))
	{
		command(sprintf("tell %s 你瞧瞧，人家等不及已经走了，你这真是要遗恨终身呢。\n",working->query("id")));
		command("sigh");
		go_home();
		return;
	}

	if(environment() == find_object(query("startroom")))
	{
		environment()->no_out(working);
		environment()->no_out(master);
		command(sprintf("tell %s 你可真是好福气，新娘子同意了！\n",master->query("id")));
		message_vision("$N笑呵呵的说道：恭喜二位！我已经派人去请礼部堂官啦，他马上就来主持婚礼！\n",this_object());
		call_out("come_zhuchi",4);
		return;
	}

	command(sprintf("tell %s 你可真是好福气，新娘子同意了，我这就把她接回来！你耐心等会儿。\n",master->query("id")));

	if(environment(working) != environment())
	{
		message_vision("$N匆匆忙忙的走了。\n",this_object());
		this_object()->move(environment(working));
		message_vision("$N急急忙忙的走了过来。\n",this_object());
	}

	message_vision("$N朝后面一招手，两个轿夫抬着一乘小轿走了过来。\n",this_object());

	jf = new(__DIR__"jiaofu");
	jf->move(environment());
	jf = new(__DIR__"jiaofu");
	jf->move(environment());
	jz = new(__DIR__"obj/huajiao");
	jz->move(environment());

	message_vision(sprintf("$N将$n扶上%s。\n",jz->name()),this_object(),working);
	working->move(jz);
	jz->begin_walking();
	message_vision("$N带着轿夫匆匆忙忙的走了。\n");

	set_leader(0);
	filter_array(all_inventory(environment()),(: $1->is_marry_ob() :) )->move(VOID_OB);
	call_out("arrive",18,jz);
}

private void arrive(object jz)
{
	object home = find_object(query("startroom")),*obs;

	if(!home)
		home = load_object(query("startroom"));
	if(!home)
	{
		if(working)
		{
			tell_object(working,"\n一阵大风不知道把你吹到了什么地方。\n");
			working->move("/d/changan/jiulou");
		}

		obs = filter_array(all_inventory(environment())-({this_object()}), (: $1->is_marry_ob() :) );
		for(int i=0;i<sizeof(obs);i++)
			destruct(obs[i]);
		destruct(this_object());
		return;
	}

	filter_array(all_inventory(environment()),(: $1->is_marry_ob() :) )->move(home);

	message_vision("$N带着两个轿夫抬着一乘小花轿走了进来。\n",this_object());

	tell_object(working,"媒婆一撩轿帘把你扶了下去。\n");
	working->move(home);
	tell_room(home,sprintf("媒婆一撩轿帘把扶%s了下来。\n",working->name()),({this_object(),working}));

	tell_room(home,"轿夫将小花轿抬了出去。\n");
	obs = filter_array(all_inventory(environment())-({this_object()}), (: $1->is_marry_ob() :) );
	for(int i=0;i<sizeof(obs);i++)
		destruct(obs[i]);

	if(!master)
	{
		message_vision("$N四处看看对$n说道：人怎么没了！还自称大侠哪！这种人天下男人死光
	了也不能嫁他！你别难受，早发现了是好事情，姑娘去忙别的吧，以后
	要是见到他我一定帮你羞辱死他！\n",this_object(),working);
		fail();
		return;
	}

	else if(environment(master) != home)
	{
		command(sprintf("tell %s 新娘子已经到啦！您赶紧来呀！\n",master->query("id")));
		command(sprintf("tell %s 新郎出去办点事情马上就来，请你等一会儿吧。\n",working->query("id")));
		wait = 1;
		home->no_out(working);
		call_out("waiting",5,0);
		return;
	}

	home->no_out(working);
	home->no_out(master);
	message_vision("$N笑呵呵的说道：恭喜二位！我已经派人去请礼部堂官啦，他马上就来主持婚礼！\n",this_object());

	call_out("come_zhuchi",4);
}

void init()
{
	if( wait && objectp(master) && (this_player() == master))
	{
		wait = 0;
		environment()->no_out(master);
		call_out("come_on",1);
	}
}

private void come_on()
{
	if( master && (environment(master) == environment()) )
	{
		message_vision("$N笑嘻嘻的迎上$n说道：“你可来啦，新娘子都快等急啦，嘻嘻。”",
			this_object(),master);
		remove_call_out("waiting");
		message_vision("$N笑呵呵的说道：恭喜二位！我已经派人去请礼部堂官啦，他马上就来主持婚礼！\n",this_object());
		call_out("come_zhuchi",4);
	}
}

private void waiting(int times)
{
	if(times > 10)
	{
		if(objectp(master))
			command(sprintf("tell %s 算了，你也别来了！新娘子已经等不及走了！\n",master->query("id")));
		if(objectp(working))
		{
			environment()->can_out(working);
			message_vision("$N四处看看对$n说道：还不来，太差劲啦！还自称大侠哪！这种人天下男人死光
	了也不能嫁他！你别难受，早发现了是好事情，姑娘去忙别的吧，以后
	要是见到他我一定帮你羞辱死他！\n",this_object(),working);
		}
		wait = 0;
		fail();
		return;
	}

	if(!master)
	{
		if(objectp(working))
		{
			environment()->can_out(working);
			message_vision("$N四处看看对$n说道：还不来，太差劲啦！还自称大侠哪！这种人天下男人死光
	了也不能嫁他！你别难受，早发现了是好事情，姑娘去忙别的吧，以后
	要是见到他我一定帮你羞辱死他！\n",this_object(),working);
		}
		wait = 0;
		fail();
		return;
	}

	if(!working)
	{
		if(objectp(master))
			command(sprintf("tell %s 算了，你也别来了！新娘子已经等不及走了！\n",master->query("id")));
		wait = 0;
		fail();
		return;
	}

	command(sprintf("tell %s 你到是快点呀！新娘子都要等不及了！\n",master->query("id")));
	message_vision("$N笑嘻嘻的对$n说道：再等会儿，就快来啦。\n",this_object(),working);
	call_out("waiting",6,++times);
}

private void come_zhuchi()
{
	object tang;

	if(!objectp(master) || !(working))
	{
		message_vision("$N哼了一声说道：还没办事呢人先走了！真差劲！算啦！当老娘百忙活一场。\n",this_object());
		if(master)
			environment()->can_out(master);
		if(working)
			environment()->can_out(working);
		fail();
		return;
	}

	tang = new(__DIR__"litang");
	tang->move(environment());
	message_vision("\n$N迈着方步踱了进来。\n",tang);
	message_vision("\n$N一扭身子迎上去说道：哎呀，和大人来啦，这对新人就等着您来主持婚礼啦。\n",this_object());
	tang->begin_hunli(master,working);
}

// 打开双喜阁
void finish_yishi()
{
	call_out("end",3);
}

private void end()
{
/*
	environment()->set("exits/eastup",__DIR__"sxg");
	message_vision("\n$N把右面的红木门打开。\n");
*/
	command("open door");
	message_vision("\n$N说道：右面上楼就是“双喜阁”啦，新人如果想要举行婚宴，上去看牌子(pai)就清楚啦！
	祝两位新人永结同心，白头到老。。。\n",
		this_object());
	fail();
}
