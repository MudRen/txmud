inherit F_DEALER;

void create()
{
        set_name("包子铺老板", ({ "lao ban", "boss"}) );
        set("gender", "男性");
        set("age", 62);
        set("long", "包子铺老板是个老实人，不爱说话。\n");

        set("combat_exp", 200);
        set("attitude", "friendly");

        set("sell_all_day",1);

        set("vendor_goods", ([
                __DIR__"obj/zbaozi":-1,
                __DIR__"obj/nbaozi":-1,
                __DIR__"obj/jbaozi":-1,
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
                        command(sprintf("say 这位%s想买几个包子吃吗?", RANK_D->query_respect(ob)));
                        break;
                case 1:
                        command("say 本店全天营业，敬请随时光临。");
                        break;
        }
}
