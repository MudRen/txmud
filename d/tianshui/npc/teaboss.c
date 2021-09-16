// /d/tianshui/npc/tea boss.c

#include <ansi.h>

inherit F_DEALER;

void create()
{
        set_name("茶师", ({ "tea boss","boss" }) );
        set("gender", "男性" );
        set("age", 39);
        set("long","茶师手里拎着一个龙嘴大茶壶里外忙着，还不时和客人打招呼。\n");
        set("combat_exp", 200);
        set("attitude", "friendly");
        set("vendor_goods", ([
		FOOD_DIR"chicken_leg" : -1,
		LIQUID_DIR"kettle" : -1,
        ]) );
        setup();
	carry_object(ARMOR_DIR"cloth")->wear();
}

void init()
{
        object ob;

	::init();
        if( living(ob = previous_object()) && !is_fighting() )
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
		message_vision(CYN"$N冲着$n喊道：这不是你来的地方，赶紧滚！\n"NOR,this_object(),ob);
		ob->go_back_direction();
	}

	if(!is_day())
	{
		sscanf( day_night(),"%s %d",day_night,time);
		say( (time > 480) ? CYN"这么晚的天，小店已经打烊了，"+RANK_D->query_respect(ob)+
			"请明天再来吧。\n"NOR
			: ( (time <= 60) ? CYN"茶师点头哈腰：马上就要开门了，这位客官请等一下吧。\n"NOR
			: CYN"茶师睡眼朦胧地说道：小店还没有开门，请天亮了再来吧。\n"NOR ) );
		return;
	}
	else
	{
		switch( random(2) )
		{
                case 0:
                        say( CYN"茶师笑咪咪地说道：欢迎光临，小店各种名茶俱全，请进请进。\n"NOR);
                        break;
                case 1:
                        say( CYN"茶师一哈腰说道：这位" + RANK_D->query_respect(ob)
                                + "，请进请进。\n"NOR);
                        break;
		}
	}
}