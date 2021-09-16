// kuangshiboss.c

#include <ansi.h>

inherit F_DEALER;

void create()
{
        set_name("矿石商", ({ "kuangshi boss" }) );
//	set("title","    ");
        set("gender", "男性" );
        set("age", 42);
        set("long","想卖什么矿石，找他就对了。\n");
        set("combat_exp", 50);
        set("sell_all_day",1);
        set("attitude", "friendly");
        set("vendor_goods", ([
		"/d/obj/kuangshi/qingtong_stone" : -1,
		"/d/obj/kuangshi/lvkuang_stone"  : -1,
		"/d/obj/kuangshi/zikuang_stone"  : -1,
		"/d/obj/kuangshi/hongkuang_stone"  : 20,
		"/d/obj/tanhuo/mutan"  : -1,
		"/d/obj/kuangshi/wujin_stone"  : 0,
		"/d/obj/kuangshi/xuantie_stone"  : 0,
		"/obj/mine/sz_gao": -1,
		"/d/obj/tool/kaishanfu": -1,
		
        ]) );

        setup();
	carry_object(ARMOR_DIR"cloth")->wear();
}
/*

void init()
{
        object ob;

	::init();
        if( living(ob = previous_object()) && !is_fighting() && !wizardp(ob))
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
		message_vision(CYN"$N冲着$n喊道：这不是你来的地方，出去!\n"NOR,this_object(),ob);
		ob->go_back_direction();
	}

	if(!is_day())
	{
		sscanf( day_night(),"%s %d",day_night,time);
		say( (time > 480) ? CYN"这么晚的天，小店已经打烊了，"+RANK_D->query_respect(ob)+
			"请明天再来吧。\n"NOR
			: ( (time <= 60) ? CYN"矿石商对你点点头：马上就要开门了，这位客官请等一下吧。\n"NOR
			: CYN"矿石商打了个哈嗤说道：小店还没有开门，请天亮了再来吧。\n"NOR ) );
		return;
	}
	else
	{
		switch( random(2) )
		{
                case 0:
                        say( CYN"矿石商笑咪咪地说道：我这里有各式的矿石，客官要不要看看啊。\n"NOR);
                        break;
                case 1:
                        say( CYN"矿石商说道：这位" + RANK_D->query_respect(ob)
                                + "，请进请进。\n"NOR);
                        break;
		}
	}
	
}*/