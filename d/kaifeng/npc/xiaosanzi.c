inherit F_DEALER;

void create()
{
        set_name("小三子", ({ "xiao sanzi", "waiter" ,"sanzi" }) );
        set("gender", "男性" );
        set("age", 23);
set("title","春来福酒楼");

        set("long", "小三子是个光头小伙子。\n");

        set("combat_exp", 100);
        set("attitude", "friendly");

        set("sell_all_day",1);

        set("vendor_goods", ([
                FOOD_DIR"chicken_leg" : -1,
                LIQUID_DIR"bowl" : -1,
                "/d/changan/npc/obj/yuxiang":-1,
                "/d/changan/npc/obj/tuofeng":-1,
                "/d/changan/npc/obj/yuchi":-1,
                "/d/changan/npc/obj/yinyu":-1,
                "/d/changan/npc/obj/shizi_tou":-1,
                "/d/changan/npc/obj/taxue":-1,
]) );

        setup();
        carry_object(WEAPON_DIR"sword")->wield();
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
                        command(sprintf("say 这位%s想吃点什么?", RANK_D->query_respect(ob)));
                        break;
                case 1:
                        command("say 本店全天营业，敬请随时光临。");
                        break;
        }
}
