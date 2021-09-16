inherit F_DEALER;

void create()
{
        set_name("海老板", ({ "hai laoban", "hai","boss"}) );
        set("gender", "男性");
        set("age", 54);
        set("long", "海老板专门经营海鲜产品.\n");

        set("combat_exp", 100);
        set("attitude", "friendly");

        set("sell_all_day",1);

        set("vendor_goods", ([
                __DIR__"obj/daxia" : -1,
                __DIR__"obj/liyu" : -1,
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
                        command(sprintf("say 这位%s想买点海鲜尝尝吗?", RANK_D->query_respect(ob)));
                        break;
                case 1:
                        command("say 本店全天营业，敬请随时光临。");
                        break;
        }
}
