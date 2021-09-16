inherit F_DEALER;

void create()
{
        set_name("李玉堂", ({ "li yutang", "li" , "yutang"}) );
        set("gender", "男性" );
        set("age", 42);

        set("long", "李老板一看就是个生意人，戴着个小眼镜。\n");

        set("combat_exp", 1000);
        set("attitude", "friendly");

        set("sell_all_day",1);
        set("vendor_goods", ([
                __DIR__"obj/xianglian":-1,
                __DIR__"obj/shouzhuo":-1,
                __DIR__"obj/erhuan":-1,
                __DIR__"obj/jiezhi":-1,
        ]) );

        setup();
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
                        command(sprintf("say 这位%s想买点首饰吗?", RANK_D->query_respect(ob)));
                        break;
                case 1:
                        command("say 本店全天营业，敬请随时光临。");
                        break;
        }
}
