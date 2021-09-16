// wangboss.c

#include <ansi.h>

inherit F_DEALER;

void create()
{
        set_name("王万金", ({ "wang wanjin" }) );
        set("title","鸭子王");
        set("gender", "男性" );
        set("age", 41);
        set("sell_all_day",1);
        set("long","一看他就是一位奸商．\n");
        set("combat_exp", 50);
        set("attitude", "friendly");
        set("vendor_goods", ([
                __DIR__"obj/yazi":10,
                __DIR__"obj/wangya":10,

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
        if( !ob
        || (environment(ob) != environment())
        || file_name(environment()) != this_object()->query("startroom"))
                return;
 
        switch( random(2) )
        {
                case 0:
                        say( CYN"王万金笑眯眯道：这位" + RANK_D->query_respect(ob)
                                + "，快请进。\n"NOR);
                        break;
                case 1:
                        say( CYN"王万金说道：这位" + RANK_D->query_respect(ob)
                                + "想要来只鸭子吗？\n"NOR);
                        break;
        }
}
