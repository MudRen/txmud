inherit F_DEALER;

void create()
{
        set_name("杂货铺老板", ({ "lao ban", "boss"}) );
        set("gender", "男性");
        set("age", 56);
        set("long", "杂货铺老板年过半百,两鬓的头发已经白了.\n");

        set("combat_exp", 200);
        set("attitude", "friendly");

        set("sell_all_day",1);

        set("vendor_goods", ([
                MISC_DIR"bag" : -1,
                MISC_DIR"lamp" : 30,
		__DIR__"obj/she_cha" : 20,
		"/obj/mine/sz_gao" : -1,
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
                        command(sprintf("say 这位%s想买点什么?", RANK_D->query_respect(ob)));
                        break;
                case 1:
                        command("say 本店全天营业，敬请随时光临。");
                        break;
        }
}

