// book_boss.c

inherit F_DEALER;

void create()
{
        set_name("����ϰ�", ({ "book seller" }) );

        set("gender", "����" );
        set("age", 45);
	set("long","�����Ƿ��������ϰ塣\n");
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
