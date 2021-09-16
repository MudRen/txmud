#include <ansi.h>
inherit F_DEALER;

void create()
{
        set_name("潇湘月", ({ "xiaoxiang yue", "yue" ,"xiaoxiang"}) );
        set("gender", "男性" );
        set("title",HIW"翩翩随月行--碧雪寒天"NOR);
        set("age", 24);

        set("long", "潇湘月是个英俊潇洒的公子哥。\n");

        set("combat_exp", 50000);

        set_skill("parry",180);
        set_skill("dodge",180);
        set_skill("unarmed",180);
        set_skill("force",180);

        set("attitude", "friendly");

        set("sell_all_day",1);

        set("vendor_goods", ([
                __DIR__"obj/xiao" : -1,
        ]) );


        setup();
        add_money("silver", 1);
        carry_object(ARMOR_DIR"cloth")->wear();
}

void init()
{
        object ob;
        ::init();
        if( interactive(ob = this_player()) && !is_fighting() )
        {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}

void greeting(object ob)
{
        if( !ob || environment(ob) != environment() )
                return;

        switch( random(4) )
        {
                case 0:
                        command(sprintf("say 这位%s想买什么乐器？", RANK_D->query_respect(ob)));
                        break;
                case 1:
                        command("say 本店全天营业，敬请随时光临。");
                        break;
        }
}

