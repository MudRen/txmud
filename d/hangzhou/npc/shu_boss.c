// shu_boss.c
// By Find.

#include <ansi.h>

inherit F_DEALER;

void create()
{
        set_name("刘勤学", ({ "boss liu", "boss"}) );
	set("title","书店老板");
        set("gender", "男性" );
        set("age", 45);
        set("long","书店老板。\n");
        set("combat_exp", 50);
        set("attitude", "friendly");
        set("vendor_goods", ([
		BOOK_DIR"luo_book":5,
		BOOK_DIR"guwen_book":5,
		BOOK_DIR"parrybook" : 3,
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
		message_vision(CYN"$N冲着$n说道：别影响我做生意，赶紧出去！\n"NOR,this_object(),ob);
		ob->go_back_direction();
		return;
	}

	if(!is_day())
	{
		sscanf( day_night(),"%s %d",day_night,time);
		say( (time > 480) ? CYN"对不起，鄙号已经关门了，"+RANK_D->query_respect(ob)+
			"请明天再来吧。\n"NOR
			: ( (time <= 60) ? CYN"刘老板笑眯眯的说道：请您等一下吧，小号马上就开门了。\n"NOR
			: CYN"刘老板说道：请天亮了再来吧。\n"NOR ) );
		return;
	}
	else
	{
		switch( random(2) )
		{
                case 0:
                        say( CYN"刘老板嘴里咕哝着：书中自有黄金屋。。。颜如玉。。。\n"NOR);
                        break;
                case 1:
                        say( CYN"刘老板一哈腰说道：这位" + RANK_D->query_respect(ob)
                                + "光临，小号蓬壁生辉，请进，请进。\n"NOR);
                        break;
		}
	}
}
