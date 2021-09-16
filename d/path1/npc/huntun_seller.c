// hundun_seller.c

inherit F_DEALER;

void create()
{
	set_name("ÂôâÆâ½Ð¡··", ({ "huntun seller","seller" }) );
	set("gender", "ÄÐÐÔ" );
        set("age", 37);
        set("long","ÕâÊÇÒ»Î»ÂôâÆâ½µÄÐ¡··£¬Ò»±ßÖóâÆâ½Ò»±ß
Æð¾¢µÄßººÈ×Å¡£\n");
        set("combat_exp", 50);
        set("attitude", "friendly");
	set("sell_all_day",1);

	set("vendor_goods", ([
		__DIR__"obj/huntun":20,
	]) );

        setup();
	carry_object(ARMOR_DIR"cloth")->wear();
}

void init()
{       
        object ob;

        ::init();
        if( interactive(ob = previous_object()) && !is_fighting() )
	{
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}

void greeting(object ob)
{
	if( !ob
	|| (environment(ob) != environment())
	|| file_name(environment()) != this_object()->query("startroom"))
		return;

	say(sprintf("%sßººÈµÀ£º¡°ÕâÎ»%sÐªÐª½ÅÀ´ÍëâÆâ½°É¡£¡±\n",name(),RANK_D->query_respect(ob)));
}