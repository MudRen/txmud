inherit F_DEALER;

void create()
{
        set_name("木材店老板", ({ "lao ban", "boss"}) );
        set("gender", "男性");
        set("age", 62);
        set("long", "木材店老板看起来像个老大娘。\n");

        set("combat_exp", 120);
        set("attitude", "friendly");

        set("sell_all_day",1);

        set("vendor_goods", ([
                __DIR__"obj/mutou" : -1,
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
                        command(sprintf("say 这位%s想点木材吗?", RANK_D->query_respect(ob)));
                        break;
                case 1:
                        command("say 本店全天营业，敬请随时光临。");
                        break;
        }
}
