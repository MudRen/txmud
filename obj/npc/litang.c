// litang.c

#include <ansi.h>

inherit NPC;

object master,working;
int time,money,bai;

int open_heart_beat() { return 1; }

private int do_check(string msg)
{
	object mp;

	if(!objectp(master)
	|| !objectp(working)
	|| (environment(master) != environment())
	|| (environment(working) != environment()) )
	{
		if(stringp(msg))
			message_vision(msg,this_object());
		if(master)
			environment()->can_out(master);
		if(working)
			environment()->can_out(working);
		mp = present("mei po",environment());
		if(objectp(mp))
			mp->fail();
		call_out("leave",2);
		return 0;
	}
	return 1;
}

void create()
{
	set_name("和事老", ({ "he shi lao" }));
	set("title","礼部堂官");
	set("long", "这是一位身广体胖的中年男子，看气度大概
是一位不小的朝廷命官。\n");
	set("gender","男性");

	set("age",45);
	set("con",20);
	set("str",20);
	set(NO_KILL, 1);

	set("combat_exp",1500);

	setup();
	carry_object(ARMOR_DIR"cloth")->wear();
}

void begin_hunli(object m,object w)
{
	master = m; working = w;

	if(!do_check("$N皱皱眉头说道：人都没到齐呢请我来作什么！胡闹！\n"))
		return;

	master->delete_temp("marry_bai");
	working->delete_temp("marry_bai");
	message_vision("\n$N“咳嗯”的嗽了一下嗓子，点了一下头。\n",this_object());
	call_out("do_say",2);
}

private void do_say()
{
	message_vision("\n$N慢悠悠的说道：本部堂。。。承。。。万岁信任，执掌礼部。。。，
	百姓婚配事宜也由本部堂。。。掌管。。。，礼部规定。。。，
	每对新人须向礼部缴纳。。。十两黄金。。。手续费。。。，
	现在。。。先交钱吧！\n",this_object());

	money = 1; time = time();
}

private void leave()
{
	if(environment())
		message_vision("$N踱着方步走了出去。\n",this_object());
	destruct(this_object());
}

int accept_object(object me, object ob)
{
	if( !money
	|| ((me != master)
	&& (me!= working)) )
		return 0;

	if(!is_money(ob))
	{
		message_vision("$N对$n着说道：交手续费，你怎么回事！\n",this_object(),me);
		return 0;
	}

	if(ob->value() < 100000)
	{
		message_vision("$N对$n着说道：手续费十两黄金！这是朝廷规定的！\n",this_object(),me);
		return 0;
	}

	money = 0;
	call_out("do_begin",2);
	return 1;
}

int heal_up()
{
	int t = time();

	if(bai)
	{
		if((find_call_out("on_bai") != -1) || (find_call_out("finish_bai") != -1))
			return 0;
		if(!do_check("$N说道：仪式都不举行完人就跑了！这还结什么婚！不像话！\n"))
			return 0;
		if(t - time < 20)
			return 1;
		if(master->query_temp("marry_bai") != bai)
			tell_object(master,"和事老对你说道：快点拜(koubai)呀！这种事情还不抓紧。\n");
		if(working->query_temp("marry_bai") != bai)
			tell_object(working,"和事老对你说道：快点拜(koubai)呀！这种事情还不抓紧。\n");
		if(t - time > 40)
		{
			object mp;

			message_vision("\n$N目着脸说道：这种事情磨磨蹭蹭的，我看是不想结婚了！算了，打道回府！\n\n",this_object());
			call_out("leave",2);
			environment()->can_out(master); environment()->can_out(working);
			mp = present("mei po",environment());
			if(objectp(mp))
				mp->fail();
			return 0;
		}
		return ::heal_up();
	}

	if(!money)
		return ::heal_up();

	if(!do_check("$N慢悠悠说道：怎么！为了几两手续费人就跑了？胡闹！\n"))
		return 0;

	if( t - time > 40 )
	{
		message_vision("\n$N慢悠悠说道：怎么！手续费都不舍得不交！这种十两都
	不值的婚我看不结也罢！\n",this_object());
		call_out("leave",2);
		return 0;
	}

	message_vision("\n$N慢悠悠说道：怎么回事。。！赶紧交来手续费。。本部堂好为你们主持婚礼.\n",this_object());
	return ::heal_up();
}

private void do_begin()
{
	if(!do_check("$N说道：怎么交了钱就跑！这还结什么婚！\n"))
		return;

	message_vision("\n$N立刻换上一副笑脸说道：好好。。两位郎才女貌，真是天作之和。
	今天是黄道吉日，宜婚配！这就举行仪式吧！\n\n",this_object());

	call_out("on_bai",2);
}

private void on_bai()
{
	if(!do_check("$N说道：仪式都不举行就跑！这还结什么婚！\n"))
		return;

	if(bai <= 0)
		bai = 0;

	bai++; time = time();

	switch(bai)
	{
		case 1:
		message_vision(sprintf("$N郑重说道：今有我朝。。良善子民%s和%s。。举行结婚大礼，本部堂
	代表。。。朝廷。。。予以恩准，主持婚礼。。。。。。

一。。。拜(koubai)。。。天。。。地。。。。。。\n\n",master->name(),working->name()),this_object());
			return;
		case 2:
		message_vision("$N点点头说道：
二。。。拜(koubai)。。。主。。。持。。。人。。。。。。\n\n",this_object());
			return;
		case 3:
		message_vision("$N点点头说道：
夫。。。妻。。。对。。。拜(koubai)。。。。。。\n\n",this_object());
			return;
	}
}

void init()
{
	add_action("do_bai","koubai");
}

int do_bai()
{
	object me = this_player();

	if(!bai || ( (me!= master) && (me != working)))
		return 0;

	if(me->query_temp("marry_bai") == bai)
	{
		write(name()+"瞪你一眼说道：乱拜什么！听我号令行事！\n");
		return 1;
	}

	if(!do_check("$N说道：婚礼还没举行完人就跑了！太不像话了！哼！\n"))
	{
		bai = 0;
		return 1;
	}

	switch (bai)
	{
		case 1:
			me->start_busy(2);
			message_vision("\n$N恭恭敬敬的朝着供在上面的“合和”二仙拜了下去，
嘴里说道：感谢上苍赐我们这段因缘。\n\n",me);
			me->set_temp("marry_bai",bai);
			if( (master->query_temp("marry_bai") == bai)
			&& (working->query_temp("marry_bai") == bai) )
				call_out("on_bai",3);
			return 1;
		case 2:
			me->start_busy(2);
			message_vision("\n$N恭恭敬敬的朝着礼部堂官和事老拜了下去，
嘴里说道：感谢朝廷恩准，感谢和大人主持。\n\n",me);
			message_vision("$N笑眯眯的点了点头说道：好说，好说。。。\n");
			me->set_temp("marry_bai",bai);
			if( (master->query_temp("marry_bai") == bai)
			&& (working->query_temp("marry_bai") == bai) )
				call_out("on_bai",3);
			return 1;
		case 3:
			me->start_busy(2);
			if(me->query("gender") == "男性")
				message_vision(sprintf("\n$N朝着$n拜了下去，说道：%s某人今日能娶%s为妻，三生有幸，
定将细心疼爱，今生不移。\n\n",me->name()[0..1],working->name()),me,working);
			else
				message_vision("\n$N朝着$n拜了下去，说道：小女子以终生相托，望相公
怜香惜玉，始终如一。\n\n",me,master);

			me->set_temp("marry_bai",bai);
			if( (master->query_temp("marry_bai") == bai)
			&& (working->query_temp("marry_bai") == bai) )
				call_out("finish_bai",5);
			return 1;
	}
}

private void finish_bai()
{
	mapping mm,mw;
	object mp = present("mei po",environment()),mcard;
	int y,m,d;
	string date;

	bai = 0;

	if(!do_check("$N说道：婚礼还没举行完人就跑了！太不像话了！哼！\n"))
		return;

	message_vision("$N笑呵呵的说道：
礼。。。。。。成。。。。。。！！\n\n",this_object());
	message_vision("$N说道：祝二位相亲相爱，白头到老！\n\n",this_object());

	if(!mp)
	{
		mp = new(__DIR__"meipo");
		mp->move(environment());
	}

	message_vision("$N走上前笑嘻嘻的说道：恭喜！恭喜！\n\n",mp);

	message_vision("$N拿起两张证书仔细填好分别交给两位新人。\n\n",this_object());

	y = query_year();
	m = query_month();
	d = query_day_in_month();

	date = sprintf("创世%s年%s月%s日",chinese_number(y),chinese_number(m),chinese_number(d));

	mm = allocate_mapping(3);
	mw = allocate_mapping(3);

	mm["id"] = working->query("id");
	mm["name"] = working->query("name");
	mm["date"] = date;

	mw["id"] = master->query("id");
	mw["name"] = master->query("name");
	mw["date"] = date;

	master->set("marry",mm); master->save();
	working->set("marry",mw); working->save();

	mcard = new(MARRYCARD_OB);
	mcard->set_master( master->name(),
		geteuid(master),
		mm["name"],
		mm["id"],
		mm["date"]);
	mcard->move(master);

	mcard = new(MARRYCARD_OB);
	mcard->set_master( working->name(),
		geteuid(working),
		mw["name"],
		mw["id"],
		mw["date"]);
	mcard->move(working);

	CHANNEL_D->do_channel( this_object(), "guanfu",
		sprintf("经朝廷户部批准、礼部主持，%s和%s结为夫妻。\n",
		master->name(),working->name()));

	NEWS_D->add_news_item( sprintf(HIM"%s(%s) 和 %s(%s) 郎才女貌，两情相悦，
经朝廷户部批准、礼部主持，喜结连理。\n"NOR,
		master->query("name"),capitalize(master->query("id")),
		working->query("name"),capitalize(working->query("id")) ),"p", 1);

	message_vision("$N说道：祝二位相亲相爱，白头到老！
	来人呀，打道回府！\n\n",this_object());

	environment()->can_out(master); environment()->can_out(working);
	call_out("leave",2);
	mp->finish_yishi();
}
