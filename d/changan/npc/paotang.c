// paotang.c

#include <ansi.h>

inherit F_DEALER;

void create()
{
        set_name("跑堂", ({ "pao tang","tang","waiter" }) );
	set("title","谪仙楼");
        set("gender", "男性" );
        set("age", 22);
        set("long","小跑堂里外忙着，还不时要和进来的客人打招呼。\n");
        set("combat_exp", 50);
        set("attitude", "friendly");
        set("vendor_goods", ([
		__DIR__"obj/noodles" : -1,
		__DIR__"obj/ysd" : -1,
		FOOD_DIR"chicken_leg" : -1,
		LIQUID_DIR"bowl" : -1,
		MISC_DIR"top" : 50,
        ]) );
        setup();
	carry_object(ARMOR_DIR"cloth")->wear();
}

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
		message_vision(CYN"$N冲着$n喊道：这不是你来的地方，赶紧滚！\n"NOR,this_object(),ob);
		ob->go_back_direction();
	}

	if(!is_day())
	{
		sscanf( day_night(),"%s %d",day_night,time);
		say( (time > 480) ? CYN"这么晚的天，小店已经打烊了，"+RANK_D->query_respect(ob)+
			"请明天再来吧。\n"NOR
			: ( (time <= 60) ? CYN"小跑堂点头哈腰：马上就要开门了，这位客官请等一下吧。\n"NOR
			: CYN"跑堂打了个哈嗤说道：小店还没有开门，请天亮了再来吧。\n"NOR ) );
		return;
	}
	else
	{
		switch( random(2) )
		{
                case 0:
                        say( CYN"小跑堂笑咪咪地说道：醉仙楼的饭菜远近闻名。\n"NOR);
                        break;
                case 1:
                        say( CYN"小跑堂一哈腰说道：这位" + RANK_D->query_respect(ob)
                                + "，请进请进。\n"NOR);
                        break;
		}
	}
}