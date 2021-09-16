// ph_girl.c

inherit NPC;

string ask_me(object who);
private int working;

void create()
{
	set_name("煎药女僮", ({ "pharmacy girl" }) );
	set("gender", "女性" );
	set("age", 20);

	set(NO_KILL, 1);

	set("inquiry",([
	"百云汤" : (: ask_me :),
]));

	set("long", "她整天笑嘻嘻的，一副无忧无虑的样子。\n");
	set("combat_exp", 100);
	set("per", 30);
	set("attitude", "friendly");
	setup();
	carry_object(ARMOR_DIR"cloth")->wear();
}

string ask_me(object who)
{
	string *get;
	object ob1,ob2,ob3,ob4;

	if(working)
		return "正忙着呢，等一会儿吧。";

	if( (who->query("quest/rain_quest/name") == "百云汤")
	&& arrayp(get = who->query("quest/rain_quest/geted"))
	&& (sizeof(get) >= 4) )
	{
		if(!objectp(ob1 = present("lian zi",who)))
			return "你连莲子都没有，没法煎制百云汤。";
		if(!objectp(ob2 = present("jinyin hua",who)))
			return "你连金银花都没有，没法煎制百云汤。";
		if(!objectp(ob3 = present("baishi guo",who)))
			return "你连百实果都没有，没法煎制百云汤。";
		if(!objectp(ob4 = present("buyun cao",who)))
			return "你连步云草都没有，没法煎制百云汤。";

		working = 1;
		destruct(ob1);
		destruct(ob2);
		destruct(ob3);
		destruct(ob4);
		message_vision("$N将$n手上的原料接了过去。\n",this_object(),who);
		call_out("do_working",4,who,0);
		return "好，请等一下，这就好。\n";
	}
}

void do_working(object who,int n)
{
	object ob;

	remove_call_out("do_working");

	if(!who)
	{
		working = 0;
		return;
	}

	switch (n)
	{
		case 0:
			message_vision("$N将原料都投在锅里，兑上水，生起了火。\n\n",this_object());
			call_out("do_working",6,who,++n);
			break;
		case 1:
			message_vision("$N使劲拉着风箱，锅下的火越烧越旺。\n\n",this_object());
			call_out("do_working",6,who,++n);
			break;
		case 2:
			message_vision("锅里的水“咕嘟咕嘟”的响了起来，慢慢的冒出了热气。\n\n",this_object());
			call_out("do_working",6,who,++n);
			break;
		case 3:
			message_vision("锅里的水越熬越少，慢慢的变成了棕红色。\n\n",this_object());
			call_out("do_working",8,who,++n);
			break;
		default:
			message_vision("$N说道：熬好啦。\n说着收了火将锅里的汤倒在碗里。\n\n",this_object());
			if(environment(who) != environment())
			{
				message_vision(sprintf("$N左右看了看%s没在，顺手把熬好的汤倒在了地上。\n\n",
					who->name()),this_object());
				working = 0;
				return;
			}
			ob = new(__DIR__"obj/baiyun_tang");
			ob->move(this_object());
			command(sprintf("give baiyun tang to %s",who->query("id")));
			working = 0;
	}
}
