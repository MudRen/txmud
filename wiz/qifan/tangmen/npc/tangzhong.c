// tangzhong.c

inherit NPC;

string ask_me(object who);

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

string ask_me(object who)
{
	object ob;

	if( (who->query("class") != "tangmen")
	|| (who->query("quest/tangmen_quest/name") != "丹药") )
		return 0;

	if(who->query("quest/tangmen_quest/zhong_give"))
		return "东西不是都给了你了，赶紧去采吧。";

	if(!ob = present("yao chu",who))
	{
		ob = new(__DIR__"obj/yaochu");
		if(!ob->move(who))
		{
			ob->move(environment());
			message_vision("$N将一把药锄放在地上。\n",this_object());
		}
		else
			message_vision("$N给$n一把药锄。\n",this_object(),who);

	who->set("quest/tangmen_quest/zhong_give",1);

	return "你去药圃采颗草药，然后拿到炼药房试着炼一颗丹然后去交差。";
	}
}
