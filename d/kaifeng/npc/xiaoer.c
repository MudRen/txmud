#include <ansi.h>

inherit F_DEALER;

void create()
{
        set_name("小二", ({ "xiao er","er","waiter" }) );
        set("title","开封酒楼");
        set("gender", "男性" );
        set("age", 23);
        set("long","小二里里外外的跑，招待着四面八方来的客人。\n");
        set("combat_exp", 10);
        set("attitude", "friendly");
        set("vendor_goods", ([
                FOOD_DIR"chicken_leg" : -1,
                LIQUID_DIR"bowl" : -1,
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
                        : ( (time <= 60) ? CYN"小二点头哈腰：马上就要开门了，这位客官请等一下吧。\n"NOR
                        : CYN"小二打了个哈嗤说道：小店还没有开门，请天亮了再来吧。\n"NOR ) );
                return;
        }
        else
        {
                switch( random(2) )
                {
                case 0:
                        say( CYN"小二笑咪咪地说道：本酒楼饭菜远近闻名。\n"NOR);
                        break;
                case 1:
                        say( CYN"小二一哈腰说道：这位" + RANK_D->query_respect(ob)
                                + "，快请进。\n"NOR);
                        break;
                }
        }
}

