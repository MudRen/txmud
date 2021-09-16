// yu_fanzi.c

inherit NPC;

string *valid_rooms = ({
"lu19",
"lu18",
"lu17",
"lu16",
"lu5",
});

void do_move();

#ifdef WIZARD_FLAG
private int check_sell_object(object me,object ob)
{
	string name;

	if(!objectp(me) || !objectp(ob))
		return 0;
	if(ob->query_wiz_flag() && !wizardp(me))
	{
		name = ob->name();
		log_file("shop",sprintf("%s 在 %s 卖巫师物品 %s 被没收. %s\n",
			geteuid(me),to_chinese(domain_file(base_name(this_object()))),
			base_name(ob),ctime(time())));
		destruct(ob);
		return notify_fail(ob->name()+"是巫师物品被没收了，请立刻向天神发信做出解释！\n");
	}
	else
		return 1;
}
#endif

void create()
{
	set_name("鱼贩子", ({"yu fanzi"}));
	set("long", "这是一位满脸尖滑的鱼贩子。");
	set("gender","男性");

        set(NO_KILL, 1);
        set("age",35);
        set("con",20);
        set("str",20);

	set("chat_chance", 10);
	set("chat_msg", ({
		(: do_move :),
	}) );

        set("combat_exp",3000);

        setup();
        carry_object(ARMOR_DIR"cloth")->wear();
}

void init()
{
	add_action("do_sell", "sell");
}

int do_sell(string arg)
{
        object ob;
        int value;

	if(!query("startroom"))
		return 0;

	if( !arg || !(ob = present(arg, this_player())) )
		return notify_fail("你要卖什么？\n");

	if(!ob->is_jinghai_fish())
		return notify_fail(name()+"说道：我这只收海边刚打上来的鲜鱼。\n");

#ifdef WIZARD_FLAG
	if(!check_sell_object(this_player(),ob))
		return 0;
#endif

	if(!value = ob->query("value"))
		return notify_fail("这样东西不值钱。\n");

	if(value < 10)
		return notify_fail(ob->query("name")+"价值太低，这不收。\n");

	if( (time() - ob->query("time")) > 1440 )
	{
		write(name()+"说道：你这鱼打上来的时间太长，就折个半价吧。\n");
		value /= 2;
	}

	message_vision("$N把身上的" + ob->query("name") + "卖掉。\n",this_player());
	pay_player(this_player(), value);

	destruct(ob);
	return 1;
}

void do_move()
{
	mapping exits;
	string *dirs,start,domain,fname;
	int n,i,idx;
	object home;

	if(!environment() || !query("startroom"))
		return;

	if(sscanf(query("startroom"),"/d/%s/%*s",start) != 2 )
		return;

	if(sscanf(base_name(environment()),"/d/%s/%s",domain,fname ) != 2)
		return;

	if(domain != start || member_array(fname,valid_rooms) == -1)
	{
		home = find_object(query("startroom"));
		if(!home)
			home = load_object(query("startroom"));
		if(home)
			return_home(home);
		return;
	}

	if( !mapp(exits = environment()->query("exits")) )
		return;

	dirs = keys(exits);
	n = sizeof(dirs);
	if(!n)
		return;

	for(i=0;i<n;i++)
	{
		idx = strsrch(exits[dirs[i]],"/",-1);
		if(idx == -1
		|| member_array(exits[dirs[i]][idx+1..],valid_rooms) == -1)
			dirs[i] = 0;
	}

	dirs -= ({ 0 });
	if(!(n = sizeof(dirs)))
		return;

	command("go " + dirs[random(n)]);
}
