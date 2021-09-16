// fruit_seller.c

inherit F_DEALER;

void create()
{
	set_name("水果贩子", ({ "fruit seller","seller" }) );
	set("gender", "男性" );
	set("age", 28);
	set("long", "一个卖水果的小贩，正在起劲的向行人兜售水果。\n");
	set("combat_exp", 5000);
	set("attitude", "friendly");
	set_skill("unarmed", 60);
	set_skill("dodge", 100);
	set_skill("throwing", 30);

	set("vendor_goods", ([
		__DIR__"obj/apple":5,
		__DIR__"obj/pear":5,
		__DIR__"obj/strawberry":5,
		__DIR__"obj/grape":5,
		__DIR__"obj/melon":5,
	]) );

	setup();
	add_money("silver", 1);
	add_money("coin", 100);
	carry_object(ARMOR_DIR"cloth")->wear();
}

void init()
{
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}

void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        switch( random(2) ) {
                case 0:
                        say( "水果贩子高喊：买水果啦，又香又甜的水果。\n");
                        break;
                case 1:
                        say( "水果贩子高喊：又解渴又充饥啦。\n");
                        break;
        }
}