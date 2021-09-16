#include <ansi.h>

inherit F_DEALER;

void create()
{
        set_name("钱老板", ({ "qiao laoban","qian","laoban" }) );
        set("gender", "男性" );
        set("title",HIR"见钱眼开"NOR);
        set("age", 46);
        set("long","钱老板整天拿着个旱烟壶，一副奸商的样子。\n");
        set("combat_exp", 1000);
        set("attitude", "friendly");
        set("vendor_goods", ([
                __DIR__"obj/huangjinxianglian" : -1,
                __DIR__"obj/manaoshouzhuo" : -1,
                __DIR__"obj/feicuijiezhi" : -1,
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
                        : ( (time <= 60) ? CYN"钱老板道：一会就开门了，这位客官请等一下吧。\n"NOR
                        : CYN"钱老板揉了揉眼睛说道：天还没亮，本点现在不营业。\n"NOR ) );
                return;
        }
        else
        {
                switch( random(2) )
                {
                case 0:
                        say( CYN"钱老板懒洋洋道：这位" + RANK_D->query_respect(ob)
                                + "想买点首饰吗？\n"NOR);
                        break;
                case 1:
                        say( CYN"钱老板说道：这位" + RANK_D->query_respect(ob)
                                + "，不买可别乱碰。\n"NOR);
                        break;
                }
        }
}
