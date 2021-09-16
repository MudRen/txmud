inherit F_DEALER;

void create()
{
        set_name("烤肉店老板", ({ "lao ban", "boss" }) );
        set("gender", "男性" );
        set("age", 52);

        set("long", "烤肉店老板是个和蔼的老人。\n");

        set("combat_exp", 10);
        set("attitude", "friendly");

        set("sell_all_day",1);

        set("vendor_goods", ([
                __DIR__"obj/kaoyangrou" : -1,
                __DIR__"obj/kaoniurou" : -1,
        ]) );


        setup();
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
                        command(sprintf("say 这位%s来尝尝我们店的烤肉。", RANK_D->query_respect(ob)));
                        break;
                case 1:
                        command("say 本店全天营业，敬请随时光临。");
                        break;
        }
}
