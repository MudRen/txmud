//waitress.c 林芝村酒楼的招待。
#include <ansi.h>
inherit F_DEALER;
void create()
{
        set_name("女招待", ({"xiao jie","waitress",}));
        set("title","香格里拉");
        set("gender", "女性" );
        set("age",18);
        set("per",27);
        set("long","一位年轻的小姐，看上去天真迷人。\n");
        set("combat_exp", 50);
        set("attitude", "friendly");
        set("vendor_goods", ([
                "/d/changan/npc/obj/noodles" : -1,
                "/d/changan/npc/obj/ysd" : -1,
                FOOD_DIR"chicken_leg" : -1,
                LIQUID_DIR"bowl" : -1,
                MISC_DIR"top" : 50,
        ]) );
        setup();
        carry_object(__DIR__"obj/skirt")->wear();
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
                message_vision(CYN"$N用会说话的眼睛盯着$n,抱歉的一笑。\n"NOR,this_object(),ob);
                ob->go_back_direction();
        }

        if(!is_day())
        {
                sscanf( day_night(),"%s %d",day_night,time);
                say( (time > 480) ? CYN"这么晚的天，本店已经打烊了，"+RANK_D->query_respect(ob)+
                        "请明天再来吧。\n"NOR
                        : ( (time <= 60) ? CYN"女招待歉然一笑：马上就要开门了，这位客官请等一下吧。\n"NOR
                        : CYN"女招待强打精神说道：小店还没有开门，请天亮了再来吧。\n"NOR ) );
                return;
        }
        else
        {
                switch( random(2) )
                {
                case 0:
                        say( CYN"女招待笑咪咪地说道：香格里拉的饭菜远近闻名。\n"NOR);
                        break;
                case 1:
                        say( CYN"女招待手一伸说道：这位" + RANK_D->query_respect(ob)
                                + "，请进请进。\n"NOR);
                        break;
                }
        }
}
