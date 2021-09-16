// seller.c

inherit F_DEALER;

void create()
{
        set_name("杂货贩子", ({ "zahuo fanzi" }) );
        set("gender", "男性" );
        set("age", 42);
        set("long", "卖杂货的是个年轻汉子，面带微
笑，据华阴村的人说他以前也是一位江湖人。\n");
        set("combat_exp", 100);

	set("sell_all_day",1);
        set("attitude", "friendly");
        set_skill("unarmed", 60);
        set_skill("dodge", 50);

        set("vendor_goods", ([
                BOOK_DIR"s_force_book":2,
                MISC_DIR"bag":10,
		MISC_DIR"torch":20,
        ]) );

        setup();
        carry_object(ARMOR_DIR"cloth")->wear();
}

void init()
{
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() && is_day())
	{
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}

void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
	if( !random(4) )
		say( "杂货贩子笑脸相迎，道：这位"
			+ RANK_D->query_respect(ob)
			+ "，要买什么？\n");
}
