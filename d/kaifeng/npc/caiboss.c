#include <ansi.h>

inherit F_DEALER;

void create()
{
        set_name("菜老板", ({ "lao ban","boss"}) );
        set("gender", "男性" );
        set("age", 35);
        set("long","菜老板是个闲不住的人,总想找点活干。\n");
        set("combat_exp", 100);
        set("attitude", "friendly");
        set("vendor_goods", ([
                __DIR__"dabaicai" : -1,
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
                say( (time > 480) ? CYN"这么晚的天，菜场一个人都没有了，"+RANK_D->query_respect(ob)+
                        "还是明天再来吧。\n"NOR
                        : ( (time <= 60) ? CYN"菜老板道：马上就要营业了，这位客官请等一下吧。\n"NOR
                        : CYN"菜老板打了个哈嗤说道：菜场没开门，想买菜天亮再说。\n"NOR ) );
                return;
        }
        else
        {
                switch( random(2) )
                {
                case 0:
                        say( CYN"菜老板喊道：快来买大白菜呀!\n"NOR);
                        break;
                case 1:
                        say( CYN"菜老板道：这位" + RANK_D->query_respect(ob)
                                + "，想买点大白菜?\n"NOR);
                        break;
                }
        }
}
