// shucai_seller.c

inherit F_DEALER;

void create()
{
	set_name("菜贩子", ({ "cai seller","seller" }) );
	set("gender", "男性" );
	set("age", 22);
	set("long","菜贩子木着脸站在那里。\n");

	set("sell_all_day",1);
        set("combat_exp", 50);
        set("attitude", "friendly");
        set("vendor_goods", ([
		__DIR__"obj/baicai":50,
		__DIR__"obj/qincai":50,
		__DIR__"obj/douya":50,
        ]) );
        setup();
	carry_object(ARMOR_DIR"cloth")->wear();
}
