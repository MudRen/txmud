#include <ansi.h>

inherit F_DEALER;

void create()
{
        set_name("老板娘", ({ "laoban niang","laoban","niang" }) );
        set("title",HIW"千里飘香--豆腐花"NOR);
        set("gender", "女性" );
        set("age", 29);
        set("per",30);
        set("long","老板娘是开封城内有名的亮妞。\n");
        set("combat_exp", 10);
        set("attitude", "friendly");
        set("vendor_goods", ([
                __DIR__"obj/choudoufu" : -1,
                __DIR__"obj/youzhadoufu" : -1,
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
                        : ( (time <= 60) ? CYN"老板娘道：一会就开门了，这位客官请等一下吧。\n"NOR
                        : CYN"老板娘揉了揉眼睛,柔柔道：天还没亮，本点现在不营业。\n"NOR ) );
                return;
        }
        else
        {
                switch( random(2) )
                {
                case 0:
                        say( CYN"老板娘扭着细腰走过来道：这位" + RANK_D->query_respect(ob)
                                + "里边请，想吃豆腐吗？\n"NOR);
                        break;
                case 1:
                        say( CYN"老板娘媚眼闪闪,道：这位" + RANK_D->query_respect(ob)
                                + "，吃点豆腐吧,香着呢,保您不后悔。\n"NOR);
                        break;
                }
        }
}
