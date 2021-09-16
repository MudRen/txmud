inherit F_DEALER;

void create()
{
        set_name("陈老板", ({ "chen laoban", "chen" ,"laoban" }) );
        set("gender", "男性" );
        set("age", 45);

        set("long", "陈老板混身药味,好象一生都埋在了药堆里.\n");

        set("combat_exp", 100);
        set("attitude", "friendly");

        set("sell_all_day",1);
        set("vendor_goods", ([
                DRUG_DIR"medicine_ganmao":-1,
                DRUG_DIR"huandan":50,
        ]) );

        setup();
        add_money("silver", 1);
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
                        command(sprintf("say 这位%s想买点什么药吗?", RANK_D->query_respect(ob)));
                        break;
                case 1:
                        command("say 本店全天营业，敬请随时光临。");
                        break;
        }
}
