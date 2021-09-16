// lu.c

inherit NPC;

mixed ask_me(object);

void create()
{
        set_name("陆佑明", ({ "lu youming" }) );
        set("gender", "男性" );
        set("age", 56);
        set("long", "这是一位瘦弱的小老头，从他饱经沧
桑的脸上能看出经历不凡。\n");

	set(NO_KILL, 1);

	set("inquiry",([
	"无花果" : (: ask_me :),
	"无花果干" : (: ask_me :),
]));

        set("combat_exp", 1000);

	set_skill("unarmed",20);
        set("attitude", "friendly");
        setup();
        carry_object(ARMOR_DIR"cloth")->wear();
}

mixed ask_me(object who)
{
	mapping q;

	if(!mapp(q = who->query("quest/tangmen_quest"))
	|| (q["name"] != "无花果干") )
		return "我家这棵树上每年就结这么几个，还要留着卖大价钱呢。";

	if(q["lu_give"])
		return "不是给你一个了，我哪有那么多！";

	if(q["lu_asked"])
		return "不是和你说了条件了，这么贵重的东西哪能白给你。";

	tell_object(who, "
陆佑明说道：我家这棵无花果树是我好不容易才从云南移
来栽活的，每年就结这么几个。不过既然是唐家堡需要，
老朽就卖你一个面子，不过你要先帮我一个忙，这几天成
都闹贼，我家的一块『白壁玲珑玉』也被偷了，你能不能
帮我找回来。\n");

	q["lu_asked"] = 1;

	q["hint"] += "\t帮助陆员外找回被偷的『白壁玲珑玉』，然后交还给他。";

	return 1;
}

protected void refresh_inv()
{
	object *inv;
	int n;

	if(n = sizeof(inv = filter_array(all_inventory(this_object()), (: $1->query("id") != "cloth" :))))
		for(int i=0; i<n; i++)
			destruct(inv[i]);
}

int accept_object(object me, object ob)
{
	mapping q;
	object whg;

	if(!mapp(q = me->query("quest/tangmen_quest"))
	|| (q["name"] != "无花果干")
	|| !q["entered_hy"]
	|| (base_name(ob) != __DIR__"obj/baiyu") )
		return 0;

	if( q["get_wuhuaguo"]
#ifdef WIZARD_FLAG
	|| (ob->query_wiz_flag() && !wizardp(me))
#endif
	|| (ob->query_master() != me->query("id")) )
		tell_object(me, "陆员外摇摇头说道：这块假壁做得还真像那么回事，
                  留着给我小孙孙当玩艺吧。\n");

	else
	{
		q["get_wuhuaguo"] = 1;
		tell_object(me, "陆员外高兴地说道：正是它，这可是我们家的传家宝，谢谢你了。\n");
		whg = new(__DIR__"obj/wuhuaguo");
		if(!whg->move(me) && !whg->move(environment()))
			destruct(whg);
	}

	if(find_call_out("refresh_inv") <= 0)
		call_out("refresh_inv", 3);
	return 1;
}
