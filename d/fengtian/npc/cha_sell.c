// cha_sell.c

inherit F_DEALER;

void create()
{
        set_name("马大嫂", ({ "ma dasao" }) );
	set("title","茶馆老板娘");
        set("gender", "女性" );
        set("age", 35);
        set("long","这是一位满脸笑容的中年妇女。\n");
        set("combat_exp", 50);

        set("attitude", "friendly");
        set("vendor_goods", ([
		LIQUID_DIR"bowl" : -1,
        ]) );

	set("sell_all_day",1);

        setup();
	carry_object(ARMOR_DIR"cloth")->wear();
}
