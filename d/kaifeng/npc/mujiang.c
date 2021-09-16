#include <ansi.h>

inherit F_DEALER;

void create()
{
        set_name("木匠", ({ "mu jiang","waiter" }) );
        set("gender", "男性" );
        set("age", 42);
        set("long","这个木匠据说以前是一位剑客。\n");
        set("combat_exp", 10);
        set("attitude", "friendly");
        set("vendor_goods", ([
                __DIR__"obj/wood_stick" : -1,
                __DIR__"obj/wood_staff" : -1,
                __DIR__"obj/wood_sword" : -1,
                __DIR__"obj/wood_blade" : -1,
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
                        : ( (time <= 60) ? CYN"木匠道：一会就开门了，这位客官请等一下吧。\n"NOR
                        : CYN"木匠揉了揉眼睛说道：天还没亮，本点现在不营业。\n"NOR ) );
                return;
        }
        else
        {
                switch( random(2) )
                {
                case 0:
                        say( CYN"木匠笑呵呵说道：这位" + RANK_D->query_respect(ob)
                                + "里边请，想买点什么称手的兵器？\n"NOR);
                        break;
                case 1:
                        say( CYN"木匠说道：这位" + RANK_D->query_respect(ob)
                                + "，我这的木器在开封城可是有名的哦。\n"NOR);
                        break;
                }
        }
}
