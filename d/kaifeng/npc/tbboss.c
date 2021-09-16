#include <ansi.h>

inherit F_DEALER;

void create()
{
        set_name("驼背老大娘", ({ "lao daniang","daniang"}) );
        set("gender", "女性" );
        set("age", 61);
        set("long","驼背老大娘满脸的皱纹。\n");
        set("combat_exp", 10);
        set("attitude", "friendly");
        set("vendor_goods", ([
                FOOD_DIR"chicken_leg" : -1,
                __DIR__"obj/huashengmi" : -1,
                FOOD_DIR"dumpling" : -1,
               LIQUID_DIR"wineskin" : -1,
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

        if(!is_day())
        {
                sscanf( day_night(),"%s %d",day_night,time);
                say( (time > 480) ? CYN"小店已经打烊了，"+RANK_D->query_respect(ob)+
                        "明天再来吧。\n"NOR
                        : ( (time <= 60) ? CYN"驼背老大娘道：一会就开门了，这位客官请等一下吧。\n"NOR
                        : CYN"驼背老大娘揉了揉眼睛说道：天还没亮，本点现在不营业。\n"NOR ) );
                return;
        }
        else
        {
                switch( random(2) )
                {
                case 0:
                        say( CYN"驼背老大娘笑呵呵说道：这位" + RANK_D->query_respect(ob)
                                + "里边请，喝点酒？尝尝新炸出来的花生米？\n"NOR);
                        break;
                case 1:
                        say( CYN"驼背老大娘说道：这位" + RANK_D->query_respect(ob)
                                + "，快进来歇一会。\n"NOR);
                        break;
                }
        }
}
