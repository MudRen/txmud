// jinboss.c

#include <ansi.h>

inherit F_DEALER;

void create()
{
        set_name("金鸣暗", ({ "jin ming an" }) );
        set("title","防具店老板");
        set("gender", "男性" );
        set("age", 42);
        set("sell_all_day",1);
        set("long","他长的猪鼻鼠目，说有多难看就有多难看。\n");
        set("combat_exp", 50);
        set("attitude", "friendly");
        set("vendor_goods", ([
                __DIR__"obj/armor":10,
                __DIR__"obj/boot":10,
                __DIR__"obj/head":10,
                __DIR__"obj/hands":10,
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
 
        switch( random(4) )
        {
                case 0:
                        say( CYN"金鸣暗说道：这位" + RANK_D->query_respect(ob)
                                + "，请进。\n"NOR);
                        break;
                case 1:
                        say( CYN"金鸣暗说道：这位" + RANK_D->query_respect(ob)
                                + "想要买几件防具吗？\n"NOR);
                        break;
        }
}
