// book_boss.c

inherit F_DEALER;

void create()
{
        set_name("书店老板", ({ "book seller" }) );

        set("gender", "男性" );
        set("age", 45);
	set("long","他就是奉天书店的老板。\n");
        set("combat_exp", 50);

	set("sell_all_day",1);

        set("attitude", "friendly");
        set("vendor_goods", ([
                BOOK_DIR"luo_book":5,
                BOOK_DIR"sword_book":8,
		BOOK_DIR"blade_book":7,
        ]) );

        setup();
        carry_object(ARMOR_DIR"cloth")->wear();
}
