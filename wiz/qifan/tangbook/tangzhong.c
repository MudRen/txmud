// tangzhong.c

inherit NPC;

nomask int is_doctor() {return 1;}
protected void do_cure(object, string);

void create()
	{
	set("class", "tangmen");

	set_name("唐忠", ({"doctor zhong"}));
	set("title", "蒙汗药当白面");

	set("long", @TEXT
唐忠是上一代堡主的仆人，出身微贱，
但却非常聪颖，在老堡主身边耳濡目
睹数十年，对各种毒物研究有加，尤
其擅长解毒。
TEXT
);

	set(NO_KILL, 1);

	set("gender","男性");
	set("age",65);
	set("con",20);
	set("str",20);
	set("combat_exp",200);
	set("inquiry",([
	"工作" : (: ask_me :),
	"丹药" : (: ask_me :),
	]));

	setup();
	carry_object(ARMOR_DIR"cloth")->wear();
}

void init()
	{
	::init();
	add_action("do_ask", "ask");
}

int do_ask( string arg )  /* return 0 let ask command process this action. */
{
	object me = this_player();
	string name, what;

	if( me->is_busy() )
		return notify_fail(BUSY_MESSAGE);

	if( !arg || !stringp(arg) )
		return 0;

	if( sscanf( arg, "%s about %s", name, what ) != 2 )
		return 0; 

	if( !id(name) )
		return 0;

	if(me->query("class") != "tangmen")
	{
		write("不是唐门弟子免开尊口。\n");
		return 1;
	}

	if( what != "疗伤" && what != "解毒" )
		return 0;

	if( what == "疗伤"
	&& me->query("eff_kee") >= me->query("max_kee")
	&& me->query("eff_gin") >= me->query("max_gin")
	&& me->query("eff_sen") >= me->query("max_sen") )
	{
		write(sprintf("%s打量了你一下说道：这位%s面色红润，没有受伤呀。\n",
			name(),RANK_D->query_respect(me)));
		return 1;
	}

	if( (what == "解毒")
	&& !me->query_condition("snake_poison")
	&& !me->query_condition("tangdu")
	&& !me->query_condition("mabi") )
	{
		write(sprintf("%s摇摇头说道：你中了什么毒，我看不出来。\n",name()));
		return 1;
	}

	if( me->query_condition("heal_up") )
	{
		write(name()+"说道：“你上次看病用的药还没有失效，不能再用药了，你过几天再来吧。”\n");
		return 1;
	}

	do_cure(me, what);
	return 1;
}

protected void do_cure( object me, string what )
	{
	switch( what )
	{
		case "疗伤" :
			write(sprintf("%s端出一碗汤药给你喝了下去，然后说道：“好好休息，过两天就会好的。”\n",name()));
			me->apply_condition("heal_up", 20 );
			break;

		case "解毒" :
			/* 其他一般的毒完成后在这里加上，特殊的毒应该由本人的特制解药在区域中解决。*/

			write(name()+"端出一碗药给你喝下又看了看你说道：“好了，你体内的毒已经拔尽了。”\n");
			me->clear_condition("snake_poison");
			me->clear_condition("mabi");
			me->clear_condition("tangdu");
			break;
        }
}

int ask_quest(object me)

	object me, du;
	string msg, targ;
	int coun;

	string *targ = ({
		"白芍","半夏","蔻仁","龙眼","牛黄","三七","石苇","天仙藤","五加皮"
	});

	me = this_player();
	du = this_object();

	{
	if( (me->query("quest/tangmen_quest/name") != "炼丹")
	command(sprintf("say %s","你先去药圃采棵药材，然后拿去炼药堂炼丹。"));
	me->set_temp("asked_tangzhong",1);
	return 1;
	}

	{
		if ( (int)me->query_temp("yao") )
		{
	                command("say “你还没有完成刚才给你的任务呢！”");
			return 1;
		}
		coun = 1 + random(sizeof(tar));
		if ( coun == sizeof(tar) )
			coun = ( sizeof(tar) - 1 );
		targ = tar[coun];
		printf("%d/%d\n",coun,sizeof(tar));
		say("唐忠说道:“我这里正缺一份药物，快去给我找一份" + targ + "来吧！”\n");
		me->set_temp("yao",coun);
	}

void init()
{
	add_action("do_give","give");
}

int do_give(string arg)
{
	object obj, obj2, me, *inv, who;
	string item;
	int amount, i;

	me = this_player();

	if(!arg) return notify_fail("你要给谁什么东西？\n");

	if( sscanf(arg, "%s to tz", item) == 1 || sscanf(arg, "tz %s", item)==1 );
		else 
			return notify_fail("你要给谁什么东西？\n");

	if(!objectp(who = present("tang zhong", environment(me))) || !living(who))
		return notify_fail("这里没有这个人。\n");

	if(sscanf(item, "%d %s", amount, item)==2)
	{
		if( !objectp(obj = present(item, me)) )	
			return notify_fail("你身上没有这样东西。\n");
		if( !obj->query_amount() )	
			return notify_fail( obj->name() + "不能被分开给人。\n");
		if( amount < 1 )
			return notify_fail("东西的数量至少是一个。\n");
		if( amount > obj->query_amount() ) 
			return notify_fail("你没有那么多的" + obj->name() + "。\n");
		else 
			if( amount == (int)obj->query_amount() )
				return do_giveto(me, obj2);
			else
			{
				obj->set_amount( (int)obj->query_amount() - amount );
				obj2 = new(base_name(obj));
				obj2->set_amount(amount);
				if (do_giveto(me, obj2))
					return 1;
				else
				{
					obj->set_amount((int)obj->query_amount() + amount);
					return 0;
				}
			}
	}

	if(arg=="all")
	{
		inv = all_inventory(me);
		for(i=0; i<sizeof(inv); i++)
		{
			do_giveto(me, inv[i]);
		}
		write("Ok.\n");
		return 1;
	}

	if(!objectp(obj = present(item, me)))
		return notify_fail("你身上没有这样东西。\n");
	return do_giveto(me, obj);
}

int do_giveto(object me, object obj)
{
	if ( obj->query("id") == "cao yao" && !userp(obj) )
	{
		message_vision("唐忠说道：“辛苦你了，就是这个！”\n", me);
		destruct(obj);
		me->delete_temp("tangmen");
		me->delete_temp("yao");
		me->delete_temp("find");
		return 1;
	}

}

protected void give_yaofen(object me)
	{
	object yaofen;

	if(!me || (environment(me) != environment())
	|| me->query("quest/tangmen_quest/have_yaofen") )
		return;

	guan = new(__DIR__"obj/yaofen");
	guan->move(this_object());
	me->set("quest/tangmen_quest/have_yaofen",1);
	tell_object(me,sprintf("%s点点头说道：就是这个了。\n",name()));
	tell_object(me,sprintf("%s转身将药物放到石舂里捣碎，然后倒在一个药包交给你，然后说，快去炼丹吧。\n",name()));
	command(sprintf("give yaofen to %s",me->query("id")));
}