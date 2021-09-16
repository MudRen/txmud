// zhubao_boss.c

#include <ansi.h>

inherit F_DEALER;

private string *passwds = ({"天","上","地","下","人","间","少","有","皇","天","后","土"});
private string party_ob = __DIR__"shouqian";
int want_jingong(object who);
string random_pass()
{
	int i,r;
	string out = "",*temp = passwds;

	for(i=0;i<6;i++)
	{
		out += temp[r = random(sizeof(temp))];
		temp -= ({ temp[r] });
	}
	return out;
}

void create()
{
        set_name("刘乾宏", ({ "liu qianhong","liu","boss" }) );
	set("title","古玩行掌柜");
        set("gender", "男性" );
        set("age", 57);
        set("long","掌柜的已经卸顶,满脸沧桑，但一双精明的眼睛却泛着贼光。\n");
        set("combat_exp", 50);
        set("attitude", "friendly");
	set("inquiry",([
	random_pass() : (: want_jingong :),
]));

        set("vendor_goods", ([
		__DIR__"obj/diamond_ring" : 3,
		__DIR__"obj/shouzhuo":3,
		__DIR__"obj/picture_1":1,
        ]) );

        setup();
	carry_object(ARMOR_DIR"cloth")->wear();
}

void init()
{       
        object ob;

        ::init();
        if( interactive(ob = previous_object()) && !is_fighting() )
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
		message_vision(CYN"$N冲着$n说道：穷光蛋赶紧滚出去！\n"NOR,this_object(),ob);
		ob->go_back_direction();
		return;
	}

	if(!is_day())
	{
		sscanf( day_night(),"%s %d",day_night,time);
		say( (time > 480) ? CYN"刘掌柜盯着你说道：鄙行已经打烊了，"+RANK_D->query_respect(ob)+
			"现在来有什么事情吗？。\n"NOR
			: ( (time <= 60) ? CYN"刘掌柜笑眯眯的说道：客官请等一下吧，马上就开门。\n"NOR
			: CYN"刘掌柜瞟了你一眼说道：现在是鄙行休息时间，你来有什么事情。\n"NOR ) );
		return;
	}
	else
	{
		switch( random(2) )
		{
                case 0:
                        say( CYN"刘掌柜笑咪咪地说道：咱这里是百年老号，货真价实。\n"NOR);
                        break;
                case 1:
                        say( CYN"刘掌柜笑眯眯地说道：欢迎光临，请进请进。\n"NOR);
                        break;
		}
	}
}

void set_passwd(string str)
{
	if( !stringp(str)
	|| str == ""
	|| previous_object() != find_object(party_ob) )
		return;

	set("inquiry",([ str : (: want_jingong :) ]));
}

int want_jingong(object who)
{
	if( !who
	|| !who->query_temp("enter_huanggong_asked")
	|| !environment()
	|| (base_name(environment()) != query("startroom")) )
		return 0;

	if( sizeof( filter_array(all_inventory(environment())-({who,this_object()}),(: $1->is_charactor() :)) ) )
		return 0;

	message_vision("$N警惕的四处看看了，一把把$n拽进了里屋。\n",this_object(),who);
	who->move("/d/changan/zhubao_behind");
	tell_room(environment(who),sprintf("%s踉踉跄跄的从外面走了进来。\n",who->name()),({who}) );
	who->delete_temp("enter_huanggong_asked");
	return 1;
}
