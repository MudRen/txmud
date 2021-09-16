// flower_sell.c

inherit F_DEALER;

void create()
{
	set_name("卖花女", ({ "flower seller" }) );
	set("gender", "女性" );
	set("age", 15);
	set("long","这是一位清秀的小女孩。\n");
	set("combat_exp", 50);

	set("attitude", "friendly");
	set("vendor_goods", ([
		__DIR__"obj/rose" : 15,
		__DIR__"obj/y_rose" : 15,
		__DIR__"obj/w_rose" : 15,
		__DIR__"obj/baihe" : 15,
		__DIR__"obj/ju" : 15,
	]) );

	set("sell_all_day",1);

	setup();
	carry_object(ARMOR_DIR"cloth")->wear();
}
